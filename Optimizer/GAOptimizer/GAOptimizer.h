//  MABE is a product of The Hintze Lab @ MSU
//     for general research information:
//         hintzelab.msu.edu
//     for MABE documentation:
//         github.com/ahnt/MABE/wiki
//
//  Copyright (c) 2015 Michigan State University. All rights reserved.
//     to view the full license, visit:
//         github.com/ahnt/MABE/wiki/License

#ifndef __BasicMarkovBrainTemplate__GA_Optimizer__
#define __BasicMarkovBrainTemplate__GA_Optimizer__

#include "../AbstractOptimizer.h"

using namespace std;



class GAOptimizer : public AbstractOptimizer {
 public:
	static shared_ptr<ParameterLink<string>> optimizeFormulaPL;
	static shared_ptr<ParameterLink<int>> elitismPL;

	shared_ptr<ParameterLink<int>> elitismLPL;

	GAOptimizer(shared_ptr<ParametersTable> _PT = nullptr) : AbstractOptimizer(_PT) {
		optimizeFormula = (PT == nullptr) ? stringToMTree(optimizeFormulaPL->lookup()) : stringToMTree(PT->lookupString("OPTIMIZER_GA-optimizeValue"));
		elitismLPL = (PT == nullptr) ? elitismPL : Parameters::getIntLink("OPTIMIZER_GA-elitism", PT);
	}
	virtual void makeNextGeneration(vector<shared_ptr<Organism>> &population) override;

	virtual string maxValueName() override {
		return (PT == nullptr) ? optimizeFormulaPL->lookup() : PT->lookupString("OPTIMIZER_GA-optimizeValue");
	}

};

#endif /* defined(__BasicMarkovBrainTemplate__GA_Optimizer__) */
