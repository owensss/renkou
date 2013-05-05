#ifndef _PARARULE_hPP
#define _PARARULE_hPP
#include <set>

/*
 * @impl: a simple rule system that validate the value input
 * 		  by adding candicates into the rule, the input will be assured to match the candidate
 */
template <typename T>
class ParaRule {
	public:
		ParaRule() = default;
		~ParaRule() = default;
	public:
		bool add(const T& candidate) {
			candidates.insert(candidate);
		}
		// @return: true if input is a candidate
		bool isIn(const T& value) const {
			if (candidates.find(value) == candidates.end()) 
				return false;
			return true;
		}

		bool empty(void) const {
			return candidates.empty();
		}

		const std::set<T>& get_candicates(void) const {return candidates;}

	private:
		std::set<T> candidates;
};

#endif
