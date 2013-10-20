#include <QVector>
#include <vector> // for std::vector<bool>
#include "evaluate.h"
#include "Scheme.hpp"

namespace METHOD_ADD {

	struct remove_dimension_para {
		size_t index; // the index of the indicator TODO: use QString
		bool posi; // posi indicates `positive indicator` or negetive indicator
		bool std; // standardization needed if (std == true)
		score_type pz; // then pz is the standard value
		// size_t start_year;
		// size_t end_year;

		// initparalist ctor
		remove_dimension_para(size_t _index, bool _posi, bool _std=false, score_type _pz=0.0)
			:index(_index), posi(_posi), std(_std), pz(_pz) {}
	};

	// 指标层
	struct indicator_layer_score {
		size_t index;
		std::vector<score_type> score;
		std::vector<bool> valid; // false if the value is missing(original data is missing)
		// score_type max;
		// size_t max_year;
		// score_type min;
		// size_t min_year;
		indicator_layer_score() {}
		indicator_layer_score(indicator_layer_score&& rhs) {
			index = rhs.index;
			score = std::move(rhs.score);
			valid = std::move(rhs.valid);
		}
		indicator_layer_score(const indicator_layer_score& ) = default;
		indicator_layer_score& operator=(const indicator_layer_score&) = default;
	};

	struct scheme_dimension { // schemePtr & the values with dimension removed
		QVector<indicator_layer_score> score;
		SchemePtr scheme;
	};

    struct chayixishu_score {
        score_type score;
        SchemePtr scheme;
    };

	template <typename T>
		score_type gao_avg(SchemePtr scheme, size_t index, bool posi, bool std, score_type pz) ;
     /**
      * remove dimension of a single value
      */
	template <typename T>
		indicator_layer_score do_remove_dimension(SchemePtr scheme, const remove_dimension_para& , T max, T min);
	template <typename T>
		void remove_dimension(std::vector<scheme_dimension>&, const std::vector<SchemePtr>&, const remove_dimension_para&);

} // namespace method_add

