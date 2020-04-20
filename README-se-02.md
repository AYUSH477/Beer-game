##### se-02-team-24
# Beer Game
The beer game is an online game intended for students to better understand howsupply chain works in a real world situation, applying the theory learned in class andpracticing decision making. Therefore it is a functional type of game. This project simulates the way beer is being ordered and delivered from production and factory,going to distributor, then wholesaler and then to retailer and consumer. Each of these stages can be played by the students who, order enough beer stock in the position theyhold, taking into consideration shipment times, delays, backorders, inventory such that,every partner in this chain doesn’t suffer any losses.The objective of the game is to satisfy the demand of the customer, while keepingthe cost low. There is a cost for holding inventory and a cost for not satisfying demand(backorder). The demand for the product remains until it is satisfied i.e. backorder persists until it is fulfilled. It creates the illusion of a real time supply chain, each couldview only the downstream data and the upstream shipment they receive. 

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

#### Prerequisites
What things you need to install the software and how to install them: 

```
GNU C++: https://gcc.gnu.org/install/
Qt: https://www.qt.io/download
NetBeans: https://netbeans.org/downloads/8.2/ (be sure to use version 8.x as version 9 and upwards no longer support C++)
CMake: https://cmake.org/install
Doxygen: https://sourceforge.net/projects/doxygen/
```
Installing
A step by step series of examples that tell you how to get a development env running

Place the follwoing step into terminal to build the project.
```
mkdir build && cd build && cmake ..
```
You can now make the project
```
make
```
To execute the project you need to run
```
./beergame
```
to execute the testing
```
./beergame-tests
```
and to make docs run
```
make doc
```
and then the documentation can be found in the directory doc and in the directory doc.

### Built With
[QT5](https://www.qt.io/) - The GUI framework used  
[Cmake](https://cmake.org/) - Dependency Management  
[Doxygen](http://www.doxygen.nl/) - Used to generate docs  

### Acheived Progress:
Updated the README.md <br/>
Environment set up<br/>
Split the code into separate directories<br/>
Made necessary CMakelists.txt<br/>
Made the comments precise<br/>
Implimented most of class methods<br/>
Implemented all getters and setters<br/>
 
###### Contributors:
Dipak Kandel - Sprint 2 - [Github](https://github.com/kandeldipak06)  
Huzaifa Hashim - Sprint 2 - [Github](https://github.com/hhashim2)
