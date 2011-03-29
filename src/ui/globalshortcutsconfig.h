/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GLOBALSHORTCUTSCONFIG_H
#define GLOBALSHORTCUTSCONFIG_H

#include <QWidget>
#include <QMap>
#include <QSettings>

#include <boost/scoped_ptr.hpp>

#include "core/globalshortcuts.h"

class QTreeWidgetItem;

class Ui_GlobalShortcutsConfig;
class GlobalShortcutGrabber;

class GlobalShortcutsConfig : public QWidget {
 Q_OBJECT

 public:
  GlobalShortcutsConfig(QWidget* parent = 0);
  ~GlobalShortcutsConfig();

  void SetManager(GlobalShortcuts* manager);

  void Load();
  void Save();

 private slots:
  void ItemClicked(QTreeWidgetItem*);
  void NoneClicked();
  void DefaultClicked();
  void ChangeClicked();

  void OpenGnomeKeybindingProperties();

 private:
  struct Shortcut {
    GlobalShortcuts::Shortcut s;
    QKeySequence key;
    QTreeWidgetItem* item;
  };

  void SetShortcut(const QString& id, const QKeySequence& key);

 private:
  Ui_GlobalShortcutsConfig* ui_;

  GlobalShortcuts* manager_;
  boost::scoped_ptr<GlobalShortcutGrabber> grabber_;

  QSettings settings_;
  QMap<QString, Shortcut> shortcuts_;

  QString current_id_;
};

#endif // GLOBALSHORTCUTSCONFIG_H