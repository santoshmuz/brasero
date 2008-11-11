/***************************************************************************
 *            burn-dialog.h
 *
 *  mer jun 29 13:05:45 2005
 *  Copyright  2005  Philippe Rouquier
 *  brasero-app@wanadoo.fr
 ***************************************************************************/

/*
 *  Brasero is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Brasero is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#ifndef BURN_DIALOG_H
#define BURN_DIALOG_H

#include <glib.h>
#include <glib-object.h>

#include <gtk/gtkwidget.h>
#include <gtk/gtkdialog.h>

#include "burn-basics.h"
#include "burn.h"

G_BEGIN_DECLS
#define BRASERO_TYPE_BURN_DIALOG         (brasero_burn_dialog_get_type ())
#define BRASERO_BURN_DIALOG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), BRASERO_TYPE_BURN_DIALOG, BraseroBurnDialog))
#define BRASERO_BURN_DIALOG_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), BRASERO_TYPE_BURN_DIALOG, BraseroBurnDialogClass))
#define BRASERO_IS_BURN_DIALOG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), BRASERO_TYPE_BURN_DIALOG))
#define BRASERO_IS_BURN_DIALOG_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), BRASERO_TYPE_BURN_DIALOG))
#define BRASERO_BURN_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BRASERO_TYPE_BURN_DIALOG, BraseroBurnDialogClass))
typedef struct BraseroBurnDialogPrivate BraseroBurnDialogPrivate;

typedef struct {
	GtkDialog parent;
	BraseroBurnDialogPrivate *priv;
} BraseroBurnDialog;

typedef struct {
	GtkDialogClass parent_class;
} BraseroBurnDialogClass;

GType brasero_burn_dialog_get_type ();
GtkWidget *brasero_burn_dialog_new (void);

gboolean
brasero_burn_dialog_run (BraseroBurnDialog *dialog,
			 BraseroBurnSession *session);

#endif				/* BURN_DIALOG_H */
