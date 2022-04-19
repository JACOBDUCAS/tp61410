///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.cpp
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "ComputeTimeVisitor.h"
#include "CompositeStep.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SingleStep.h"

ComputeTimeVisitor::ComputeTimeVisitor()
	: m_preparationTime(0), m_realizationTime(0)
{
}

void ComputeTimeVisitor::processCompositeStep(CompositeStep& composite)
{
	// À compléter: itérer sur les enfants du composite et appliquer le visiteur à chaque enfant
}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// À compléter: ajouter la durée de préparation de l'ingrédient au temps total de préparation
}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// À compléter: itérer sur les ingrédients et appliquer le visiteur à chaque enfant
	//              itérer sur chaque étape et appliquer le visiteur à chaque étape
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// À compléter: ajouter la durée de réalisation de l'étape au temps total de réalisation
}
