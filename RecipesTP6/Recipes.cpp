// Recipes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "RecipeBook.h"

#include "Recipe.h"
#include "AbsRecipeComponent.h"
#include "RecipeComponentContainer.h"
#include "ComputeTimeVisitor.h"
#include "FindIngredientVisitor.h"
#include "TimeFormater.h"

void testComputeTimeVisitor(Recipe& recipe)
{
    // Compute how much time is needed to prepare ingredients and realize the recipe
    ComputeTimeVisitor timeVisitor;
    recipe.accept(timeVisitor);

    int preparationTime = timeVisitor.getPreparationTime();
    std::cout << "Temps de preparation des ingredients: " << preparationTime << std::endl;
    TimeFormater::selectFormatStrategy("litteral");
    std::cout << "Temps en format litteral: " << TimeFormater::formatTime(preparationTime) << std::endl;
    TimeFormater::selectFormatStrategy("numeric");
    std::cout << "Temps en format numerique: " << TimeFormater::formatTime(preparationTime) << std::endl << std::endl;

    int realizationTime = timeVisitor.getRealizationTime();
    std::cout << "Temps pour realiser la recette: " << realizationTime << std::endl;
    TimeFormater::selectFormatStrategy("litteral");
    std::cout << "Temps en format litteral: " << TimeFormater::formatTime(realizationTime) << std::endl;
    TimeFormater::selectFormatStrategy("numeric");
    std::cout << "Temps en format numerique: " << TimeFormater::formatTime(realizationTime) << std::endl;
}

void testFindIngredientVisitor(Recipe& recipe, const char* ingredientName)
{
    FindIngredientVisitor findIngredient(ingredientName);
    recipe.accept(findIngredient);
    std::cout << "Verifier si la recette contient l'ingredient " << ingredientName << std::endl;
    if (findIngredient.getNumberFound() != 0)
    {
        std::cout << "Oui, la recette contient l'ingredient " << ingredientName << "! (ingredient trouve " << findIngredient.getNumberFound() << " fois)" << std::endl;
        for (auto it = findIngredient.begin(); it != findIngredient.end(); ++it)
            std::cout << "Dans cette recette, l'ingredient doit etre " << (*(*it)).getDescription() << std::endl;
    }
    else
    {
        std::cout << "Non, une pizza ne contient pas l'ingredient " << ingredientName << " !" << std::endl;
    }
}

int main()
{
    try {
        std::cout << "Creation du livre de recette LOG1410\n";
        RecipeBook log1410Recipes("Le livre de recette de LOG1410");

        std::cout << "On cherche une recette de pizza dans le livre de recette de LOG1410\n";
        Recipe* pizzaPtr = log1410Recipes.findRecipe("pizza");

        if (pizzaPtr != nullptr)
        {
            std::cout << "On a trouve une recette de pizza!" << std::endl << "Voici la recette: " << std::endl << *pizzaPtr << std::endl << std::endl;

            // Test the ComputeTimeVisitor on a pizza
            testComputeTimeVisitor(*pizzaPtr);

            // Test the FindIngredientVisitor for 2 ingredients of a pizza
            std::cout << std::endl;
            testFindIngredientVisitor(*pizzaPtr, "farine");

            std::cout << std::endl;
            testFindIngredientVisitor(*pizzaPtr, "oignons");
        }
        else
        {
            std::cout << "Pas de recette de pizza trouvee, desole!" << std::endl;
        }
    }

    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
