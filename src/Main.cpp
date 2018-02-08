// TODO: Implement
#include <iostream>
#include <vector>
#include <sharedptr>

#include "Handlers/IHandler.hpp"

int main(int argc, char **argv)
{
    std::string input;
    std::vector<std::shared_ptr<IHandler>> handlerList = { new LoginHandler };

    while(true) {
        std::cout << "Enter a command: " << std::endl;
        std::cin >> input;

        for(auto handler : handlerList) {
            if (input == handler->GetName())
                handler->Handle(user);
        }
    }

    return 0;
}