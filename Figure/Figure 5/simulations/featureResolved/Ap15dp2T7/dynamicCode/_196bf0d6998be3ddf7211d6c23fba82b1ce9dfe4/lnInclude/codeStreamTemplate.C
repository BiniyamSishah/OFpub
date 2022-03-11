/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with codeStream.

\*---------------------------------------------------------------------------*/

#include "dictionary.H"
#include "Ostream.H"
#include "Pstream.H"
#include "unitConversion.H"

//{{{ begin codeInclude
#line 95 "/d1/home/bini/General/paperWithJoel/Newcases/Finalcases/2DF/Ap15dp2T7/system/blockMeshDict.#codeStream"
#include "pointField.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    void codeStream_196bf0d6998be3ddf7211d6c23fba82b1ce9dfe4
    (
        Ostream& os,
        const dictionary& dict
    )
    {
//{{{ begin code
        #line 100 "/d1/home/bini/General/paperWithJoel/Newcases/Finalcases/2DF/Ap15dp2T7/system/blockMeshDict.#codeStream"
label nbPoints = 1.389970e+03;


     for (label i = 0; i < nbPoints; i++)
     {
       scalar xi = i - 0.5*2.084950e+02*std::sin(i*4.520390e+03*0.000001);
       scalar yi = 0.5*2.084950e+02*std::cos(i*4.520390e+03*0.000001);
       os  << point(xi, yi, 0) << endl;
      // Info  << point(xi, yi, 0) << endl;
     }
//}}} end code
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

