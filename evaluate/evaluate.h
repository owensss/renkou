#ifndef EVALUATE_H
#define EVALUATE_H

typedef double score_type;

namespace evaluate {
    enum class EvaIndicators {
        total_popu = 3, // 总人口
        per_water_res = 115, // 人均水资源
        per_plough = 116, // 人均耕地
        since_the_rate_of = 22, // 自增率 via 有道，点个赞
        birth_diff_coe = 20, // 畜生差异系数
        inter_elder_ratio = 99, // 国际老年比
        inter_elder_young_ratio = 100,// 国际老少比
        inter_load_elder = 102, // 国际负老
        inter_load_young = 103, // 国际负少
        inter_work_age_b = 104, // 国际劳年b
        inter_work_teen_b = 105, // 国际劳请b
        inter_window_82 = 101, // 国际视窗82
        age_diff = 81, // 年龄差异度
        one_child_parent = 64, // 一孩父母
        special_assist = 67 // 特扶
    };
}

#endif // evaluate
