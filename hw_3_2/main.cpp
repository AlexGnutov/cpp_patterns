#include <iostream>
#include <memory>

#include "observable.h"


int main()
{

    std::shared_ptr<WarningObserver> wo(new WarningObserver());
    std::shared_ptr<ErrorObserver> eo(new ErrorObserver("log.txt"));
    std::shared_ptr<FatalErrorObserver> feo(new FatalErrorObserver("log.txt"));

    auto po = new Observable();

    po->addObserver(wo);
    po->addObserver(eo);
    po->addObserver(feo);

    po->warning("time to warn you, Sir");
    po->error("time to error you, Sir");
    po->fatalError("time to fatal error you, Sir");

    return 0;
}
