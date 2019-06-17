#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/document.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{  
  rapidjson::Document d;
  ifstream fp("orders.json");
  rapidjson::IStreamWrapper isw(fp);

  d.ParseStream(isw);
  fp.close();

  cout << d["orders"][0]["order_id"].GetString() << endl;
  
  return 0;
}
