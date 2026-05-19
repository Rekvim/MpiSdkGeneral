#include "Builder.h"

#include "Report/Pages/TechnicalInspection.h"
#include "Report/Pages/StepReaction.h"

#include "Report/Writer.h"

namespace Report {
void Builder::build(
    ReportData& report,
    const Telemetry& telemetryStore,
    const ObjectInfo& objectInfo,
    const ValveInfo& valveInfo,
    const MaterialsOfComponentParts& materials,
    const OtherParameters& otherParams,
    const ChartImageStorage& chartImages
    )
{
    Writer writer(report);

    Context ctx{
        telemetryStore,
        objectInfo,
        valveInfo,
        materials,
        otherParams,
        chartImages
    };

    {
        Pages::TechnicalInspection::Layout layout;
        layout.sheet = m_sheetTechnicalInspection;

        layout.positionRow = 1;

        layout.objectInfoRow = 5;
        layout.valveSpecRow = 5;
        layout.materialsRow = 11;
        layout.technicalResultsRow = 29;
        layout.strokeTimeRow = 51;

        layout.firstDateRow = 65;
        layout.fioRow = 73;

        layout.taskImageRow = 83;
        layout.pressureImageRow = 111;
        layout.frictionImageRow = 139;

        layout.secondDateRow = 165;

        layout.positionerModel = true;
        layout.includeSolenoid = false;

        Pages::TechnicalInspection(layout).build(writer, ctx);
    }

    writer.validation(m_sheetTechnicalInspection, "=ЗИП!$A$1:$A$37", "J55:J64");
    writer.validation(m_sheetTechnicalInspection, "=Заключение!$B$1:$B$4", "E41");
    writer.validation(m_sheetTechnicalInspection, "=Заключение!$C$1:$C$3", "E43");
    writer.validation(m_sheetTechnicalInspection, "=Заключение!$E$1:$E$4", "E45");
    writer.validation(m_sheetTechnicalInspection, "=Заключение!$D$1:$D$5", "E47");
    writer.validation(m_sheetTechnicalInspection, "=Заключение!$F$3", "E49");

    {
        Pages::StepReaction::Layout layout;
        layout.sheet = m_sheetStepReactionTest;

        layout.positionRow = 1;

        layout.objectInfoRow = 4;
        layout.valveSpecRow = 4;

        layout.imageRow = 17;
        layout.tableStartRow = 55;

        layout.dateRow = 67;

        layout.positionerModel = true;
        layout.includeSolenoid = false;

        Pages::StepReaction(layout).build(writer, ctx);
    }
}
}