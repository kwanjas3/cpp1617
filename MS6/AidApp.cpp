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

   AidApp::~AidApp()
   {
      deallocate();
   }

   void AidApp::pause() const
   {
      cin.clear();
      cout << "Press Enter to continue...";
      cin.ignore(1, '\n');
   }

   int AidApp::menu()
   {

      int menu = -1;
      cout << "Disaster Aid Supply Management Program" << endl
         << "1- List Products" << endl
         << "2 - Display product" << endl
         << "3 - Add non - perishable product" << endl
         << "4 - Add perishable product" << endl
         << "5 - Add to quantity of purchased products" << endl
         << "0 - Exit program" << endl
         << "> ";

      cin >> menu;
      if (cin.fail()) {
         menu = -1;
      }
      cin.ignore();

      return (menu > -1 || menu < 6) ? menu : -1;
   }

   void AidApp::loadRecs()
   {
      int readIndex = 0;
      char c; //readType

      datafile_.open(filename_, ios::in);

      if (datafile_.fail() || !datafile_.is_open()) {
         datafile_.clear();
         datafile_.close();
         datafile_.open(filename_, ios::out);
         datafile_.close();
      }
      else {
         deallocate();
         while (datafile_.good() && !datafile_.eof()) {
            datafile_ >> c;
            datafile_.ignore();
            if (datafile_.fail()) { break; } // stops the last line of garbage from being read
            else
               if (c == 'N' || c == 'P') {
                  if (c == 'N') {
                     product_[readIndex] = new AmaProduct();
                  }
                  if (c == 'P') {
                     product_[readIndex] = new AmaPerishable();
                  }
                  product_[readIndex]->load(datafile_);
                  readIndex++;
               }
         }
         noOfProducts_ = readIndex;
         datafile_.close();
      }
   }
   void AidApp::saveRecs()
   {
      datafile_.open(filename_, ios::out);
      for (int i = 0; i < noOfProducts_; i++) {
         product_[i]->store(datafile_);
      }
      datafile_.close();
   }

   void AidApp::listProducts() const
   {
      double total = 0;
      cout << "----|-------|--------------------|-------|----|----------|----|----------" << endl <<
         "Row |SKU    | Item Name          | Cost  | QTY| Unit     |need| Expiry   " << endl <<
         "----|-------|--------------------|-------|----|----------|----|----------" << endl;

      for (int i = 0; i < noOfProducts_; i++) {
         //product_[i]->write(cout, 1) << endl;
         cout << right << setw(4) << i + 1 << "|" << *product_[i] << endl;
         total += *product_[i];
      }

      std::cout << "-------|--------------------|-------|----|----------|----|----------" << std::endl
         << "       | Total: $"
         << " " << std::left << std::setw(38) << std::setprecision(2) << std::fixed << total << " |" << std::endl
         << "       +---------------------------------------------- --+" << endl;
   }

   int AidApp::SearchProducts(const char * sku) const
   {
      int index = -1;
      for (int i = 0; i < noOfProducts_; i++) {
         if (*product_[i] == sku) { index = i; }
      }
      return index;
   }

   void AidApp::addQty(const char * sku)
   {
      int q = 0;
      int index = SearchProducts(sku);
      int amtreq = product_[index]->qtyNeeded() - product_[index]->quantity();
      if (index == -1) {
         cout << "Not found!" << endl;
      }
      else {
         product_[index]->write(cout, false) << endl;
         cout << "Please enter the number of purchased items: ";
         cin >> q;
         if (cin.fail()) {
            cout << "Invalid quantity value!" << endl;
         }
         if (q <= amtreq) {
            *product_[index] += q;

         }
         else {
            cout << "Too many items: only " << amtreq << "is needed,"
               << " please return the extra " << q - amtreq << " items." << endl;
         }
         //    *product_[index]->quantity += amtreq;
      }
      cout << "Updated!" << endl;
      cin.ignore();
      saveRecs();
      //  cin.ignore();
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
      // cin.ignore();

   }

   int AidApp::run()
   {
      int index;
      int select;
      char stemp[MAX_SKU_LEN + 1] = { 0 };
      char st[MAX_SKU_LEN + 1] = { 0 };


      do {
         select = menu();
         switch (select) {
         case 1:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                    ------ List products ------" << endl << endl;
            listProducts();
            pause();
            break;
         case 2:
            cout << "========------ Aid Management Application ------========" << endl << endl;
            cout << "                 ------ Display product ------" << endl << endl;
            cout << "Enter the Sku: ";
            cin >> stemp;
            index = SearchProducts(stemp);
            if (index == -1) {
               cout << "Not Found!" << endl;
            }
            else {
               product_[index]->write(cout, false);
               cout << endl;
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
            cout << "Please enter the SKU: ";
            cin >> st;        
            addQty(st);
            

            pause();
            break;
         case 0:
            cout << "Goodbye!!" << endl;

            break;
         default:
            cout << "===Invalid Selection, try again.===" << endl;
            pause();
            break;
         }
      } while (select != 0);
      return 0;
   }

   void AidApp::deallocate()
   {
      for (int i = 0; i < noOfProducts_; i++) {

         if (product_[i] != nullptr) {
            delete product_[i];
            product_[i] = nullptr;
         }
      }
   }

}

