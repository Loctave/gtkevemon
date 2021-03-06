// This file is part of GtkEveMon.
//
// GtkEveMon is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// You should have received a copy of the GNU General Public License
// along with GtkEveMon. If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

#include <gtkmm.h>

#include "net/asynchttp.h"
#include "bits/config.h"
#include "defines.h"
#include "imagestore.h"
#include "gtkdefines.h"
#include "guiaboutdialog.h"

GuiAboutDialog::GuiAboutDialog (void)
{
  Gtk::Image* logo = Gtk::manage(new Gtk::Image(ImageStore::aboutlogo));
  Gtk::Frame* logo_frame = MK_FRAME0;
  logo_frame->add(*logo);
  logo_frame->set_shadow_type(Gtk::SHADOW_IN);

  Gtk::Label* title_label = MK_LABEL0;
  title_label->set_halign(Gtk::ALIGN_START);
  title_label->set_text("<b>GtkEveMon - a skill monitor for Linux</b>");
  title_label->set_use_markup(true);

  Gtk::Label* info_label = MK_LABEL0;
  info_label->set_line_wrap(true);
  info_label->set_justify(Gtk::JUSTIFY_LEFT);
  info_label->set_halign(Gtk::ALIGN_START);
  info_label->set_text(
      "GtkEveMon is a skill monitoring standalone\n"
      "application for GNU/Linux systems. With GtkEveMon\n"
      "you can monitor your current skills and your\n"
      "skill training process without starting EVE-Online.\n"
      "You will never miss to train your next skill!\n\n"

      "GtkEveMon on Github:\n"
      "https://github.com/gtkevemon/gtkevemon\n\n"
      "GtkEveMon " GTKEVEMON_VERSION_STR);
  info_label->set_use_markup(true);

  Gtk::Button* close_but = MK_BUT("Close");
  Gtk::Box* button_box = MK_HBOX(5);
  button_box->pack_end(*close_but, false, false, 0);

  Gtk::Box* about_label_box = MK_VBOX(5);
  about_label_box->pack_start(*title_label, false, false, 0);
  about_label_box->pack_start(*info_label, false, false, 0);
  about_label_box->pack_end(*button_box, false, false, 0);

  Gtk::Box* logo_text_box = MK_HBOX(5);
  logo_text_box->set_spacing(10);
  logo_text_box->pack_start(*logo_frame, false, false, 0);
  logo_text_box->pack_start(*about_label_box, true, true, 0);

  Gtk::Box* main_box = MK_VBOX(5);
  main_box->set_border_width(5);
  main_box->pack_start(*logo_text_box, false, false, 0);

  close_but->signal_clicked().connect(sigc::mem_fun(*this, &WinBase::close));

  this->add(*main_box);
  this->set_default_size(410, 250);
  this->set_title("About GtkEveMon");
  this->show_all();
}
