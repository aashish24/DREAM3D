#ifndef _orientationanalysisconstants_h_
#define _orientationanalysisconstants_h_

#include <QtCore/QString>
/**
 * @namespace OrientationAnalysis
 * @brief These are strings that the plugin uses for display in error and other information messages.
 */
namespace OrientationAnalysisConstants
{
  const QString OrientationAnalysisPluginFile("OrientationAnalysisPlugin");
  const QString OrientationAnalysisPluginDisplayName("OrientationAnalysis");
  const QString OrientationAnalysisBaseName("OrientationAnalysis");
}

/**
 * @namespace FilterParameterWidgetType
 * @brief If you create custom Filter Parameter Widgets for your classes then those need to be defined here
 */
namespace FilterParameterWidgetType
{

  const QString EbsdToH5EbsdWidget("EbsdToH5EbsdWidget");
  const QString ReadH5EbsdWidget("ReadH5EbsdWidget");
  const QString ConvertHexGridToSquareGridWidget("ConvertHexGridToSquareGridWidget");
}
namespace BlueQuartz
{
  const QString VendorName("BlueQuartz Software, LLC");
  const QString URL("http://www.bluequartz.net");
  const QString Copyright("(C) 2016 BlueQuartz Software, LLC");
}

#endif
