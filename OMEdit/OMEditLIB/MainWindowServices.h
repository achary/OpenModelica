/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#ifndef MAINWINDOWSERVICES_H
#define MAINWINDOWSERVICES_H

#include <qobjectdefs.h>
#include <QString>

class OMCProxy;
class LibraryWidget;
class StackFramesWidget;
class BreakpointsWidget;
class TargetOutputWidget;
class LocalsWidget;
class QDockWidget;
class GDBLoggerWidget;
class DocumentationWidget;
class QDockWidget;
class PlotWindowContainer;
class VariablesWidget;
class QDockWidget;
class SearchWidget;
class QWidget;
class ModelWidgetContainer;
class Label;
class ThreeDViewer;
class SimulationDialog;
class TLMCoSimulationDialog;
class OMSSimulationDialog;
class WelcomePageWidget;
class GitCommands;
class CommitChangesDialog;
class TraceabilityInformationURI;
class QStatusBar;
class QProgressBar;
class QTimer;
class QMimeData;
class QAction;
class LibraryTreeItem;
class QMdiSubWindow;
class TransformationsWidget;

class MainWindowServices
{
public:
  virtual bool isDebug() const = 0;
  virtual void setDebug(bool debug) = 0;
  virtual bool isNewApi() const = 0;
  virtual void setNewApi(bool newApi) = 0;
  virtual bool isTestsuiteRunning() const = 0;
  virtual void setTestsuiteRunning(bool testsuiteRunning) = 0;
  virtual OMCProxy *getOMCProxy() = 0;
  virtual void setExitApplicationStatus(bool status) = 0;
  virtual bool getExitApplicationStatus() = 0;
  virtual int getNumberOfProcessors() = 0;
  virtual LibraryWidget *getLibraryWidget() = 0;
  virtual StackFramesWidget *getStackFramesWidget() = 0;
  virtual BreakpointsWidget *getBreakpointsWidget() = 0;
  virtual LocalsWidget *getLocalsWidget() = 0;
  virtual TargetOutputWidget *getTargetOutputWidget() = 0;
  virtual QDockWidget *getTargetOutputDockWidget() = 0;
  virtual GDBLoggerWidget *getGDBLoggerWidget() = 0;
  virtual DocumentationWidget *getDocumentationWidget() = 0;
  virtual QDockWidget *getDocumentationDockWidget() = 0;
  virtual PlotWindowContainer *getPlotWindowContainer() = 0;
  virtual VariablesWidget *getVariablesWidget() = 0;
  virtual QDockWidget *getVariablesDockWidget() = 0;
  virtual SearchWidget *getSearchWidget() = 0;
  virtual void printStandardOutAndErrorFilesMessages() = 0;
  virtual void addSystemLibraries() = 0;
  virtual QWidget *mainWindowWidget() = 0;
  virtual ModelWidgetContainer *getModelWidgetContainer() = 0;
#if !defined(WITHOUT_OSG)
  virtual bool isThreeDViewerInitialized() = 0;
  virtual ThreeDViewer *getThreeDViewer() = 0;
  virtual QDockWidget *getThreeDViewerDockWidget() = 0;
#endif
  virtual SimulationDialog *getSimulationDialog() = 0;
  virtual TLMCoSimulationDialog *getTLMCoSimulationDialog() = 0;
  virtual OMSSimulationDialog *getOMSSimulationDialog() = 0;
  virtual WelcomePageWidget *getWelcomePageWidget() = 0;
  virtual GitCommands *getGitCommands() = 0;
  virtual CommitChangesDialog *getCommitChangesDialog() = 0;
  virtual TraceabilityInformationURI *getTraceabilityInformationURI() = 0;
  virtual QStatusBar *getStatusBar() = 0;
  virtual QProgressBar *getProgressBar() = 0;
  virtual void showProgressBar() = 0;
  virtual void hideProgressBar() = 0;
  virtual Label *getPositionLabel() = 0;
  virtual bool isModelingPerspectiveActive() = 0;
  virtual bool isPlottingPerspectiveActive() = 0;
  virtual bool isDebuggingPerspectiveActive() = 0;
  virtual void findFileAndGoToLine(QString fileName, QString lineNumber) = 0;
  virtual QString getLibraryIndexFilePath() const = 0;
  virtual QTimer *getAutoSaveTimer() = 0;
  virtual void openDroppedFile(const QMimeData *pMimeData) = 0;
  virtual bool isItActiveWindow() = 0;
  virtual QAction *getUndoAction() = 0;
  virtual QAction *getRedoAction() = 0;
  virtual QAction *getResetZoomAction() = 0;
  virtual QAction *getZoomInAction() = 0;
  virtual QAction *getZoomOutAction() = 0;
  virtual bool openInstallLibraryDialog() = 0;
  virtual void updateRecentFileActionsAndList() = 0;
  virtual void toggleAutoSave() = 0;
  virtual void fetchInterfaceData(LibraryTreeItem *pLibraryTreeItem, QString singleModel = QString()) = 0;
  virtual TransformationsWidget *showTransformationsWidget(QString fileName, bool profiling) = 0;
  virtual void updateModelSwitcherMenu(QMdiSubWindow *pSubWindow) = 0;

  static MainWindowServices *instance();
public slots:
  virtual void undo() = 0;
  virtual void redo() = 0;
  virtual void switchToWelcomePerspectiveSlot() = 0;
  virtual void switchToModelingPerspectiveSlot() = 0;
  virtual void switchToPlottingPerspectiveSlot() = 0;
  virtual void switchToAlgorithmicDebuggingPerspectiveSlot() = 0;
private:
};

#endif // MAINWINDOWSERVICES_H
