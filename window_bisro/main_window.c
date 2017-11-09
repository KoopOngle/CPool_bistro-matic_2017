#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

gchar stext[50];
void resultat(GtkWidget *button, gpointer entry);

int main(int ac, char **av)
{
	GtkWidget * window;
	GtkWidget * vBox;
	GtkWidget * entry;
	GtkWidget * table;
	GtkWidget * button[19];
	GtkWidget * MenuBar;
	GtkWidget * Menujtem;

	
	gtk_init(&ac,&av);

	//window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "The bistrokage !");
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	//box
	vBox = gtk_vbox_new(0, 0);
	gtk_container_add(GTK_CONTAINER(window), vBox);

        //Menu
	MenuBar = gtk_menu_bar_new();

	Menujtem = gtk_menu_item_new_with_label("Edition");

	gtk_menu_shell_append(GTK_MENU_SHELL(MenuBar), Menujtem);


	gtk_box_pack_start(GTK_BOX(vBox), MenuBar, FALSE, FALSE, 0);
	//entry

	entry = gtk_entry_new_with_max_length(50);
	gtk_entry_set_editable(GTK_ENTRY(entry), TRUE);
	gtk_entry_set_alignment(GTK_ENTRY(entry), TRUE);
	gtk_entry_set_has_frame(GTK_ENTRY(entry), TRUE);

	//table
	table = gtk_table_new(8, 3, 1);
	gtk_container_add(GTK_CONTAINER(vBox), table);
	gtk_table_attach_defaults(GTK_TABLE(table), entry, 0, 4, 0, 1);

	button[1] = gtk_button_new_with_label("1");
	gtk_table_attach(GTK_TABLE(table), button[1], 0, 1, 2, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[2] = gtk_button_new_with_label("2");
	gtk_table_attach(GTK_TABLE(table), button[2], 1, 2, 2, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[3] = gtk_button_new_with_label("3");
	gtk_table_attach(GTK_TABLE(table), button[3], 2, 3, 2, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[4] = gtk_button_new_with_label("+");
	gtk_table_attach(GTK_TABLE(table), button[4], 3, 4, 2, 3, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 20, 0);
	button[5] = gtk_button_new_with_label("4");
	gtk_table_attach(GTK_TABLE(table), button[5], 0, 1, 3, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[6] = gtk_button_new_with_label("5");
	gtk_table_attach(GTK_TABLE(table), button[6], 1, 2, 3, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[7] = gtk_button_new_with_label("6");
	gtk_table_attach(GTK_TABLE(table), button[7], 2, 3, 3, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[8] = gtk_button_new_with_label("-");
	gtk_table_attach(GTK_TABLE(table), button[8], 3, 4, 3, 4, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 20, 0);
	button[9] = gtk_button_new_with_label("7");
	gtk_table_attach(GTK_TABLE(table), button[9], 0, 1, 4, 5, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[10] = gtk_button_new_with_label("8");
	gtk_table_attach(GTK_TABLE(table), button[10], 1, 2, 4, 5, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[11] = gtk_button_new_with_label("9");
	gtk_table_attach(GTK_TABLE(table), button[11], 2, 3, 4, 5, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[12] = gtk_button_new_with_label("*");
	gtk_table_attach(GTK_TABLE(table), button[12], 3, 4, 4, 5, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 20, 0);
	button[13] = gtk_button_new_with_label("0");
	gtk_table_attach(GTK_TABLE(table), button[13], 1, 2, 5, 6, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 0, 0);
	button[14] = gtk_button_new_with_label("%");
	gtk_table_attach(GTK_TABLE(table), button[14], 2, 3, 5, 6, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 10, 0);
	button[15] = gtk_button_new_with_label("/");
	gtk_table_attach(GTK_TABLE(table), button[15], 0, 1, 5, 6, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 10, 0);
	button[16] = gtk_button_new_with_label("=");
	gtk_table_attach(GTK_TABLE(table), button[16], 3, 4, 5, 6, GTK_EXPAND | GTK_FILL, GTK_EXPAND, 20, 0);


	//signal
	g_signal_connect(GTK_OBJECT(button[15]), "clicked", G_CALLBACK(resultat), (GtkWidget *) entry);

       	gtk_widget_show_all(window);

	
	gtk_main();
	
}

void resultat(GtkWidget *button, gpointer entry)
{
	strcat(stext, gtk_button_get_label(GTK_BUTTON(button)));
	gtk_entry_set_text(GTK_ENTRY(entry), stext);
}
