/*Program that calculates the amount of time to pay off a loan based on the principal amount
remaining, interest rate, and monthly payments to be made. This DOES NOT account for future
balance increases, interest rate changes, or changes to monthly payments. It's simply a
snapshot.

Copyright 2025 TxMedic436
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.

WARRANTY INFORMATION:
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "Table.h"

#define PRINCIPAL 0
#define RATE 1
#define PAYMENT 2

void usage(const char* name){
    std::cerr << "usage: " << name << " principal_amount interest_rate monthly_payment\n";
    std::cerr << "All arguments must be numerical and above 0.\n";
}

float nper(double principal, float rate, double payment){
    //n = log(M / (M - P * r)) / log(1 + r)
    return log(payment / (payment - (principal * rate))) / log(1 + rate);
}

int main(int argc, char** argv){
    //BEGIN ARGUMENT VALIDATION
    double user_data[3], adj_rate;

    if(argc < 4 ){
        std::cerr << "Not enough arguments.\n";
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < argc; i++){
        if(i == 0) {continue;}
        if(!isdigit(*argv[i])){
            std::cerr << "Invalid argument. '" << argv[i] << "'" << std::endl;
            usage(argv[0]);
            return EXIT_FAILURE;
        }
        user_data[i-1] = atof(argv[i]);
    }
    //END ARGUMENT VALIDATION

    //Test
    Table table;

    //BEGIN PROGRAM
    adj_rate = user_data[RATE] / 1200.0;
    float result = nper(user_data[PRINCIPAL], adj_rate, user_data[PAYMENT]);
    std::cout << "It will take " << std::ceil(result) << " months to pay off $" << user_data[PRINCIPAL] << " in debt with a payment of "
              << user_data[PAYMENT] << " each month at a rate of " << user_data[RATE] << "%." << std::endl;

    return 0;
}
