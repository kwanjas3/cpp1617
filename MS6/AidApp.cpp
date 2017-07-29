#include <iomanip>
#include "AidApp.h"
using namespace std;
namespace sict {
   AidApp::AidApp(char * filename)
   {
      strcpy(filename_, filename);
      for (int i = 0; i < MAX_NO_RECS; i++) { product_[i] = nullptr; };
      noOfProducts_ = 0;
      loadRecs();
   }

   void AidApp::pause() const
   {
      cout << "Press Enter to continue...";
      while (getchar() != '\n');
      cin.ignore();
   }

   int AidApp::menu()
   {
      int menu;
      cout << "Disaster Aid Supply Management Program" << endl
         << "1- List Products" << endl
         << "2 - Display product" << endl
         << "3 - Add non - perishable product" << endl
         << "4 - Add perishable product" << endl
         << "5 - Add to quantity of purchased products" << endl
         << "0 - Exit program" << endl
         << "> ";

      cin >> menu;

      //While the input entered is not an integer, prompt the user to enter an integer.
      while (!cin)
      {
         cout << "That was no integer! Please enter an integer: ";
         cin.clear();
         cin.ignore();
         cin >> menu;
      }
      if (menu < 0 || menu > 5) {
         menu = -1;
      }

      return menu;
   }

   void AidApp::loadRecs()
   {
      int readIndex = 0;
      char c;
      Product* temp = nullptr;
      datafile_.open(filename_, ios::in);
      if (datafile_.fail()) {
         datafile_.clear();
         datafile_.close();
         datafile_.open(filename_, ios::out);
         datafile_.close();
      }
      else {

         while (!datafile_.fail()) {
            delete product_[readIndex];
            datafile_ >> c;

            if (c == 'N') {
               product_[readIndex] = new AmaProduct();
            }
            if (c == 'P') {
               product_[readIndex] = new AmaPerishable();
            }

            if (c == 'P' || c == 'N') {
               datafile_.ignore(); //skips comma
               product_[readIndex++]->load(datafile_);
            }
         }
         noOfProducts_ = readIndex;
      }
   }

   void AidApp::saveRecs()
   {
      datafile_.open(filename_, ios::out);
      for (int i = 0; i < noOfProducts_; i++) {
         product_[i]->store(datafile_);
      }
      datafile_.clear();
      datafile_.close();
   }

   void AidApp::listProducts() const
   {
      double total = 0;
      cout <<
         " Row | SKU    | Item Name          | Cost  | QTY|Need| Unit     | Expiry   " << endl <<
         "-----|--------|--------------------|-------|----|----|----------|----------" << endl;

      for (int i = 0; i < noOfProducts_; i++) {
         product_[i]->write(cout, 1);
         total += product_[i]->cost();
      }

      std::cout << "+-----+---------+----------------------+---------+-----+------+--------------+------------+" << std::endl
         << "      | Total: $"
         << " " << std::left << std::setw(37) << std::setprecision(2) << std::fixed << total << " |" << std::endl
         << "      +------------------------------------------------+" << std::endl;
   }

   int AidApp::SearchProducts(const char * sku) const
   {
      int index = -1;
      for (int i = 0; i < noOfProducts_; i++) {
         if (*product_[i] == sku) index = i;
      }
      return index;
   }

   void AidApp::addQty(const char * sku)
   {
      int q = 0;
      int index = SearchProducts(sku);
      if (index == -1) {
         cout << "Not found!" << endl;
      }
      else {
         cout << "Please enter the number of purchased items: ";
         cin >> q;
         if (cin.fail()) {
            cout << "Invalid quantity value!" << endl;
         }
         if (q <= product_[index]->qtyNeeded() - product_[index]->quantity()) {
            product_[index] += q;
            cout << "Updated!" << endl;
            saveRecs();
         }
         else {
            cout << "Too many items: only " << product_[index]->qtyNeeded() - product_[index]->quantity() << "is needed,"
               << "please return the extra " << q - (product_[index]->qtyNeeded() - product_[index]->quantity()) << " items." << endl;
         }
      }

      cin.clear();
   }

   void AidApp::addProduct(bool isPerishable)
   {
      if (isPerishable) {
         product_[noOfProducts_] = new AmaPerishable();
      }
      else {
         product_[noOfProducts_] = new AmaProduct();
      }

      cin >> *product_[noOfProducts_];
      if (cin.fail()) {
         product_[noOfProducts_]->write(cout, false) << endl;
         delete product_[noOfProducts_];
         product_[noOfProducts_] = nullptr;
      }
      else {
         noOfProducts_++;
         saveRecs();
      }
      cin.clear();

   }

   int AidApp::run()
   {
      int index;
      char stemp[MAX_SKU_LEN + 1] = { 0 };
      char st[MAX_SKU_LEN + 1] = { 0 };

      do {
         switch (menu()) {
         case 1:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                    ------ List products ------" << endl << endl;
            listProducts();
            pause();
            break;
         case 2:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                 ------ Display product ------" << endl << endl;
            stemp[MAX_SKU_LEN + 1] = { 0 };
            cin >> stemp;
            index = SearchProducts(stemp);
            if (index == -1) {
               cout << "Not Found!" << endl;
            }
            else {
               product_[index]->write(cout, false);
            }
            pause();
            break;
         case 3:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                 ------ Add non-perishable product ------" << endl << endl;
            addProduct(false);
            pause();
            break;
         case 4:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                 ------ Add perishable product ------" << endl << endl;
            addProduct(true);
            pause();
            break;
         case 5:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                 ------ Add to quantity of purchased products ------" << endl << endl;
            st[MAX_SKU_LEN + 1] = { 0 };
            cout << "Please enter the SKU: ";
            cin >> st;
            if (cin.fail()) {
               std::cout << "SKU invalid!";
               cin.clear();
            }
            else {
               std::cout << std::endl;
               addQty(st);
            }

            pause();
            break;
         case 0:
            cout << "Goodbye!!" << endl;
            break;
         default:
            cout << "===Invalid Selection, try again.===" << endl;
         }
      } while (menu() != 0);
      return 0;
   }

}

