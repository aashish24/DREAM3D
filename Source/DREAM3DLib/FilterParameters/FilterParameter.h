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

#ifndef _FilterParameter_H_
#define _FilterParameter_H_

#include <QtCore/QMetaType>
#include <QtCore/QVector>

#include "DREAM3DLib/DREAM3DLib.h"
#include "DREAM3DLib/Common/DREAM3DSetGetMacros.h"
#include "DREAM3DLib/DataContainers/DataContainerArrayProxy.h"

typedef struct { int x; int y; int z; } IntVec3_t;
typedef struct { float x; float y; float z; } FloatVec3_t;
//typedef struct { QString arrayName; int compOperator; double compValue; } ComparisonInput_t;
typedef struct { float angle; float h; float k; float l; } AxisAngleInput_t;

Q_DECLARE_METATYPE(IntVec3_t)
Q_DECLARE_METATYPE(FloatVec3_t)
Q_DECLARE_METATYPE(AxisAngleInput_t)


namespace FilterParameterWidgetType
{

      const QString StringWidget("StringWidget");
      const QString IntWidget("IntWidget");
      const QString DoubleWidget("DoubleWidget");
      const QString InputFileWidget("InputFileWidget");
      const QString InputPathWidget("InputPathWidget");
      const QString OutputFileWidget("OutputFileWidget");
      const QString OutputPathWidget("OutputPathWidget");
      const QString BooleanWidget("BooleanWidget");
      const QString ChoiceWidget("ChoiceWidget"); // Generic ComboBox Drop down where the filter provides the list of strings
      const QString IntVec3Widget("IntVec3Widget");
      const QString FloatVec3Widget("FloatVec3Widget");
      const QString AxisAngleWidget("AxisAngleWidget");
      const QString UnknownWidget("UnknownWidget");
      const QString DataContainerArrayProxyWidget("DataContainerArrayProxyWidget");
      const QString ArraySelectionWidget("ArraySelectionWidget"); // This is the generic array name selection tool where the user can select multiple arrays with checkboxes from all data containers
      const QString SingleArraySelectionWidget("SingleArraySelectionWidget");
      const QString ComparisonSelectionWidget("ComparisonSelectionWidget");

#if 0
      /* **** DO NOT PUT ANY OTHER WIDGETS BETWEEN THIS ***** */
      const QString SingleArraySelectionWidget("SingleArraySelectionWidget"); // ComboBox where the Cell Array names are used to populate
      const QString VolumeEdgeArrayNameSelectionWidget("VolumeEdgeArrayNameSelectionWidget"); //ComboBox where the Feature Array names are used to populate
      const QString VolumeFaceArrayNameSelectionWidget("VolumeFaceArrayNameSelectionWidget"); //ComboBox where the Ensemble Array names are used to populate
      const QString VolumeCellArrayNameSelectionWidget("VolumeCellArrayNameSelectionWidget"); // ComboBox where the Cell Array names are used to populate
      const QString VolumeFeatureArrayNameSelectionWidget("VolumeFeatureArrayNameSelectionWidget"); //ComboBox where the Feature Array names are used to populate
      const QString VolumeEnsembleArrayNameSelectionWidget("VolumeEnsembleArrayNameSelectionWidget"); //ComboBox where the Ensemble Array names are used to populate
      const QString SurfaceVertexArrayNameSelectionWidget("SurfaceVertexArrayNameSelectionWidget");
      const QString SurfaceFaceArrayNameSelectionWidget("SurfaceFaceArrayNameSelectionWidget");
      const QString SurfaceEdgeArrayNameSelectionWidget("SurfaceEdgeArrayNameSelectionWidget");
      const QString SurfaceFeatureArrayNameSelectionWidget("SurfaceFeatureArrayNameSelectionWidget");
      const QString SurfaceEnsembleArrayNameSelectionWidget("SurfaceEnsembleArrayNameSelectionWidget");
      const QString EdgeVertexArrayNameSelectionWidget("EdgeVertexArrayNameSelectionWidget");
      const QString EdgeEdgeArrayNameSelectionWidget("EdgeEdgeArrayNameSelectionWidget");
      const QString EdgeFeatureArrayNameSelectionWidget("EdgeFeatureArrayNameSelectionWidget");
      const QString EdgeEnsembleArrayNameSelectionWidget("EdgeEnsembleArrayNameSelectionWidget");
      const QString VertexVertexArrayNameSelectionWidget("VertexVertexArrayNameSelectionWidget");
      const QString VertexFeatureArrayNameSelectionWidget("VertexFeatureArrayNameSelectionWidget");
      const QString VertexEnsembleArrayNameSelectionWidget("VertexEnsembleArrayNameSelectionWidget");
      /* ****  AND THIS LINE ******** */
#endif
      /* This widget presents a blank table and the user clicks an "Add" button to add arrays and Opertors */
      const QString CellArrayComparisonSelectionWidget("CellArrayComparisonSelectionWidget");
      const QString FeatureArrayComparisonSelectionWidget("FeatureArrayComparisonSelectionWidget");
      const QString EnsembleArrayComparisonSelectionWidget("EnsembleArrayComparisonSelectionWidget");
      const QString VertexArrayComparisonSelectionWidget("VertexArrayComparisonSelectionWidget");
      const QString FaceArrayComparisonSelectionWidget("FaceArrayComparisonSelectionWidget");
      const QString EdgeArrayComparisonSelectionWidget("EdgeArrayComparisonSelectionWidget");



      const QString CustomWidget("CustomWidget");
}

/**
 * @class FilterParameter FilterParameter.h DREAM3DLib/FilterParameters/FilterParameter.h
 * @brief This class holds the various properties that an input parameter to a
 * filter needs to describe itself.
 * @author Michael A. Jackson for BlueQuartz Software
 * @date Jan 17, 2012
 * @version 1.0
 */
class FilterParameter
{
  public:
    DREAM3D_SHARED_POINTERS(FilterParameter)
    DREAM3D_STATIC_NEW_MACRO(FilterParameter)
    DREAM3D_TYPE_MACRO(FilterParameter)
    virtual ~FilterParameter() {}

    DREAM3D_INSTANCE_STRING_PROPERTY(HumanLabel)
    DREAM3D_INSTANCE_STRING_PROPERTY(PropertyName)
    DREAM3D_INSTANCE_STRING_PROPERTY(WidgetType)
    DREAM3D_INSTANCE_STRING_PROPERTY(ValueType)
    DREAM3D_INSTANCE_STRING_PROPERTY(CastableValueType)
    DREAM3D_INSTANCE_STRING_PROPERTY(FileExtension)
    DREAM3D_INSTANCE_STRING_PROPERTY(FileType)
    DREAM3D_INSTANCE_STRING_PROPERTY(Units)


  protected:
    FilterParameter() :
      m_ValueType("Not_Set"),
      m_FileExtension(""),
      m_FileType(""),
      m_Units("")
    {}

  private:
    FilterParameter(const FilterParameter&); // Copy Constructor Not Implemented
    void operator=(const FilterParameter&); // Operator '=' Not Implemented
};

typedef QVector<FilterParameter::Pointer> FilterParameterVector;


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
template<typename T>
class ConstrainedFilterParameter : public FilterParameter
{
  public:
    DREAM3D_SHARED_POINTERS(ConstrainedFilterParameter<T>)
    DREAM3D_STATIC_NEW_MACRO(ConstrainedFilterParameter<T>)
    DREAM3D_TYPE_MACRO_SUPER(ConstrainedFilterParameter<T>, FilterParameter)

    virtual ~ConstrainedFilterParameter() {}

    DREAM3D_INSTANCE_PROPERTY(T, Minimum)
    DREAM3D_INSTANCE_PROPERTY(T, Maximum)

  protected:
    ConstrainedFilterParameter() {}

  private:
    ConstrainedFilterParameter(const ConstrainedFilterParameter&); // Copy Constructor Not Implemented
    void operator=(const ConstrainedFilterParameter&); // Operator '=' Not Implemented
};


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
class ChoiceFilterParameter : public FilterParameter
{
  public:
    DREAM3D_SHARED_POINTERS(ChoiceFilterParameter)
    DREAM3D_STATIC_NEW_MACRO(ChoiceFilterParameter)
    DREAM3D_TYPE_MACRO_SUPER(ChoiceFilterParameter, FilterParameter)

    virtual ~ChoiceFilterParameter() {}

    DREAM3D_INSTANCE_PROPERTY(QVector<QString>, Choices)
    DREAM3D_INSTANCE_PROPERTY(bool, Editable)

  protected:
    ChoiceFilterParameter() :
      m_Editable(false) {}

  private:
    ChoiceFilterParameter(const ChoiceFilterParameter&); // Copy Constructor Not Implemented
    void operator=(const ChoiceFilterParameter&); // Operator '=' Not Implemented
};

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
class ComparisonFilterParameter : public FilterParameter
{
  public:
    DREAM3D_SHARED_POINTERS(ComparisonFilterParameter)
    DREAM3D_STATIC_NEW_MACRO(ComparisonFilterParameter)
    DREAM3D_TYPE_MACRO_SUPER(ComparisonFilterParameter, FilterParameter)

    virtual ~ComparisonFilterParameter() {}

    DREAM3D_INSTANCE_PROPERTY(QVector<QString>, Choices)
    DREAM3D_INSTANCE_PROPERTY(bool, ShowOperators)

  protected:
    ComparisonFilterParameter() :
      m_ShowOperators(true) {}

  private:
    ComparisonFilterParameter(const ComparisonFilterParameter&); // Copy Constructor Not Implemented
    void operator=(const ComparisonFilterParameter&); // Operator '=' Not Implemented
};


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
class DataContainerArrayProxyFilterParameter : public FilterParameter
{
  public:
    DREAM3D_SHARED_POINTERS(DataContainerArrayProxyFilterParameter)
    DREAM3D_STATIC_NEW_MACRO(DataContainerArrayProxyFilterParameter)
    DREAM3D_TYPE_MACRO_SUPER(DataContainerArrayProxyFilterParameter, FilterParameter)

    virtual ~DataContainerArrayProxyFilterParameter() {}

    DREAM3D_INSTANCE_PROPERTY(DataContainerArrayProxy, DataContainerArrayProxy)

  protected:
    DataContainerArrayProxyFilterParameter()
     {}

  private:
    DataContainerArrayProxyFilterParameter(const DataContainerArrayProxyFilterParameter&); // Copy Constructor Not Implemented
    void operator=(const DataContainerArrayProxyFilterParameter&); // Operator '=' Not Implemented
};

#endif /* _FilterParameter_H_ */

