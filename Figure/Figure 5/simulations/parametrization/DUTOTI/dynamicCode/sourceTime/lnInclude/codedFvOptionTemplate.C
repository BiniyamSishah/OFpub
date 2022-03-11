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

\*---------------------------------------------------------------------------*/

#include "codedFvOptionTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "fvMatrix.H"

//{{{ begin codeInclude
#line 36 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/constant/fvOptions.momentumSource.vectorCodedSourceCoeffs"

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace fv
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = b273b7f5f419de0f1d84a8c729c68be621969d79
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void sourceTime_b273b7f5f419de0f1d84a8c729c68be621969d79(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

//makeRemovablePatchTypeField
//(
//    fvPatch,
//    sourceTimeFvOptionvectorSource
//);
defineTypeNameAndDebug(sourceTimeFvOptionvectorSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    sourceTimeFvOptionvectorSource,
    dictionary
);


const char* const sourceTimeFvOptionvectorSource::SHA1sum =
    "b273b7f5f419de0f1d84a8c729c68be621969d79";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

sourceTimeFvOptionvectorSource::
sourceTimeFvOptionvectorSource
(
    const word& name,
    const word& modelType,
    const dictionary& dict,
    const fvMesh& mesh
)
:
    cellSetOption(name, modelType, dict, mesh)
{
    if (false)
    {
        Info<<"construct sourceTime sha1: b273b7f5f419de0f1d84a8c729c68be621969d79"
            " from components\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

sourceTimeFvOptionvectorSource::
~sourceTimeFvOptionvectorSource()
{
    if (false)
    {
        Info<<"destroy sourceTime sha1: b273b7f5f419de0f1d84a8c729c68be621969d79\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void sourceTimeFvOptionvectorSource::correct
(
    GeometricField<vector, fvPatchField, volMesh>& fld
)
{
    if (false)
    {
        Info<<"sourceTimeFvOptionvectorSource::correct()\n";
    }

//{{{ begin code
    #line 40 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/constant/fvOptions.momentumSource.vectorCodedSourceCoeffs"

//}}} end code
}


void sourceTimeFvOptionvectorSource::addSup
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<<"sourceTimeFvOptionvectorSource::addSup()\n";
    }

//{{{ begin code
    #line 44 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/constant/fvOptions.momentumSource.vectorCodedSourceCoeffs"
const Time& time = mesh().time();
         const scalarField& V = mesh_.V(); //volume center
         const vectorField& C = mesh_.C(); // cell center
         vectorField& Source = eqn.source();
         
         forAll(C, i)
         {
         Source[i] = vector( 0.1638 *std::sin(1.1701 *time.value()),0,0)*V[i]; 
         }
//}}} end code
}


void sourceTimeFvOptionvectorSource::addSup
(
    const volScalarField& rho,
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<<"sourceTimeFvOptionvectorSource::addSup()\n";
    }

//{{{ begin code
    #line 44 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/constant/fvOptions.momentumSource.vectorCodedSourceCoeffs"
const Time& time = mesh().time();
         const scalarField& V = mesh_.V(); //volume center
         const vectorField& C = mesh_.C(); // cell center
         vectorField& Source = eqn.source();
         
         forAll(C, i)
         {
         Source[i] = vector( 0.1638 *std::sin(1.1701 *time.value()),0,0)*V[i]; 
         }
//}}} end code
}


void sourceTimeFvOptionvectorSource::constrain
(
    fvMatrix<vector>& eqn,
    const label fieldi
)
{
    if (false)
    {
        Info<<"sourceTimeFvOptionvectorSource::constrain()\n";
    }

//{{{ begin code
    #line 59 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/constant/fvOptions.momentumSource.vectorCodedSourceCoeffs"

//}}} end code
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

} // End namespace fv
// ************************************************************************* //

