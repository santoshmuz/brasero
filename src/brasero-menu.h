/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/***************************************************************************
 *            menu.h
 *
 *  Sat Jun 11 12:00:29 2005
 *  Copyright  2005  Philippe Rouquier	
 *  <brasero-app@wanadoo.fr>
 ****************************************************************************/

#ifndef _MENU_H
#define _MENU_H

G_BEGIN_DECLS

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib.h>
#include <glib/gi18n-lib.h>

#include <gtk/gtkstock.h>
#include <gtk/gtkaction.h>
#include <gtk/gtktoggleaction.h>

#include "brasero-utils.h"
#include "brasero-app.h"

void on_prefs_cb (GtkAction *action, BraseroApp *app);
void on_erase_cb (GtkAction *action, BraseroApp *app);
void on_integrity_check_cb (GtkAction *action, BraseroApp *app);

void on_exit_cb (GtkAction *action, BraseroApp *app);

void on_burn_cb (GtkAction *action, BraseroApp *app);
void on_disc_info_cb (GtkAction *action, BraseroApp *app);
void on_about_cb (GtkAction *action, BraseroApp *app);

static GtkActionEntry entries[] = {
	{"ProjectMenu", NULL, N_("_Project")},
	{"ViewMenu", NULL, N_("_View")},
	{"EditMenu", NULL, N_("_Edit")},
	{"DiscMenu", NULL, N_("_Disc")},
	{"HelpMenu", NULL, N_("_Help")},

	{"Prefs", GTK_STOCK_PREFERENCES, N_("Pre_ferences"), NULL,
	 N_("Set preferences for brasero"), G_CALLBACK (on_prefs_cb)},

	{"Erase", "media-optical-blank", N_("_Erase"), NULL,
	 N_("Erase a disc"), G_CALLBACK (on_erase_cb)},

	{"Check", GTK_STOCK_FIND, N_("_Check integrity"), NULL,
	 N_("Check data integrity of disc"), G_CALLBACK (on_integrity_check_cb)},

	{"Exit", GTK_STOCK_QUIT, N_("E_xit"), NULL,
	 N_("Exit the program"), G_CALLBACK (on_exit_cb)},

	{"About", GTK_STOCK_ABOUT, N_("About"), NULL, N_("About"),
	 G_CALLBACK (on_about_cb)},

	{"DiscInfo", GTK_STOCK_CDROM, N_("_Disc Info"), NULL,
	 N_("Display information on blank discs currently inserted"),
	 G_CALLBACK (on_disc_info_cb)},
};


static const gchar *description = {
	"<ui>"
	    "<menubar name='menubar' >"
	    "<menu action='ProjectMenu'>"
	    "<placeholder name='ProjectPlaceholder'/>"
	    "<separator/>"
	    "<menuitem action='Exit'/>"
	    "</menu>"
	    "<menu action='EditMenu'>"
	    "<placeholder name='EditPlaceholder'/>"
	    "<separator/>"
	    "<menuitem action='Prefs'/>"
	    "</menu>"
	    "<menu action='ViewMenu'>"
	    "<placeholder name='ViewPlaceholder'/>"
	    "</menu>"
	    "<menu action='DiscMenu'>"
	    "<placeholder name='DiscPlaceholder'/>"
	    "<menuitem action='Erase'/>"
	    "<menuitem action='Check'/>"
	    "</menu>"
	    "<menu action='HelpMenu'>"
	    "<menuitem action='About'/>"
	    "</menu>"
	    "</menubar>"
	"</ui>"
};

G_END_DECLS

#endif				/* _MENU_H */
