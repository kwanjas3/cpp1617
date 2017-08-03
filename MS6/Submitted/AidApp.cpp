#include <iomanip>
#include <cstring>
#include "AidApp.h"
using namespace std;
namespace sict {
   AidApp::AidApp(const char * filename)
   {
      strncpy(filename_, filename, 256);
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
      cin.ignore(1000, '\n');
   }

   int AidApp::menu()
   {

      int menu = -1;
      cout << "Disaster Aid Supply Management Program" << endl
         << "1- List products" << endl
         << "2- Display product" << endl
         << "3- Add non-perishable product" << endl
         << "4- Add perishable product" << endl
         << "5- Add to quantity of purchased products" << endl
         << "0- Exit program" << endl
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
      cout << endl <<
         " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl <<
         "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

      for (int i = 0; i < noOfProducts_; i++) {
         //product_[i]->write(cout, 1) << endl;
         cout << right << setw(4) << i + 1 << " |" << *product_[i] << endl;
         total += *product_[i];
      }

      std::cout << "---------------------------------------------------------------------------" << std::endl
         << "Total cost of support: $"
         << std::setprecision(2) << std::fixed << total << std::endl;
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
         product_[index]->write(cout, false) << endl << endl;
         cout << "Please enter the number of purchased items: ";
         cin >> q;
         if (cin.fail()) {
            cout << "Invalid quantity value!" << endl;
         }
         if (q <= amtreq) {
            *product_[index] += q;
            cout << endl;
            cout << "Updated!" << endl;
         }
         else {
            *product_[index] += amtreq;
            cout << "Too many items: only " << amtreq << "is needed,"
               << " please return the extra " << q - amtreq << " items." << endl;
         }
         //    *product_[index]->quantity += amtreq;
      }

      cin.ignore();
      saveRecs();
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
            listProducts();
            cout << endl;
            pause();
            cout << endl;
            break;
         case 2:

            cout <<endl << "Please enter the SKU: ";
            cin >> stemp;
            cout << endl;
            index = SearchProducts(stemp);
            if (index == -1) {
               cout << "Not Found!" << endl;
            }
            else {
               product_[index]->write(cout, false);
               cin.ignore();
               cout << endl << endl;
            }
          
            pause();
            cout << endl;
            break;
         case 3:
            cout << endl;
            addProduct(false);
            cin.ignore();
            cout << endl;
            cout << "Product added";
            cout << endl << endl;
            break;
         case 4:
            cout << endl;
            addProduct(true);
            cout << endl;
            cout << "Product added";
	    cout << endl << endl;
            break;
         case 5:
            cout << endl;
            cout << "Please enter the SKU: ";
            cin >> st;      
            cout << endl;
            addQty(st);
            cout << endl;
            break;
         case 0:
            cout << endl;
            cout << "Goodbye!!" << endl;

            break;
         default:
            cout << endl;
            cout << "===Invalid Selection, try again.===" << endl;
            pause();
            cout << endl;
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

