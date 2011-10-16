/**
 * @file Parser.h
 * @author A. Huaman
 * @date 2011-10-06
 * @brief Load from RSDH to dart
 */

#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <Tools/Constants.h>
#include <kinematics/PrimitiveMesh.h>
#include <planning/Robot.h>
#include <planning/Object.h>
#include <planning/World.h>


planning::World* parseWorld( std::string filename );
int parseRobot( std::string _filename, planning::Robot *_robot );
int parseObject( std::string _filename, planning::Object *_object );

#endif /** PARSER_H */