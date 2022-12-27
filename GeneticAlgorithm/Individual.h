//
// Created by ricar on 26/12/2022.
//

#ifndef GENETICALGORITHM_INDIVIDUAL_H
#define GENETICALGORITHM_INDIVIDUAL_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Random.h"
#include "Chromosome.h"
#include "MyUtil.h"
#if defined(__linux__)
#define barra "/" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#else
#define barra "\\"
#endif

using namespace std;

class Individual {
public:
    Individual(int i, int generationMax, double mutationProb, double mutationB, int pS, int cs,
               double *min, double* max);
    virtual ~Individual();

    void  mutate();
    void    setGeneration(int);
    int     getId();
    void    iniChromossome(double);
    double  uniformMutation(int i);
    double   fitness;
    void changeBounds(int iChron, double min, double max);
    int fitnessRank;
    int populationSize;
    string getStrFit();
private:
    double   nonUniformMutation(int i, double gene);
    double   delta(double y);
    default_random_engine individualRandomGenerator;

    Chromosome *chromosome;
    int chromossomeSize;
    int     id;
    double   b;
    int     maxGeneration;
    int     generation;

    double mutationProb;


};

#endif //GENETICALGORITHM_INDIVIDUAL_H
