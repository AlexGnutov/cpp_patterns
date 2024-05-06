#include <iostream>

#include "chain.h"

int main()
{

    auto feh = new FatalErrorHandler();
    auto eh = new ErrorHandler("log.txt");
    auto wh = new WarningHandler();
    auto umh = new UnknownMessageHandler();

    feh->set_next_handler(eh);
    eh->set_next_handler(wh);
    wh->set_next_handler(umh);

    try {
        FatalErrorMessage msg("fatal error, Sir");
        feh->handle_request(msg);
    }  catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }

    {
        ErrorMessage msg("error, Sir");
        feh->handle_request(msg);
    }

    {
        WarningMessage msg("i have to warn your majesty, Sir");
        feh->handle_request(msg);
    }

    try {
        UnknownMessage msg("what?");
        feh->handle_request(msg);
    }  catch (const std::exception& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
