///////////////////////////////////////////////////////////
//  AbsRecipeVisitor.h
//  Implementation of the Class AbsRecipeVisitor
//  Created on:      02-avr.-2022 14:16:24
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_B647BEC7_B98F_4cf0_854E_A7418A01944F__INCLUDED_)
#define EA_B647BEC7_B98F_4cf0_854E_A7418A01944F__INCLUDED_

class AbsRecipeVisitor
{

public:
	AbsRecipeVisitor() {};
	virtual ~AbsRecipeVisitor() = default;

	virtual void processCompositeStep(class CompositeStep& composite) =0;
	virtual void processIngredient(class Ingredient& ingredient) =0;
	virtual void processRecipe(class Recipe& recipe) = 0;
	virtual void processSingleStep(class SingleStep& step) =0;
};
#endif // !defined(EA_B647BEC7_B98F_4cf0_854E_A7418A01944F__INCLUDED_)
