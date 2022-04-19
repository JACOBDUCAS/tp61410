///////////////////////////////////////////////////////////
//  FindIngredientVisitor.h
//  Implementation of the Class FindIngredientVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_1BAA5CC2_188D_4776_B29D_9A194A1EEC43__INCLUDED_)
#define EA_1BAA5CC2_188D_4776_B29D_9A194A1EEC43__INCLUDED_

#include <list>
#include <string>

#include "AbsRecipeVisitor.h"
#include "RecipeComponentContainer.h"

using FoundIngredientIterator = std::list<RecipeComponentIterator>::iterator;
using FoundIngredientIterator_const = std::list<RecipeComponentIterator>::const_iterator;

class FindIngredientVisitor : public AbsRecipeVisitor
{
public:
	FindIngredientVisitor( const char* ingredientName );
	virtual ~FindIngredientVisitor() = default;

	virtual void processCompositeStep(CompositeStep& composite);
	virtual void processIngredient(class Ingredient& ingredient);
	virtual void processRecipe(Recipe& recipe);
	virtual void processSingleStep(class SingleStep& step);

	virtual std::size_t getNumberFound() const { return m_ingredientsFound.size(); }
	virtual FoundIngredientIterator begin();
	virtual FoundIngredientIterator_const cbegin() const;
	virtual FoundIngredientIterator_const cend() const;
	virtual FoundIngredientIterator end();
	virtual void reset();

private:
	std::string m_searchedName;
	RecipeComponentIterator* m_currentIterator;
	std::list<RecipeComponentIterator> m_ingredientsFound;
};
#endif // !defined(EA_1BAA5CC2_188D_4776_B29D_9A194A1EEC43__INCLUDED_)
