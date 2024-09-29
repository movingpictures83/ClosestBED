#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "ClosestBEDPlugin.h"

void ClosestBEDPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void ClosestBEDPlugin::run() {}

void ClosestBEDPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "closestBed -a";
myCommand += " ";
addRequiredParameterNoFlag("A");
addRequiredParameter("-b", "B");
myCommand += " >& "+outputfile + " ";
std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<ClosestBEDPlugin> ClosestBEDPluginProxy = PluginProxy<ClosestBEDPlugin>("ClosestBED", PluginManager::getInstance());
