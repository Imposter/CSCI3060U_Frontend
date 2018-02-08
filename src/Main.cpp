// TODO: Implement
#include <iostream>
#include <vector>
#include <memory>

#include "Handlers/IHandler.hpp"
#include "Handlers/LoginHandler.hpp"

int main(int argc, char **argv)
{
    std::string input;
    std::vector<std::shared_ptr<IHandler>> handlerList = { std::make_shared<LoginHandler>() };

    std::shared_ptr<User> user;

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