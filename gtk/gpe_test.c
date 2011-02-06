#include <stdlib.h>
#include <gtk/gtk.h>
#include "gtkpasswordentry.h"

/*
void win( GtkWidget *widget,
          gpointer   data )
{
  g_print ("Yay!\n");
  gtk_password_entry_clear (TICTACTOE (widget));
}
*/
int main( int   argc,
          char *argv[] )
{
  GtkWidget *window;
  GtkWidget *gpe;
  
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
  gtk_window_set_title (GTK_WINDOW (window), "Aspect Frame");
  
  g_signal_connect (window, "destroy",
		    G_CALLBACK (exit), NULL);
  
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  gpe = gtk_password_entry_new ();
//  gtk_entry_set_visibility (GTK_ENTRY(gpe), FALSE);
  
  gtk_container_add (GTK_CONTAINER (window), gpe);
  gtk_widget_show (gpe);

  /* And attach to its "gtk_password_entry" signal */
//  g_signal_connect (gpe, "gtk_password_entry",
//		    G_CALLBACK (win), NULL);

  gtk_widget_show (window);
  
  gtk_main ();
  
  return 0;
}
