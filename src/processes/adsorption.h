//============================================================================
//    Apothesis: A kinetic Monte Calro (KMC) code for deposition processes.
//    Copyright (C) 2019  Nikolaos (Nikos) Cheimarios
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//============================================================================
#ifndef ADSORPTIONSIMPLECUBIC_H
#define ADSORPTIONSIMPLECUBIC_H

#include "process.h"

namespace MicroProcesses
{

class Adsorption: public Process
{
public:
    Adsorption();
    ~Adsorption() override;

    double getProbability() override;
    bool rules( Site* ) override;
    void perform( Site* ) override;

    inline void setTargetSite( Site* site ){ m_Site = site;}
    inline Site* getTargetSite(){ return m_Site; }

    void init( vector<string> params ) override;

    void simple();

    inline void setSpecies(string s){ m_sSpecies = s;}
    inline string getSpecies(){ return m_sSpecies;}

private:

    string m_sSpecies;

    bool mf_isInLowerStep( Site* s );
    bool mf_isInHigherStep( Site* s );

    ///The site that the process will be performed
    Site* m_Site;

    /// A member function to calculate the neighbors of a given site
    int mf_calculateNeighbors(Site*);

    /// For simple adsorption:
    ///The sticking coefficient [-]
    double m_dStick;

    ///The molar fraction [-]
    double m_dF;

    ///The concentration of sites [sites/m^2]
    double m_dCtot;

    ///The molecular weight of the species [kg/mol]
    double m_dMW;

    REGISTER_PROCESS( Adsorption )
};
}

#endif // AdsorptionSimpleCubic_H
