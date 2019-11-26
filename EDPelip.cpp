#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
double evolve(double *psi_new, double *psi_old, double delta_x, int n_x, double m, double p);
void save(double **almacen, double *temporal, int n_x, int t);

int main(int argc, char **argv)
{   
	double *psi = NULL;
	double *psi_past = NULL;
	int n_x;
	double delta_x;
	
	psi  = new double [n_x];
	psi_past  = new double [n_x];
	
	for(int i = 1; i < 11; i++)
	{	
		n_x=atoi(argv[i+1]);
		delta_x = 2.0/n_x;	

		init(psi, n_x);
		
		double maxCamb = 1.0;
		double maxPsi = 0.0;
		int nItera = 0;
		while(maxCamb > 0.000001)
		{
			copy(psi_past, psi, n_x);
			maxCamb, maxPsi = evolve(psi, psi_past, delta_x, n_x, maxCamb, maxPsi);
			nItera++;
		}
		double epsilon = abs(maxCamb/maxPsi);
		
		std::cout << n_x << " " << nItera << " " << epsilon << " " << psi[n_x/2] << "\n";
	}
    return 0;
}

double evolve(double *psi_new, double *psi_old, double delta_x, int n_x, double m, double p)
{
    int i;
	double mx = m;
	double px = p;
    for(i=1;i<n_x-1;i++)
    {
        psi_new[i] = 0.5*psi_old[i+1] + 0.5*psi_old[i-1] + delta_x*delta_x/2;
        if(psi_new[i]-psi_old[i] > mx)
        {
            mx = (psi_new[i]-psi_old[i]);
			p = psi_old[i];
        }
    }
	return mx, px;
}

void copy(double *recibe, double *entrega, int n_x)
{
    int i;
    for (i=0;i<n_x;i++)
    {
        recibe[i] = entrega[i];
    }
}

void save(double **almacen, double *temporal, int n_x, int t)
{
    int i;
    for (i=0;i<n_x;i++)
    {
        almacen[t][i] = temporal[i];
    }
}

void init(double *psi, int n_x)
{
    int i;
    for(i=0;i<n_x;i++)
    {
        psi[i] = 0.0;
    }
}


void print(double *psi, int n_x)
{
    int i;
    for(i=0;i<n_x;i++)
    {
        std::cout << psi[i] << " ";
    }
    std::cout << "\n";
}