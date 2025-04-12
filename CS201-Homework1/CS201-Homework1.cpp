#include <iostream>
#include <iomanip>
using namespace std;



double getPizzaPrice(string size) {
    if (size == "Small") { return 10.00; }
    if (size == "Medium") { return 15.00; }
    if (size == "Large") { return 20.00; }
    return 0;
}




double getToppingPrice(string topping) {
    if (topping == "Cheese") { return 1.50; }
    if (topping == "Pepperoni") { return 2.50; }
    if (topping == "Mushrooms") { return 2.00; }
    if (topping == "Olives") { return 1.00; }
    if (topping == "Bacon") { return 3.00; }
    if (topping == "Peppers") { return 1.50; }
    return 0;
}


double getDrinkPrice(string drink) {
    if (drink == "Water") { return 1.00; }
    if (drink == "Soda") { return 2.00; }
    if (drink == "Juice") { return 3.00; }
    return 0;
}

double getDessertPrice(string dessert) {
    if (dessert == "Brownie") { return 4.00; }
    if (dessert == "Cookie") { return 3.50; }
    if (dessert == "Cheesecake") { return 5.00; }
    return 0;
}


void calculateTotal(double& totalPrice, double& pizzaPrice, string
    size, string topping, string topping2, string topping3, int
    toppingCount, string drink, string dessert) {
    pizzaPrice = getPizzaPrice(size);
    if (toppingCount == 1) {
        pizzaPrice += getToppingPrice(topping);
        totalPrice = pizzaPrice + getDrinkPrice(drink) + getDessertPrice(dessert);

    }
    if (toppingCount == 2) {
        pizzaPrice += getToppingPrice(topping) + getToppingPrice(topping2);
        totalPrice = pizzaPrice + getDrinkPrice(drink) + getDessertPrice(dessert);

    }
    if (toppingCount == 3) {
        pizzaPrice += getToppingPrice(topping) + getToppingPrice(topping2) + getToppingPrice(topping3);
        totalPrice = pizzaPrice + getDrinkPrice(drink) + getDessertPrice(dessert);
    }

}


double applyDiscount(double totalPrice, double pizzaPrice, int toppingCount, string discountCode, double& discountAmount)
{
    if (discountCode == "Yes") {
        totalPrice = totalPrice - 5;
    }
    if (toppingCount == 3) {
        totalPrice = totalPrice - (pizzaPrice * 0.1);
    }
    return totalPrice;
}




void printOrderSummary(double totalPrice, double pizzaPrice, double discountAmount, string size, string topping, string topping2, string topping3, int toppingCount, string drink, string dessert, string discountCode) {
    cout << endl << "Your order: " << endl;

    cout << "- " << size << " Pizza: $" << fixed << setprecision(2) << getPizzaPrice(size) << endl;


    cout << "- " << topping << " Topping: $" << fixed << setprecision(2) << getToppingPrice(topping) << endl;
    if (toppingCount == 2) { cout << "- " << topping2 << " Topping: $" << fixed << setprecision(2) << getToppingPrice(topping2) << endl; }
    if (toppingCount == 3) {
        cout << "- " << topping2 << " Topping: $" << fixed << setprecision(2) << getToppingPrice(topping2) << endl;
        cout << "- " << topping3 << " Topping: $" << fixed << setprecision(2) << getToppingPrice(topping3) << endl;
    }


    cout << "- " << "Drink: " << drink << " ($" << fixed << setprecision(2) << getDrinkPrice(drink) << ")" << endl;

    if (dessert == "None") {}
    else { cout << "- Dessert: " << dessert << " ($" << fixed << setprecision(2) << getDessertPrice(dessert) << ")" << endl; }

    if (toppingCount == 3) { cout << "- 10% discount on pizza applied: -$" << fixed << setprecision(2) << pizzaPrice * 0.1 << endl; }

    if (discountCode == "Yes") { cout << "- Discount code applied: -$" << fixed << setprecision(2) << discountAmount << endl; }

    totalPrice = applyDiscount(totalPrice, pizzaPrice, toppingCount, discountCode, discountAmount);

    cout << "Final Total: $" << fixed << setprecision(2) << totalPrice << endl;

}


int main()
{
    string size, topping, topping2, topping3, drink, dessert, discountCode;
    double totalPrice, pizzaPrice;
    int toppingCount;

    cout << "Choose pizza size (Small/Medium/Large): ";
    cin >> size;

    cout << "How many toppings would you like? (1-3): ";
    cin >> toppingCount;
    cout << "Enter first topping (Cheese, Pepperoni, Mushrooms, Olives, Bacon, Peppers): ";
    cin >> topping;
    if (toppingCount == 2) {
        cout << "Enter second topping: ";
        cin >> topping2;
    }
    if (toppingCount == 3) {
        cout << "Enter second topping: ";
        cin >> topping2;
        cout << "Enter third topping: ";
        cin >> topping3;

    }

    cout << "Choose a drink (Water, Soda, Juice): ";
    cin >> drink;


    cout << "Would you like a dessert? (Brownie, Cookie, Cheesecake, None): ";
    cin >> dessert;


    cout << "Do you have a discount code? (Yes/No): ";
    cin >> discountCode;
    double discountAmount = 5;

    calculateTotal(totalPrice, pizzaPrice, size, topping, topping2, topping3, toppingCount, drink, dessert);

    printOrderSummary(totalPrice, pizzaPrice, discountAmount, size, topping, topping2, topping3, toppingCount, drink, dessert, discountCode);


}
