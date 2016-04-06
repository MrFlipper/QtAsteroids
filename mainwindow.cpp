/***************************************************************************
 *   Copyright (C) 2009 by Richard Crook                                   *
 *   richard@dazzle.plus.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <QCloseEvent>
#include <QMessageBox>
#include <QToolBar>
#include "mainwindow.h"
#include "scene.h"
#include <QDesktopWidget>

#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>

/*************************************************************************************/
/*********************** Main application window for QSimulate ***********************/
/*************************************************************************************/

/************************************ constuctor *************************************/


MainWindow::MainWindow() : QMainWindow()
{
  // add drop down menus (currently empty)
  menuBar()->addMenu("&File");
  menuBar()->addMenu("&Info");

  // create scene and central widget view of scene
  m_scene               = new Scene();
  QGraphicsView*   view = new QGraphicsView( m_scene );
  view->setAlignment( Qt::AlignLeft | Qt::AlignTop );
  view->setFrameStyle( 0 );
  setCentralWidget( view );

  // connect message signal from scene to showMessage slot
  connect( m_scene, SIGNAL(message(QString)), this, SLOT(showMessage(QString)) );

  // add status bar message
  statusBar()->showMessage("QSimulate has started");
  resize(QDesktopWidget().availableGeometry(this).size() * 0.5); //sets screen size
  //QAction* newAction     = fileMenu->addAction( "&New",              this, SLOT(fileNew()) ); //action to start new game
  //fileMenu->addSeparator();
  //fileMenu->addAction( "&Quit",             this, SLOT(close()) );
  //newAction->setShortcut( QKeySequence::New );
}

/************************************ showMessage ************************************/

void  MainWindow::showMessage( QString msg )
{
  // display message on main window status bar
  statusBar()->showMessage( msg );
}
