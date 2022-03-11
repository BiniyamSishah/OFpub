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

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
//{{{ begin codeInclude
#line 36 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/0/omega.boundaryField.bottomWall"
#include "fvCFD.H"
                #include "cmath"
                #include "iostream"
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
    // dynamicCode:
    // SHA1 = 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void ModifiedForRoughness_3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae(bool load)
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

makeRemovablePatchTypeField
(
    fvPatchScalarField,
    ModifiedForRoughnessFixedValueFvPatchScalarField
);


const char* const ModifiedForRoughnessFixedValueFvPatchScalarField::SHA1sum =
    "3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

ModifiedForRoughnessFixedValueFvPatchScalarField::
ModifiedForRoughnessFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(p, iF)
{
    if (false)
    {
        Info<<"construct ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae"
            " from patch/DimensionedField\n";
    }
}


ModifiedForRoughnessFixedValueFvPatchScalarField::
ModifiedForRoughnessFixedValueFvPatchScalarField
(
    const ModifiedForRoughnessFixedValueFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchField<scalar>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae"
            " from patch/DimensionedField/mapper\n";
    }
}


ModifiedForRoughnessFixedValueFvPatchScalarField::
ModifiedForRoughnessFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<scalar>(p, iF, dict)
{
    if (false)
    {
        Info<<"construct ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae"
            " from patch/dictionary\n";
    }
}


ModifiedForRoughnessFixedValueFvPatchScalarField::
ModifiedForRoughnessFixedValueFvPatchScalarField
(
    const ModifiedForRoughnessFixedValueFvPatchScalarField& ptf
)
:
    fixedValueFvPatchField<scalar>(ptf)
{
    if (false)
    {
        Info<<"construct ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae"
            " as copy\n";
    }
}


ModifiedForRoughnessFixedValueFvPatchScalarField::
ModifiedForRoughnessFixedValueFvPatchScalarField
(
    const ModifiedForRoughnessFixedValueFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(ptf, iF)
{
    if (false)
    {
        Info<<"construct ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

ModifiedForRoughnessFixedValueFvPatchScalarField::
~ModifiedForRoughnessFixedValueFvPatchScalarField()
{
    if (false)
    {
        Info<<"destroy ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void ModifiedForRoughnessFixedValueFvPatchScalarField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs ModifiedForRoughness sha1: 3b78c21aff7a5650f9bf5d26d5a9ea825f75c6ae\n";
    }

//{{{ begin code
    #line 56 "/d1/home/bini/General/paperWithJoel/AdanedOF/dakota/DUTOTI/workdir.8/0/omega.boundaryField.bottomWall"
const fvPatch& boundaryPatch = patch();                // give access to boundary mesh patch mesh
            const vectorField& Cf = boundaryPatch.Cf();            // give access to center of mesh 
      //    const vectorField& normal = patch().nf();              // give access to the face normal 
           
            scalarField& field = *this; 
            field = patchInternalField();                          // assign value from the internal field to the patch     

            scalar Zr = 2.250;                                      // roughness to be incorporated 
            scalar nuu = 0.00000114;                               // kinematic viscosity
            scalar t = this ->db().time().value();                 // acess time information
       //      Info << "Binininini" << t << endl; 
       //    scalar rho = 1000;                                     // Density


  
           if (t>0.02)        // perform the modification from the second time step on wards
            {
                const fvPatchVectorField& Tau = patch().lookupPatchField<volVectorField, vector>("wallShearStress");      // access the wall shear stress vector
                Info << "WALL SHEAR STRESSSSSSSSSSSSSSS" << Tau << endl;   
               scalarField Taux = Tau.component(0);                                                                      // access x-component of the wall shear stress 
               scalarField Tauxx = pow (Taux*Taux,0.5);
                 Info << "HORIZONTAL WALL SHEAR STRESSSSSSSSSSS" << Taux << endl; 
                Info << "HORIZONTAL WALL SHEAR STRESSSSSSSSSSS" << Tauxx << endl;   
               scalarField Ushear =  pow(Tauxx,0.5);                                                                // compute the shear velocity => sqrt(Tau/rho)
              Info << "HORIZONTAL WALL SHEAR VELOCITY " << Ushear << endl;  
               scalarField Ksplus =  Ushear*Zr/nuu;                                                                     // compute the non-dimensional roughness => (Ushear*Zr/nu)
             Info << "NON_DIMENSIONAL ROUGHNESS CONSTANT" << Ksplus << endl;  
               scalarField Treshold =(Ushear/Ushear)*25;                                                                 // set the threshold in for all faces => kplus =25
             Info<< "JOEEEEEEEEEEE HELPPPPPPP" <<Treshold << endl;
             
     
         forAll(Cf,faceI)  
              {
               if (Ksplus < Treshold )      
                 {                 
                 field[faceI] = scalar ((Tauxx[faceI]/nuu)*pow(50/Ksplus[faceI],2));           
                 }
               else 
                 {
                 field[faceI] = scalar ((Tauxx[faceI]/nuu)*(100/Ksplus[faceI]));             
                 }
              }
            }
          else
           {
           }    
 Info << "OMEGAOMEGAOMEGA"<< field << endl;
//}}} end code

    this->fixedValueFvPatchField<scalar>::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

