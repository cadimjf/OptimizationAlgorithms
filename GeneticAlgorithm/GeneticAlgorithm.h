//
// Created by ricar on 26/12/2022.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_H
#define GENETICALGORITHM_GENETICALGORITHM_H
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Random.h"
#include "Individual.h"
#include "MyUtil.h"
using namespace std;
class GeneticAlgorithm {
public:
    GeneticAlgorithm(int cs, int nPopulation, int gm);
    ~GeneticAlgorithm();
    void setElite(int);
    void setCrossOverProb(double);
    void setAlpha(double);
    void setMutationB(double);
    void setMutationProb(double);
    void evolution();
    void setMinAllele(int i, double val);
    void setMaxAllele(int i, double val);
private:
    void iniAlleleBoundaries();
    void iniPopulation();
    unsigned    agSeed;
    int         elite; //number of individuals kept in the next generation
    int         populationSize;
    int         generationCurrent;
    int         generationMax;

    double      sumFit;
    double      avgFitness;

    int         iBest;
    int         iWorst;
    default_random_engine agRandomGenerator;
    double      crossOverProb;
    double      alpha;
    double      mutationB;
    double      mutationProb;
    std::vector<Individual*> population;
    std::vector<double> maxAllele;
    std::vector<double> minAllele;
    int chromossomeSize;
    void generation();
    int rankSelection(int forbidenGuy);
    double sumRank;
    void crossOver(int p1, int p2, int iInd);
    double crossOverBLXAlpha(double gene1, double gene2);
    int partitionQckSort(int p, int r);
    void quickSort( int p, int r);

};


#endif //GENETICALGORITHM_GENETICALGORITHM_H
