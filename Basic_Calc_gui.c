#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Global variables for the calculator
GtkWidget *num1_entry, *num2_entry, *operator_combo, *result_label;

// Function to perform calculation
void calculate(GtkWidget *widget, gpointer data) {
    const gchar *num1_text = gtk_entry_get_text(GTK_ENTRY(num1_entry));
    const gchar *num2_text = gtk_entry_get_text(GTK_ENTRY(num2_entry));
    gint op_index = gtk_combo_box_get_active(GTK_COMBO_BOX(operator_combo));
    
    // Validate input
    if (num1_text[0] == '\0' || num2_text[0] == '\0') {
        gtk_label_set_text(GTK_LABEL(result_label), "Please enter both numbers");
        return;
    }
    
    double num1 = atof(num1_text);
    double num2 = atof(num2_text);
    double result = 0;
    gchar result_str[100];
    
    // Perform calculation based on selected operator
    switch (op_index) {
        case 0: // +
            result = num1 + num2;
            snprintf(result_str, sizeof(result_str), "%.2f + %.2f = %.2f", num1, num2, result);
            break;
        case 1: // -
            result = num1 - num2;
            snprintf(result_str, sizeof(result_str), "%.2f - %.2f = %.2f", num1, num2, result);
            break;
        case 2: // *
            result = num1 * num2;
            snprintf(result_str, sizeof(result_str), "%.2f * %.2f = %.2f", num1, num2, result);
            break;
        case 3: // /
            if (num2 != 0) {
                result = num1 / num2;
                snprintf(result_str, sizeof(result_str), "%.2f / %.2f = %.2f", num1, num2, result);
            } else {
                snprintf(result_str, sizeof(result_str), "Error: Division by zero!");
            }
            break;
        case 4: // ^
            if (num2 >= 0) {
                result = pow(num1, num2);
                snprintf(result_str, sizeof(result_str), "%.2f ^ %.2f = %.2f", num1, num2, result);
            } else {
                snprintf(result_str, sizeof(result_str), "Error: Negative exponent not supported");
            }
            break;
        default:
            snprintf(result_str, sizeof(result_str), "Please select an operator");
            break;
    }
    
    gtk_label_set_text(GTK_LABEL(result_label), result_str);
}

// Function to clear all fields
void clear_fields(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(num1_entry), "");
    gtk_entry_set_text(GTK_ENTRY(num2_entry), "");
    gtk_combo_box_set_active(GTK_COMBO_BOX(operator_combo), -1);
    gtk_label_set_text(GTK_LABEL(result_label), "Result will be shown here");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *calculate_button, *clear_button;
    GtkWidget *num1_label, *num2_label, *operator_label;
    
    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Basic Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Create a grid for layout
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    
    // Create and add widgets to the grid
    num1_label = gtk_label_new("First Number:");
    gtk_grid_attach(GTK_GRID(grid), num1_label, 0, 0, 1, 1);
    
    num1_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), num1_entry, 1, 0, 2, 1);
    
    operator_label = gtk_label_new("Operator:");
    gtk_grid_attach(GTK_GRID(grid), operator_label, 0, 1, 1, 1);
    
    // Create a combo box for operators
    operator_combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operator_combo), "+");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operator_combo), "-");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operator_combo), "*");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operator_combo), "/");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(operator_combo), "^");
    gtk_grid_attach(GTK_GRID(grid), operator_combo, 1, 1, 2, 1);
    
    num2_label = gtk_label_new("Second Number:");
    gtk_grid_attach(GTK_GRID(grid), num2_label, 0, 2, 1, 1);
    
    num2_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), num2_entry, 1, 2, 2, 1);
    
    // Create buttons
    calculate_button = gtk_button_new_with_label("Calculate");
    g_signal_connect(calculate_button, "clicked", G_CALLBACK(calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate_button, 0, 3, 2, 1);
    
    clear_button = gtk_button_new_with_label("Clear");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(clear_fields), NULL);
    gtk_grid_attach(GTK_GRID(grid), clear_button, 2, 3, 1, 1);
    
    // Result label
    result_label = gtk_label_new("Result will be shown here");
    gtk_label_set_line_wrap(GTK_LABEL(result_label), TRUE);
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 4, 3, 1);
    
    // Show all widgets
    gtk_widget_show_all(window);
    
    // Start the GTK main loop
    gtk_main();
    
    return 0;
}
