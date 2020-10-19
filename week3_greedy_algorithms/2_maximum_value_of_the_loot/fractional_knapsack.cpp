#include <iostream>
#include <vector>

using std::vector;

int max(int size,vector<double> arr)
{
  int max_index = 0;
  for (int i = 0; i < size; i++)
  {
    if(arr[i] > arr[max_index]){
      max_index = i;
    }
  }
  return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int size = weights.size();
  vector<double> ratios(size);

   for (int i = 0; i < size ; i++)
   {
     ratios[i] = values[i]/weights[i];
   }
   
   int ratio_max_index = 0;
   while (capacity >= 0)
   {
      ratio_max_index = max(size, ratios);
      ratios.erase(ratios.begin() + ratio_max_index);
      if(weights[ratio_max_index] <= capacity)
      {
        value += values[ratio_max_index];
        capacity-=weights[ratio_max_index];
      }
      else
      {
         value += values[ratio_max_index] * ((double) capacity/weights[ratio_max_index]);
        // capacity = 0;
        //std::cout<< values[ratio_max_index] <<','<< (double)capacity/weights[ratio_max_index] << ',' <<capacity<< std::endl;
        break;
      }
            
   } 
   int round = (int)(value * 10000 + 0.5);
  return double(round)/10000;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout <<optimal_value << std::endl;
  return 0;
}
