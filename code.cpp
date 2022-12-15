#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Defining a structure to represent a newspaper
struct Newspaper {
  double monday_price;
  double tuesday_price;
  double wednesday_price;
  double thursday_price;
  double friday_price;
  double saturday_price;
  double sunday_price;
};

// Calculating the weekly subscription cost for a given newspaper
double weekly_subscription_cost(const Newspaper& newspaper) {
  return newspaper.monday_price + newspaper.tuesday_price + newspaper.wednesday_price
       + newspaper.thursday_price + newspaper.friday_price + newspaper.saturday_price
       + newspaper.sunday_price;
}

// Finding all possible combinations of newspaper subscriptions for a given budget
 vector<vector<string>> find_all_combinations(const map<string, Newspaper>& newspapers, double budget) {
  vector<vector<string>> combinations;

  for (const auto& [newspaper_name, newspaper] : newspapers) {
    
    if (weekly_subscription_cost(newspaper) <= budget) {
      if (combinations.empty()) {
        combinations.push_back({newspaper_name});
      } else {
        vector<vector<string>> new_combinations;
        for (const auto& combination : combinations) {
          new_combinations.push_back(combination);
          combinations.push_back(newspaper_name);
          new_combinations.push_back(combination);
        }
        combinations = new_combinations;
      }
    }
  }

  return combinations;
}

int main() {
  map<string, Newspaper> newspapers;

  newspapers["TOI"] = {3, 3, 3, 3, 3, 5, 6};
  newspapers["Hindu"] = {2.5, 2.5, 2.5, 2.5, 2.5, 4, 4};
  newspapers["ET"] = {4 ,4, 4, 4 ,4 ,4 ,10};
  newspapers["BM"] = {1.5 ,1.5, 1.5, 1.5, 1.5, 1.5, 1.5};
  newspapers["HT"] = {2, 2, 2 ,2 ,2, 4, 4};
  


  double budget;
  cout << "Enter the weekly budget for subscriptions: ";
  cin >> budget;

  // Finding all possible combinations of newspaper subscriptions for the given budget
  auto combinations = find_all_combinations(newspapers, budget);

  // Output the combinations
  if (combinations.empty()) {
    cout << "No combinations of newspaper subscriptions are within the given budget." << endl;
  } else {
    cout << "The following combinations of newspaper subscriptions are within the given budget:" << endl;
    for (const auto& combination : combinations) {
      for (const auto& newspaper_name : combination) {
        cout << newspaper_name << " ";
      }
    }
  }
  return 0;
}
    
  
      