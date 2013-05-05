#include "SchemeDef.hpp"
#include "evaluate.h"

namespace METHOD_ADD {
	struct evaluate_result {
		score_type synthesize;
		score_type rule_1[4];
		score_type rule_2[9];
		score_type indicator[15]; // 15
		SchemePtr scheme;
	};
}

METHOD_ADD::evaluate_result* method_add(const std::vector<std::vector<SchemePtr>>& scheme);
