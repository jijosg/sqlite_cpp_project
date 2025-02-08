// #include "cxxopts.hpp"

// #include <iostream>
// #include <cpr/cpr.h>

// int command_line(int argc, char* argv[]) {
//     std::cout << "CPlusPlus Version : ";
//     std::cout << __cplusplus << std::endl;

//     // Parse command line arguments
//     cxxopts::Options options("CppProject", "Trying to build a CLI using C++17 and learning cmake to package it");
//     options.add_options()
//         ("l,location", "city name", cxxopts::value<std::string>())
//         ("h,help", "print usage");
//         ;
//     auto result = options.parse(argc, argv);
//     if (result.count("help"))
//     {
//       std::cout << options.help() << std::endl;
//       exit(0);
//     }
//     std::string location;
//     if (result.count("location"))
//       location = result["location"].as<std::string>();
//       std::string url = "https://www.wttr.in/" + location;

//     auto response = cpr::Get(cpr::Url{url});
//     std::cout << response.text << std::endl;
//     return 0;
// }