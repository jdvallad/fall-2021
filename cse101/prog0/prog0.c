#include <cairo.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t width = 0, height = 0;
double fraction = 0., start_x = 0., start_y = 0., end_x = 0., end_y = 0.;
cairo_surface_t *surface = NULL;
cairo_t *cr  = NULL;
int main() {
  scanf("%"PRIu32, &width);
  scanf("%"PRIu32, &height);
  scanf("%lf", &fraction);
  scanf("%lf", &start_x);
  scanf("%lf", &start_y);
  scanf("%lf",&end_x);
  scanf("%lf",&end_y);
  printf("Width: %"PRIu32"\n",width);
  printf("Height: %"PRIu32"\n",height);
  printf("Fraction: %lf\n",fraction);
  printf("Start: %lf\n",start);
  printf("End: %lf\n",end);

  // Initialize cairo
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cr = cairo_create(surface);

  // Set background to white
  cairo_rectangle(cr, 0, 0, width, height);
  cairo_set_source_rgb(cr, 0, 0, 0); // purple
  cairo_fill(cr);

  // Make recursive call
  recursive_call(cr, width, height, fraction, start, end);

  // Output to png and memory management
  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "temp.png");
  cairo_surface_destroy(surface);
  return 0;
}

void recursive_call(double w, double h, double f, double s_x, double s_y,
    double e_x, double e_y){
  cairo_set_source_rgb(cr, 1, 0, 1);
  cairo_move_to(w/s_x, h/s_y);
}
