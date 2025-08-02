#include "MainWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/AProgressBar.h>

using namespace declarative;

MainWindow::MainWindow(_<MyUpdater> updater) : AWindow("Project template app", 300_dp, 200_dp), mUpdater(std::move(updater)) {

}

