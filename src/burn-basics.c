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
 *            burn-basics.c
 *
 *  Sat Feb 11 16:55:54 2006
 *  Copyright  2006  philippe
 *  <philippe@Rouquier Philippe.localdomain>
 ****************************************************************************/

#include <string.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib.h>
#include <glib/gi18n-lib.h>
#include <glib/gstdio.h>

#include <libgnomevfs/gnome-vfs.h>

#include "burn-basics.h"
#include "burn-debug.h"
#include "burn-caps.h"
#include "burn-plugin-manager.h"
#include "burn-plugin-private.h"
#include "brasero-ncb.h"

static BraseroPluginManager *manager = NULL;

GQuark
brasero_burn_quark (void)
{
	static GQuark quark = 0;

	if (!quark)
		quark = g_quark_from_static_string ("BraseroBurnError");

	return quark;
}
 
const gchar *
brasero_burn_action_to_string (BraseroBurnAction action)
{
	gchar *strings [BRASERO_BURN_ACTION_LAST] = { 	"",
							N_("Getting size"),
							N_("Creating image"),
							N_("Writing"),
							N_("Blanking"),
							N_("Creating checksum"),
							N_("Copying disc"),
							N_("Copying file"),
							N_("Analysing audio information"),
							N_("Transcoding song"),
							N_("Preparing to write"),
							N_("Writing leadin"),
							N_("Writing CD-TEXT information"),
							N_("Fixating"),
							N_("Writing leadout"),
							N_("Success") };
	return _(strings [action]);
}

BraseroBurnResult
brasero_burn_library_init (void)
{
	nautilus_burn_init ();
	NCB_INIT ();

	brasero_burn_caps_get_default ();

	if (!manager)
		manager = brasero_plugin_manager_get_default ();

	brasero_caps_list_dump ();
	return BRASERO_BURN_OK;
}

GSList *
brasero_burn_library_get_plugins_list (void)
{
	manager = brasero_plugin_manager_get_default ();
	return brasero_plugin_manager_get_plugins_list (manager);
}

void
brasero_burn_library_shutdown (void)
{
	if (manager) {
		g_object_unref (manager);
		manager = NULL;
	}
}
