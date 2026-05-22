#pragma once

#include "Algorithm.h"

namespace Domain::Tests::Main {

class AlgorithmDoubleActing : public Algorithm
{
    Q_OBJECT

public:
    explicit AlgorithmDoubleActing(QObject* parent = nullptr)
        : Algorithm(parent)
    {
    }

    void run() override;

signals:
    void waitingForManualResume();
};

}
