/* ============================================================================
 * Copyright (c) 2012 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2012 Dr. Michael A. Groeber (US Air Force Research Laboratories)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                           FA8650-07-D-5800
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include "PMFileGenerator.h"

#include <iostream>

#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QTextStream>
#include <QtCore/QFileInfo>

#include "QtSupport/ApplicationFileInfo.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
PMFileGenerator::PMFileGenerator(QString outputDir,
                                 QString pathTemplate,
                                 QString fileName,
                                 QString codeTemplateResourcePath,
                                 QTreeWidgetItem* wi,
                                 QObject* parent):
  PMDirGenerator(outputDir, pathTemplate, QString(""), codeTemplateResourcePath, wi, parent),
  m_FileName(fileName),
  setupFPContents(""),
  readFPContents(""),
  writeFPContents(""),
  dataCheckContents(""),
  fpContents(""),
  initListContents(""),
  filterHIncludesContents(""),
  filterCPPIncludesContents("")
{
  if (NULL != wi)
  {
    wi->setText(0, fileName);
  }
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
PMFileGenerator::~PMFileGenerator()
{
  // TODO Auto-generated destructor stub
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString PMFileGenerator::getFileName()
{
  return m_FileName;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::pluginNameChanged(const QString& pluginName)
{
//  qDebug() << "PMFileGenerator::pluginNameChanged" << "\n";

  QString pin = cleanName(pluginName);

  if (pin.isEmpty() == true)
  {
    setPluginName("Unknown Plugin Name");
  }
  else
  {
    setPluginName(pin);
  }

  if (isNameChangeable() == false)
  {
    return;
  }
  m_FileName = pin + getDisplaySuffix();

  if (NULL != getTreeWidgetItem())
  {
    getTreeWidgetItem()->setText(0, m_FileName );
  }


}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::outputDirChanged(const QString& outputDir)
{
//  qDebug() << "PMFileGenerator::outputDirChanged" << "\n";
  setOutputDir(outputDir);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::generateOutput()
{
//  qDebug() << "PMFileGenerator::generateOutput" << "\n";
  if (doesGenerateOutput() == false)
  {
    return;
  }

  //Get text feature values from widget
  QString pluginName = getPluginName();
  QString pluginDir = getOutputDir();

  if (pluginName.isEmpty() == true || pluginDir.isEmpty() == true)
  {
    return;
  }

  QString contents = getFileContents();

  if (contents.isEmpty() == false)
  {
    QString parentPath = getOutputDir() + QDir::separator() + getPathTemplate().replace("@PluginName@", getPluginName());
    parentPath = QDir::toNativeSeparators(parentPath);

    QDir dir(parentPath);
    dir.mkpath(parentPath);

    parentPath = parentPath + QDir::separator() + m_FileName;

    //Write to file
    QFile f(parentPath);
    if ( f.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
      QTextStream out(&f);
      out << contents;
    }
  }
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString PMFileGenerator::generateFileContents(QString replaceStr)
{
  QString pluginName = getPluginName();

  QString contents = getFileContents(replaceStr);

  return contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString PMFileGenerator::getFileContents(QString replaceStr)
{
  //Get text feature values from widget
  QString pluginName = getPluginName();
  QString pluginDir = getOutputDir();
  QString text = "";

  if (pluginName.isEmpty() == true || pluginDir.isEmpty() == true)
  {
    return text;
  }

  //Open file
  QFile rfile(getCodeTemplateResourcePath());
  if (rfile.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream in(&rfile);
    text = in.readAll();
    text.replace("@PluginName@", pluginName);
    QFileInfo fi(m_FileName);
    QString className = fi.baseName();
    QString filterName = className;
    filterName = filterName.remove("Test");   // For the test files
    text.replace("@ClassName@", className);
    text.replace("@FilterName@", filterName);
    text.replace("@MD_FILE_NAME@", m_FileName);
    text.replace("@ClassNameLowerCase@", className.toLower());
    text.replace("@FilterGroup@", pluginName);
    text.replace("@FilterSubgroup@", pluginName);

    // Replace function contents with the string that we have stored
    text.replace("@SetupFPContents@", setupFPContents);
    text.replace("@FPContents@", fpContents);
    text.replace("@ReadFPContents@", readFPContents);
    text.replace("@WriteFPContents@", writeFPContents);
    text.replace("@DataCheckContents@", dataCheckContents);
    text.replace("@InitList@", initListContents);
    text.replace("@Filter_H_Includes@", filterHIncludesContents);
    text.replace("@Filter_CPP_Includes@", filterCPPIncludesContents);

    if (replaceStr.isEmpty() == false)
    {
      text.replace("@AddTestText@", replaceStr);		// Replace token for Test/CMakeLists.txt file
      text.replace("@Namespaces@", replaceStr);		// Replace token for Test/TestFileLocations.h.in file
    }

    rfile.close();
  }

  return text;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::generateOutputWithFilterNames(QSet<QString> names)
{
  //  qDebug() << "PMFileGenerator::generateOutput" << "\n";
  if (doesGenerateOutput() == false)
  {
    return;
  }

  //Get text feature values from widget
  QString pluginName = getPluginName();
  QString pluginDir = getOutputDir();

  if (pluginName.isEmpty() == true || pluginDir.isEmpty() == true)
  {
    return;
  }

  //  QString classNameLowerCase = m_ClassName.toLower();

  //Open file
  QFile rfile(getCodeTemplateResourcePath());
  if (rfile.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream in(&rfile);
    QString text = in.readAll();

    text.replace("@PluginName@", pluginName);
    QFileInfo fi(m_FileName);
    QString className = fi.baseName();
    text.replace("@ClassName@", className);
    text.replace("@MD_FILE_NAME@", m_FileName);
    text.replace("@ClassNameLowerCase@", className.toLower());
    text.replace("@FilterGroup@", pluginName);
    text.replace("@FilterSubgroup@", pluginName);

    if (names.isEmpty() == false)
    {
      if (getFileName() == "TestFileLocations.h.in")
      {
        QString replaceStr = createReplacementString(TESTFILELOCATIONS, names);
        text.replace("@Namespaces@", replaceStr);		// Replace token for Test/TestFileLocations.h.in file
        qDebug() << text;
      }
      else if (getFileName() == "CMakeLists.txt")
      {
        QString replaceStr = createReplacementString(CMAKELISTS, names);
        text.replace("@AddTestText@", replaceStr);		// Replace token for Test/CMakeLists.txt file
        std::cout << text.toStdString();
        qDebug() << text;
      }
    }

    QString parentPath = getOutputDir() + QDir::separator() + getPathTemplate().replace("@PluginName@", getPluginName());
    parentPath = QDir::toNativeSeparators(parentPath);

    QDir dir(parentPath);
    dir.mkpath(parentPath);

    parentPath = parentPath + QDir::separator() + m_FileName;
    //Write to file
    QFile f(parentPath);
    if (f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
      QTextStream out(&f);
      out << text;
    }
  }
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString PMFileGenerator::createReplacementString(FileType type, QSet<QString> names)
{
	QString pluginName = getPluginName();
	QString replaceStr = "";
	if (type == CMAKELISTS)
	{
		// Build up the huge string full of namespaces using names
		QSet<QString>::iterator iter = names.begin();
		while (iter != names.end())
		{
			QString name = *iter;

			if (name == "@PluginName@Filter")
			{
				name.replace("@PluginName@", pluginName);
			}

			replaceStr.append("AddDREAM3DUnitTest(TESTNAME " + name + "Test SOURCES ${${PROJECT_NAME}_SOURCE_DIR}/" + name + "Test.cpp LINK_LIBRARIES ${${PROJECT_NAME}_Link_Libs})");

			if (++iter != names.end())
			{
				replaceStr.append("\n");
			}
		}
	}
	else if (type == TESTFILELOCATIONS)
	{
		// Build up the huge string full of namespaces using names
		QSet<QString>::iterator iter = names.begin();
		while (iter != names.end())
		{
			QString name = *iter;

			if (name == "@PluginName@Filter")
			{
				name.replace("@PluginName@", pluginName);
			}

			replaceStr.append("namespace " + name + "Test\n");
			replaceStr.append("  {\n");
			replaceStr.append("    const QString TestFile1(\"@TEST_TEMP_DIR@/TestFile1.txt\");\n");
			replaceStr.append("    const QString TestFile2(\"@TEST_TEMP_DIR@/TestFile2.txt\");\n");
			replaceStr.append("  }");

			if (++iter != names.end())
			{
				replaceStr.append("\n\n");
			}
		}
	}

	return replaceStr;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setSetupFPContents(QString contents)
{
  setupFPContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setReadFPContents(QString contents)
{
  readFPContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setWriteFPContents(QString contents)
{
  writeFPContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setDataCheckContents(QString contents)
{
  dataCheckContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setFPContents(QString contents)
{
  fpContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setInitListContents(QString contents)
{
  initListContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setFilterHIncludesContents(QString contents)
{
  filterHIncludesContents = contents;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void PMFileGenerator::setFilterCPPIncludesContents(QString contents)
{
  filterCPPIncludesContents = contents;
}



