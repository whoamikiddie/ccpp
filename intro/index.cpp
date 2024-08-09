#include <iostream>
#include <chrono>

void findcode() {
    int i[5]={1,2,3,4,5};
    for (int ii : i) {
        std :: cout << i[ii] << std::endl;
    }



}

int main() { 
    // Get the start time
    auto start = std::chrono::high_resolution_clock::now();
    
    // Call the function you want to measure
    findcode();
    
    // Get the end time
    auto end = std::chrono::high_resolution_clock::now();
    
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    
    // Output the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
    
    return 0;
}
