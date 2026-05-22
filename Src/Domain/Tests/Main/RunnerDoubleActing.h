#pragma once

#include "Runner.h"
#include "AlgorithmDoubleActing.h"

namespace Domain::Tests::Main {

class RunnerDoubleActing : public Runner {
    Q_OBJECT
public:
    RunnerDoubleActing(Mpi::Device& device, bool normalOpen,
                       const Params& params, QObject* parent = nullptr)
        : Runner(device, normalOpen, params, parent), m_daParams(params) {}

signals:
    void waitingForManualResume();

protected:
    RunnerConfig buildConfig() override;
    void wireSpecificSignals(AbstractTestAlgorithm& t) override;

private:
    Params m_daParams;
};

}
