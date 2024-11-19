# Ethanol Fuel Analyzer

Brazil is the largest producer of ethanol fuel in the world. Since 2006, most cars have been able to receive ethanol, gasoline or a mixture of both fuels. 

Brazilian gasoline has ethanol in its composition, around 27%, which is used as an anti-knock and can increase some HP in engine.

A sustainable solution that pollutes less but the problem is the lack of supervision, many gas stations adulterate the fuel with more ethanol which is cheaper to maximize their profits in a dishonest way.

After researching a lot I discovered that there is a sensor that measures the percentage of fuel in ethanol, widely used in Volkswagen/Audi cars but which can be adapted to any car model.

The sensor model is 06k907811b manufactured by Continental and is not expensive. 

To be adapted to any vehicle, the sensor must be installed in the fuel return line and connected to a micro-controller (such as ESP32, Arduino, STM...) to read the sensor values.

The sensor sends values ​​in "Hz" and the microcontroller code needs a falling border interruption to count how many cycles occurred in half a second and a variable is increased each time it receives the sensor signal.

To finish, you need to multiply the result by 2 to get the value in seconds, subtract 50 to get the value in percentage and reset the increased value for the next reading.

This experiment has no legal value for judicial purposes as it needs to be approved by INMETRO, it is a Brazilian government agency responsible for ensuring the quality and reliability of products and services in the country.

   
