#include <stdio.h>

double CalculateTax10(double income);
double CalculateTax12(double income);
double CalculateTax22(double income);
double CalculateTax24(double income);
double CalculateTax32(double income);
double CalculateTax35(double income);
double CalculateTax37(double income);
double CalculateTotalTax(double income);
void TaxCalculated(double income);
double AverageTax(double income);

double CalculateTax10(double income) {
  double tax10;
  tax10 = income * .1;
  return tax10;
}

double CalculateTax12(double income) {
  double tax12;
  tax12 = income * .12;
  return tax12;
}

double CalculateTax22(double income) {
  double tax22;
  tax22 = income * .22;
  return tax22;
}

double CalculateTax24(double income) {
  double tax24;
  tax24 = income * .24;
  return tax24;
}

double CalculateTax32(double income) {
  double tax32;
  tax32 = income * .32;
  return tax32;
}

double CalculateTax35(double income) {
  double tax35;
  tax35 = income * .35;
  return tax35;
}

double CalculateTax37(double income) {
  double tax37;
  tax37 = income * .37;
  return tax37;
}

double CalculateTotalTax(double income) {
  double taxedmoney = 0;
  if ((income > 0) && (income <= 9875)) {
      taxedmoney += CalculateTax10(income);
    } else if (income > 9875) {
      taxedmoney += CalculateTax10(9875);
    }

  if ((income - 9875 <= 30250) && (income - 9875 > 0)) {
      taxedmoney += CalculateTax12(income - 9875);
    } else if (income > 40125) {
      taxedmoney += CalculateTax12(30250);
    }

  if ((income - 40125 <= 45400) && (income - 40125 > 0)) {
      taxedmoney += CalculateTax22(income - 40125);
    } else if (income > 85525) {
      taxedmoney += CalculateTax22(45400);
    }

  if ((income - 85525 <= 77775) && (income - 85525 > 0)) {
      taxedmoney += CalculateTax24(income - 85525);
    } else if (income > 163300) {
      taxedmoney += CalculateTax24(77775);
    }

  if ((income - 163300 <= 44050) && (income - 166300 > 0)) {
      taxedmoney += CalculateTax32(income - 163300);
    } else if (income > 207350) {
      taxedmoney += CalculateTax32(44050);
    }

  if ((income - 207350 <= 311050) && (income - 207350 > 0)) {
      taxedmoney += CalculateTax35(income - 207350);
    } else if (income > 518400) {
      taxedmoney += CalculateTax35(311050);
    }

  if (income > 518400) {
      taxedmoney += CalculateTax37(income - 518400);
    } return taxedmoney;
}

void TaxCalculated(double income) {
  if ((income > 0) && (income <= 9875)) {
    double tax10;
    tax10 = CalculateTax10(income);
    printf("You were taxed 10.00%% on the first $%.2f you made which is $%.2f.\n", income, tax10);
  } else if (income > 9875) {
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
  }

  if (((income - 9875) > 0) && ((income - 9875) <= 30250)) {
    double tax12;
    tax12 = CalculateTax12(income - 9875);
    printf("You were taxed 12.00%% on the first $%.2f you made which is $%.2f.\n ", (income - 9875), tax12);
  } else if (income > 40125) {
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
  }

  if (((income - 40125) > 0) && ((income - 40125) <= 45400)) {
    double tax22;
    tax22 = CalculateTax22(income - 40125);
    printf("You were taxed 22.00%% on the next $%.2f you made which is $%.2f.\n", (income - 40125), tax22);
  } else if (income > 85525) {
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
  }

  if (((income - 85525) > 0) && ((income - 85525) <= 77775)) {
    double tax24;
    tax24 = CalculateTax24(income - 85525);
    printf("You were taxed 24.00%% on the next $%.2f you made which is $%.2f.\n", (income - 85525), tax24);
  } else if (income > 163300) {
    printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
  }

  if (((income - 163300) > 0) && ((income - 163300) <= 44050)) {
    double tax32;
    tax32 = CalculateTax32(income - 163300);
    printf("You were taxed 32.00%% on the next $%.2f you made which is $%.2f.\n", (income - 163300), tax32);
  } else if (income > 207350) {
    printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
  }

  if (((income - 207350) > 0) && ((income - 207350) <= 311050)) {
    double tax35;
    tax35 = CalculateTax35(income - 207350);
    printf("You were taxed 35.00%% on the next $%.2f you made which is $%.2f.\n", (income - 207350), tax35);
  } else if (income > 518400) {
    printf("You were taxed 35.00%% on the next $311050.00 you made which is $108867.50.\n");
  }

  if (income > 518400) {
    double tax37;
    tax37 = CalculateTax37(income - 518400);
    printf("You were taxed 37.00%% on the next $%.2f you made which is $%.2f.\n", (income - 518400), tax37);
  }
}

double AverageTax(double income) {
  double AvgTax;
  AvgTax = ((CalculateTotalTax(income) * 100) / income);
  return AvgTax;
}

int main() {
  double income;

  printf("Enter your income for the year: ");
  scanf("%lf", &income);
  TaxCalculated(income);
  printf("In total you will pay $%.2f in taxes on the $%.2f you made this year.\n", CalculateTotalTax(income), income);
  printf("This would amount to a FLAT tax of %.2f%% on all of your income.\n", AverageTax(income));
  return 0;
}
