///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.h
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_D7E8686F_70D5_40f9_B442_B6D1C01C77ED__INCLUDED_)
#define EA_D7E8686F_70D5_40f9_B442_B6D1C01C77ED__INCLUDED_

#include "AbsRecipeVisitor.h"

class ComputeTimeVisitor : public AbsRecipeVisitor
{

public:
	ComputeTimeVisitor();
	virtual ~ComputeTimeVisitor() = default;

	virtual void processCompositeStep(class CompositeStep& composite);
	virtual void processIngredient(class Ingredient& ingredient);
	virtual void processRecipe(class Recipe& recipe);
	virtual void processSingleStep(class SingleStep& step);

	virtual int getPreparationTime() const { return m_preparationTime; };
	virtual int getRealizationTime() const { return m_realizationTime; };

private:
	int m_preparationTime;
	int m_realizationTime;
};
#endif // !defined(EA_D7E8686F_70D5_40f9_B442_B6D1C01C77ED__INCLUDED_)
