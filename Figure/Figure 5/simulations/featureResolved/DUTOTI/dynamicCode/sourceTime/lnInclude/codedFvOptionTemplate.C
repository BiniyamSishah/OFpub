/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2019 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
                            | Copyright (C) YEAR AUTHOR,AFFILIATION
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

// dynamicCode:
// SHA1 = c170b604fc53b431c8527231ded135105c0e068d
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void sourceTime_c170b604fc53b431c8527231ded135105c0e068d(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(sourceTimeFvOptionvectorSource, 0);
addRemovableToRunTimeSelectionTable
(
    option,
    sourceTimeFvOptionvectorSource,
    dictionary
);


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
        printMessage("Construct sourceTime from components");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

sourceTimeFvOptionvectorSource::
~sourceTimeFvOptionvectorSource()
{
    if (false)
    {
        printMessage("Destroy sourceTime");
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
    const Time& time = mesh().time();
         const scalarField& V = mesh_.V(); //volume center
         const vectorField& C = mesh_.C(); // cell center
         vectorField& Source = eqn.source();
         
         forAll(C, i)
         {
         Source[i] = vector(0.1638 *std::sin(1.1701 *time.value()),0,0)*V[i]; 
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
    const Time& time = mesh().time();
         const scalarField& V = mesh_.V(); //volume center
         const vectorField& C = mesh_.C(); // cell center
         vectorField& Source = eqn.source();
         
         forAll(C, i)
         {
         Source[i] = vector(0.1638 *std::sin(1.1701 *time.value()),0,0)*V[i]; 
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
    
//}}} end code
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv
} // End namespace Foam

// ************************************************************************* //

