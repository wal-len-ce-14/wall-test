#include <iostream>
//using namespace std;

// Below we define the base class
class Quote { 
public: 
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    //returns the total sales price for the specified number of items
    virtual double net_price(std::size_t n)  
        { return n * price; }
    virtual ~Quote() = default; // dynamic binding for the destructor
private:
    std::string bookNo; 
    std::size_t total = 0;
protected:
    double price = 0.0; // this is protected because we want it to be used by 
                        // the derived classes
};

//Below we define a class derived from the base class Quote
class Bulk_quote : public Quote { 
public:
	int Sell_total();
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc): 
        Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t) override;
private:
	
    std::size_t min_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0; // the discount to apply
    //std::size_t total = 0; // a acount for the total sold volumes
};

double Bulk_quote::net_price(size_t cnt)  { 
	total += cnt;
    if (cnt >= min_qty) 
        return cnt * (1-discount) * price;
    else
        return cnt * price;
}

std::size_t Bulk_quote::Sell_total(){
	return total;
}

int main()
{
    Quote item("TKU in Love", 100.0); 
    std::cout << "BOOK: " << item.isbn();
    std::cout << ", total cost: " << item.net_price(10) << std::endl;
    Bulk_quote bulk("TKU Indeed", 100.0, 5, 0.2);
    std::cout << "BOOK: " << bulk.isbn();
    std::cout << ", total cost: " << bulk.net_price(10) << std::endl;
    std::cout << "BOOK: " << bulk.isbn();
    std::cout << ", total cost: " << bulk.net_price(20) << std::endl;
    std::cout << "Total sell: " << bulk.Sell_total() << std::endl;
    return 0;
}

