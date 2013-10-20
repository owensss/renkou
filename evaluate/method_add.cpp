#include "method_add_impl.h"
#include "method_add.h"
#include <cmath>
#include <algorithm> // max_element, min_element
#include <vector>
#include <QString>
#include "Scheme.hpp"
#include "SchemeIndicator.hpp"
#include "SchemeInstance.hpp"
#include "Schemebuffer.hpp"
#include "schememetadata.h"
#include <vector> // I'm not sure weather std::vector has rvalue-ref-ctor or not(I thought it didn't). So I decide to use std::vector.
#include <cassert> // assert some value size are greater than zero
#include <QDebug>

namespace METHOD_ADD { // decl
	/* 
	 * @params: the scheme
	 * 			the remove_dimension_para( contains =>
	 * 				index of the para,
	 * 				positive ind or negtive (use different formular)
	 * 				need standardization ? if yes, the std_value
	 * 			)
	 * 			max value (max value of all same-ind-values in all schemes)
	 * 			min value (min value of all same-ind-values in all schemes)
	 * @return: the indicator_layer_score( 
	 * 				index of the indicator
	 * 				the scores(from the beginning year to end year)
     *				validator(false if value not exist)
	 * 			)
	 */
	template <typename T>
        indicator_layer_score do_remove_dimension(
                SchemePtr scheme,
                const remove_dimension_para& para,
                T max, T min
        ) {

			indicator_layer_score p; // the result
			SchemeIndicator<T> ind = scheme->getIndicator<T>(para.index); // the indicator
			for (size_t i = ind.startYear(); i <= ind.endYear(); ++i) {
                // qDebug() << "[do_remove_dimension]getting" << i;
                score_type f = ind.get(i);

				// assign p
				if (para.std) { // has a standard value
					// p = 100/exp(abs(f-pz))
					p.score.push_back( 100.0/exp(abs(f-para.pz)) );
					p.valid.push_back(true); // by now, it is always true
				} else {
					if (para.posi ) { // positive indicator(正向指标)
						// p = (f-min(f))/(max(f)-min(f))*99+1
                        p.score.push_back( (f-min)/(max-min)*99.0+1 );
						p.valid.push_back(true);
					} else { // neg indicator
						// p = 100-(f-min(f))/(max(f)-min(f))*99
                        p.score.push_back( 100.0-(f-min)/(max-min)*99 );
						p.valid.push_back(true);
					}
				}
			} // end of for each value

			return p;
		} // END OF do_remove_dimension
	// 一次解决主要是为了效率，理论上，等到使用的时候，我会把 buffer 调大到 150, 这样一个 Buffer 占 15mb
	// 而一个地区的方案大约只有 120 吧, 不存在不停 load 的问题
	// 无量纲化
    /* @params:
     *      scheme lists. List of Schemes to be processed
     *      the indicator list to be processed
	 * @return: the list of scheme pointer with all the processed indicators
	 * @impl: the default remove dimension function, with original data input
	 */
	template <typename T>
        void remove_dimension(
                std::vector<scheme_dimension>& score,
                const std::vector<SchemePtr>& schemes,
                const remove_dimension_para& para
        ) {
            // for (auto& i : scheme)
                // qDebug() << i->getMetadata()->name();

            std::vector<T> maxes; // maxes for each indicator
			std::vector<T> mins; // mins for each indicator
            // qDebug() << "remove dimension";
			// load maxes for each scheme of indicator
            for (auto& s : schemes) { // foreach scheme
                // qDebug() << "gao max min ";
                SchemeIndicator<T> indicator = s->getIndicator<T>(para.index);
				maxes.push_back(indicator.max());
				mins.push_back(indicator.min());
               // if (ind.index == 64 || ind.index == 67) {
               //     qDebug() << indicator.max();
               //     qDebug() << indicator.min();
               // }
			}

			// min(f)、 max(f) 是所有地区、所有方案、所有年份的最大值、最小值
			// 计算最值，将指标无量纲化
			T total_max = *std::max_element(maxes.begin(), maxes.end());
			T total_min = *std::min_element(mins.begin(), mins.end());
            qDebug() << "total max for" << para.index << total_max;
            qDebug() << "total min for" << para.index << total_min;
			// 无量纲化
            size_t ssize = schemes.size();
            // score.resize(ssize);
			for (size_t j = 0; j < ssize; ++j) {
                // qDebug() << scheme[j]->getMetadata()->name() << scheme[j]->getMetadata()->colCount();
                score[j].score.push_back(do_remove_dimension(schemes[j], para, total_max, total_min));
				// note: initialize the scheme once and left it alone
				// shall not be assign here
                score[j].scheme = schemes[j]; // TODO: could be dangerous!
			}
		}

	/*
	 * @special class for preparing 差异系数
	 * 差异系数 = 标准差 / 平均值
	 */
	template <typename T>
        void prepare_chayixishu(
                std::vector<chayixishu_score>& score,
                const std::vector<SchemePtr>& schemes,
                const remove_dimension_para& para
        ) {
            std::vector<score_type> recalc_score;
            for (auto& s : schemes) { // foreach scheme
				// 标准差
				auto sd = std::sqrt(s->getIndicator<T>(7).variance());
				// 平均值
				auto avg = s->getIndicator<T>(7).mean();
                // qDebug() << "sd" << sd << "mean" << avg;
                recalc_score.push_back(sd/avg);
			}
			// find max & min
            double total_max = *std::max_element(recalc_score.begin(), recalc_score.end());
            double total_min = *std::min_element(recalc_score.begin(), recalc_score.end());
            qDebug() << "total max for" << para.index << total_max;
            qDebug() << "total min for" << para.index << total_min;
            size_t ssize = schemes.size();
            // score.resize(ssize);
			for (size_t j = 0; j < ssize; ++j) {
                auto f = recalc_score[j];
                chayixishu_score p;
                // known neg indicator. directly placed here.
                p.score = 100-(f-total_min)/(total_max-total_min)*99;
                p.scheme = schemes[j];
                // qDebug() << f << p.score;
                score[j] = p;
			}
		}


	namespace detail {

		// the terminator
		template <size_t exp, typename T>
			score_type geo_mean(score_type total) {
				return std::pow(total, 1.0/exp);
			}

		// looper
		template <size_t exp, typename T, typename... Args> 
			score_type geo_mean(score_type total, T value, Args... para) {
				return geo_mean<exp+1, T>(total*value, para...);
			}

	} // end of namespace __geo_mean__

	// interface. calc the geometry mean of values
	template <typename T, typename... Args>
		score_type geo_mean(T value, Args... para) {
			return detail::geo_mean<(size_t)(0), T>(1.0, value, para...);
		}
    template <typename T>
        score_type geo_mean(const std::vector<T>& value) {
            if (value.size() == 0) return 0;
            long double result = 1.0;
            for (auto i : value)
                result *= value[i];
            return pow(result, 1.0/value.size());
        }

	// gao first indicator layer
	// return the 0.6*first_half + 0.4*second_half
	std::vector<score_type> gao_add(const scheme_dimension& scheme) {
		std::vector<score_type> result;
        // for each indicator
        for (auto& s : scheme.score) {
            size_t half = s.score.size()/2;
            size_t size = s.score.size();
            score_type first_half = 0;
            score_type second_half = 0;
            // first half
            for (size_t i = 0; i < half; ++i) {
                first_half += s.score[i];
            }
            first_half /= half;

            // second half
            for (size_t i = half; i < size; ++i) {
                second_half += s.score[i];
            }
            second_half /= half;

            result.push_back(first_half*.6+second_half*.4);
        }
        // qDebug() << scheme.scheme->getName() << result.size();
		return result;
	}

    std::vector<score_type> gao_multi(const scheme_dimension& scheme) {
        std::vector<score_type> result;
        // for each indicator
        for (auto& s : scheme.score) {
            result.push_back(geo_mean(s.score));
        }
        return result;
    }
} // namespace method_add

using namespace METHOD_ADD;

//------------------- main function start here ---------------------------
/**
 * @brief method_add
 *      this is the function to calc add method
 * @param schemes
 * @return
 */
evaluate_result* method_add(const std::vector<std::vector<SchemePtr>>& schemes) {
	// first : renkougaiyao & fufuzinv
	// second: each schemes
	// a scheme shall be score[0][i] + score[1][i];
    /*
    struct scheme_dimension { // schemePtr & the values with dimension removed
        QVector<indicator_layer_score> score;
        SchemePtr scheme;
    };
     */
    // scheme_dimension: scheme & all it's dimension_removed indicator values
    std::vector<scheme_dimension> scores[2];
    std::vector<chayixishu_score> chayixishu_scores;
    scores[0].resize(schemes[0].size());
    scores[1].resize(schemes[1].size());
    chayixishu_scores.resize(schemes[0].size());
	// renkougaiyao
    remove_dimension<schDouble>(scores[0], schemes[0], {3, false});
    remove_dimension<schDouble>(scores[0], schemes[0], {115, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {116, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {22, true});
	// gao 7
    prepare_chayixishu<schDouble>(chayixishu_scores, schemes[0], {7, false});
    remove_dimension<schDouble>(scores[0], schemes[0], {99, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {100, false});
    remove_dimension<schDouble>(scores[0], schemes[0], {102, false});
    remove_dimension<schDouble>(scores[0], schemes[0], {103, false});
    remove_dimension<schDouble>(scores[0], schemes[0], {104, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {105, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {101, true});
    remove_dimension<schDouble>(scores[0], schemes[0], {81, false});
    remove_dimension<schInt>(scores[1], schemes[1], {64, false});
    remove_dimension<schInt>(scores[1], schemes[1], {67, false});

	evaluate_result* result=nullptr; 
	// scheme size
    result = new evaluate_result[schemes[0].size()];
    size_t ssize = scores[0].size(); // score[0] & score[1] shall have the same size
	// foreach scheme =>indicator layer (准则层)
    // TODO: magic number! alot of Magic Numbers!
	for (size_t i = 0 ; i < ssize; ++i) {
		// gao renkougaiyao
        auto tmp_res = gao_add(scores[0][i]);
        // before chayixishu
        for (size_t j = 0; j < 4; ++j)
			result[i].indicator[j] = tmp_res[j];
        result[i].indicator[4] = chayixishu_scores[i].score;
        // tmp_res.size()+1 : one for chayixishu score
        for (size_t j = 5; j < tmp_res.size()+1; ++j)
            result[i].indicator[j] = tmp_res[j-1];
		// gao fufuzinv
        auto tmp_res_1 = gao_add(scores[1][i]);
        // TODO: magic number!
        for (size_t j = 0; j < tmp_res_1.size(); ++j)
            result[i].indicator[j+13] = tmp_res_1[j];

        result[i].scheme = scores[0][i].scheme;
	}

	// foreach scheme => rule_2 (指标层2)
	for (size_t i = 0; i < ssize; ++i) {
		auto& s = result[i];
		// 规模评价 -> 总人口
		s.rule_2[0] = s.indicator[0];
		// 人均资源评价 -> 人均水资源, 人均耕地
		s.rule_2[1] = geo_mean(s.indicator[1], s.indicator[2]);
		//  增长率 -> 自增率+出生差异系数
		s.rule_2[2] = geo_mean(s.indicator[3], s.indicator[4]);
		// 国际老龄评价 -> 国际老年比, 国际少年比
		s.rule_2[3] = geo_mean(s.indicator[5], s.indicator[6]);
		// 国际负担评价 ->国际负老，国际负少
		s.rule_2[4] = geo_mean(s.indicator[7], s.indicator[8]);
		// 国际劳力评价 -> 国际劳年B, 国际青劳B
		s.rule_2[5] = geo_mean(s.indicator[9], s.indicator[10]);
		// 国际视窗评价 -> 国际视窗82
		s.rule_2[6] = s.indicator[11];
		// 年龄均衡评价 -> 年龄差异度
		s.rule_2[7] = s.indicator[12];
		// 家庭风险评价 -> 一孩父母, 特扶
		s.rule_2[8] = geo_mean(s.indicator[13], s.indicator[14]);
	}


	// foreach scheme(指标层1)
	for (size_t i = 0; i < ssize; ++i) {
		auto& s = result[i];
		// 资源环境评价 -> 规模评价, 人均资源评价
		s.rule_1[0] = geo_mean(s.rule_2[0], s.rule_2[1]);
		// 增长速率评价 -> 增长评价
		s.rule_1[1] = s.rule_2[2];
		// 宏观结构评价 -> 国际老龄评价，国际负担评价，国际劳力评价，国际视窗评价，年龄均衡评价
		s.rule_1[2] = geo_mean(s.rule_2[3], s.rule_2[4], s.rule_2[5], s.rule_2[6], s.rule_2[7]);
		// 微观评价 -> 家庭风险评价
		s.rule_1[3] = s.rule_2[8];
	}
	
	// foreach scheme(综合评价)
	for (size_t i = 0; i < ssize; ++i) {
		auto& s = result[i];
		s.synthesize = geo_mean(s.rule_1[0], s.rule_1[1], s.rule_1[2], s.rule_1[3]);
	}

	return result;
}

/** @params: the second vector is the number of schemes,
  * 		the first stores renkougaiyao & fufuzinv
  */
evaluate_result* method_multi(const std::vector<std::vector<SchemePtr>>& schemes) {
    /** first : renkougaiyao & fufuzinv
      * second: each schemes
      * a scheme shall be score[0][i] + score[1][i];
      */
    /*
    struct scheme_dimension { // schemePtr & the values with dimension removed
        QVector<indicator_layer_score> score;
        SchemePtr scheme;
    };
     */
    // scheme_dimension: scheme & all it's dimension_removed indicator values
    std::vector<scheme_dimension> scores[2];
    std::vector<chayixishu_score> chayixishu_scores;
    scores[0].resize(schemes[0].size());
    scores[1].resize(schemes[1].size());
    chayixishu_scores.resize(schemes[0].size());
    // renkougaiyao
    /**
      * 无量纲化:
      *
      */
    remove_dimension<schDouble>(scores[0], schemes[0], {3, false}); // 总人口
    remove_dimension<schDouble>(scores[0], schemes[0], {115, true}); // 人均水资源
    remove_dimension<schDouble>(scores[0], schemes[0], {116, true}); // 人均耕地
    remove_dimension<schDouble>(scores[0], schemes[0], {22, true}); // 自增率，取绝对值
    // gao 7
    prepare_chayixishu<schDouble>(chayixishu_scores, schemes[0], {7, false}); // 出生差异系数
    remove_dimension<schDouble>(scores[0], schemes[0], {99, true}); // 国际老年比
    remove_dimension<schDouble>(scores[0], schemes[0], {100, false}); // 国际老少比
    remove_dimension<schDouble>(scores[0], schemes[0], {102, false}); // 国际负老
    remove_dimension<schDouble>(scores[0], schemes[0], {103, false}); // 国际负少
    remove_dimension<schDouble>(scores[0], schemes[0], {104, true}); // 国际劳年 B
    remove_dimension<schDouble>(scores[0], schemes[0], {105, true}); // 国际青劳 A
    remove_dimension<schDouble>(scores[0], schemes[0], {101, true}); // 国际视窗82
    remove_dimension<schDouble>(scores[0], schemes[0], {81, false}); // 年龄差异度
    remove_dimension<schInt>(scores[1], schemes[1], {64, false}); // 一孩父母
    remove_dimension<schInt>(scores[1], schemes[1], {67, false}); // 特扶

    evaluate_result* result=nullptr;
    // scheme size
    result = new evaluate_result[schemes[0].size()];
    size_t ssize = scores[0].size(); // score[0] & score[1] shall have the same size
    // foreach scheme =>indicator layer (准则层)
    // TODO: magic number! alot of Magic Numbers!
    for (size_t i = 0 ; i < ssize; ++i) {
        // gao renkougaiyao
        auto tmp_res = gao_multi(scores[0][i]);
        // before chayixishu
        for (size_t j = 0; j < 4; ++j)
            result[i].indicator[j] = tmp_res[j];
        result[i].indicator[4] = chayixishu_scores[i].score;
        // tmp_res.size()+1 : one for chayixishu score
        for (size_t j = 5; j < tmp_res.size()+1; ++j)
            result[i].indicator[j] = tmp_res[j-1];
        // gao fufuzinv
        auto tmp_res_1 = gao_multi(scores[1][i]);
        // TODO: magic number!
        for (size_t j = 0; j < tmp_res_1.size(); ++j)
            result[i].indicator[j+13] = tmp_res_1[j];

        result[i].scheme = scores[0][i].scheme;
    }

    // foreach scheme => rule_2 (指标层2)
    for (size_t i = 0; i < ssize; ++i) {
        auto& s = result[i];
        // 规模评价 -> 总人口
        s.rule_2[0] = s.indicator[0];
        // 人均资源评价 -> 人均水资源, 人均耕地
        s.rule_2[1] = geo_mean(s.indicator[1], s.indicator[2]);
        //  增长率 -> 自增率+出生差异系数
        s.rule_2[2] = geo_mean(s.indicator[3], s.indicator[4]);
        // 国际老龄评价 -> 国际老年比, 国际少年比
        s.rule_2[3] = geo_mean(s.indicator[5], s.indicator[6]);
        // 国际负担评价 ->国际负老，国际负少
        s.rule_2[4] = geo_mean(s.indicator[7], s.indicator[8]);
        // 国际劳力评价 -> 国际劳年B, 国际青劳B
        s.rule_2[5] = geo_mean(s.indicator[9], s.indicator[10]);
        // 国际视窗评价 -> 国际视窗82
        s.rule_2[6] = s.indicator[11];
        // 年龄均衡评价 -> 年龄差异度
        s.rule_2[7] = s.indicator[12];
        // 家庭风险评价 -> 一孩父母, 特扶
        s.rule_2[8] = geo_mean(s.indicator[13], s.indicator[14]);
    }


    // foreach scheme(指标层1)
    for (size_t i = 0; i < ssize; ++i) {
        auto& s = result[i];
        // 资源环境评价 -> 规模评价, 人均资源评价
        s.rule_1[0] = geo_mean(s.rule_2[0], s.rule_2[1]);
        // 增长速率评价 -> 增长评价
        s.rule_1[1] = s.rule_2[2];
        // 宏观结构评价 -> 国际老龄评价，国际负担评价，国际劳力评价，国际视窗评价，年龄均衡评价
        s.rule_1[2] = geo_mean(s.rule_2[3], s.rule_2[4], s.rule_2[5], s.rule_2[6], s.rule_2[7]);
        // 微观评价 -> 家庭风险评价
        s.rule_1[3] = s.rule_2[8];
    }

    // foreach scheme(综合评价)
    for (size_t i = 0; i < ssize; ++i) {
        auto& s = result[i];
        s.synthesize = geo_mean(s.rule_1[0], s.rule_1[1], s.rule_1[2], s.rule_1[3]);
    }

    return result;
}

