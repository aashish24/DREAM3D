/* ============================================================================
 * Copyright (c) 2010, Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2010, Dr. Michael A. Groeber (US Air Force Research Laboratories
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


#ifndef QUALITYMETRICITEMDELEGATE_H_
#define QUALITYMETRICITEMDELEGATE_H_
#include <iostream>


#include <QtCore/QModelIndex>
#include <QtCore/QStringList>
#include <QtGui/QStyledItemDelegate>


#include "DREAM3DLib/Common/Constants.h"
#include "ComparisonSelectionTableModel.h"

class QPainter;
class QAbstractItemModel;

class ComparisonSelectionItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

  public:
    explicit ComparisonSelectionItemDelegate(QStringList possibleFeatures, int numPhases, QObject* parent = 0);

    virtual ~ComparisonSelectionItemDelegate();


    void setNumberOfPhases(int n);


    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void setFeatureList(QStringList features);

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void setEditorData(QWidget* editor, const QModelIndex& index) const;

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

  private:
    QModelIndex m_Index;
    QStringList m_FeatureList;
    int m_NumberOfPhases;

};

#endif /*  */


