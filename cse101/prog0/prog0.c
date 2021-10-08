#include <cairo.h>
#include <inttypes.h>
#include <stdio.h>
#include <math.h>

//important pointers used in program
uint32_t width = 0, height = 0, depth = 0;
double fraction = 0.;
double start[2], end[2];
cairo_surface_t *surface = NULL;
cairo_t *cr = NULL;

void scalar(double c, double *a, double *x){
  //finds scalar product between a and c.
  x[0] = c * a[0];
  x[1] = c * a[1];
  return;
}

void sum(double *a, double *b, double *x){
  //finds sum of two points.
  x[0] = b[0] + a[0];
  x[1] = b[1] + a[1];
  return;
}

void point_between(double c, double *a, double *b, double *x){
  //finds point on line between a and b, and stores it in x.
  //This point will be scaled by c, with c = 1 being b, and
  //c = 0 being a.
  double res[2];
  res[0] = b[0] - a[0];
  res[1] = b[1] - a[1];
  double temp[2];
  scalar(c,res, temp);
  sum(a, temp, x);
  return;
}

void recursive_call(double current_depth, double *one, double *two) {
  //exit condition for recursive call
  if (current_depth == 0) {
    return;
  }
  //important points and numbers
  double dx = two[0] - one[0];
  double dy = two[1] - one[1];
  double three[2] = {two[0] + dy, two[1] - dx};
  double four[2] = {three[0] - dx, three[1] - dy};
  double color = 1.; //- ((.5) * exp(1 - depth + current_depth));

  //first line
  cairo_set_source_rgb(cr, color , 0, 0);
  cairo_move_to(cr, one[0], one[1]);
  cairo_line_to(cr, two[0], two[1]);
  cairo_set_line_width(cr, 1.);
  cairo_stroke(cr);

  //second line
  cairo_set_source_rgb(cr, color, 0, 0);
  cairo_move_to(cr, two[0], two[1]);
  cairo_line_to(cr, three[0], three[1]);
  cairo_set_line_width(cr, 1.);
  cairo_stroke(cr);

  //third line
  cairo_set_source_rgb(cr, color, 0, 0);
  cairo_move_to(cr, three[0], three[1]);
  cairo_line_to(cr, four[0], four[1]);
  cairo_set_line_width(cr, 1.);
  cairo_stroke(cr);

  //fourth line
  cairo_set_source_rgb(cr, color, 0, 0);
  cairo_move_to(cr, four[0], four[1]);
  cairo_line_to(cr, one[0], one[1]);
  cairo_set_line_width(cr, 1.);
  cairo_stroke(cr);

  //find new start and end points
  double new_start[2];
  double new_end[2];
  point_between(fraction, one, two, new_start);
  point_between(fraction, two, three, new_end);
  recursive_call(current_depth - 1, new_start, new_end);
  return;
}

void get_input(){
  //gets input and stores them in variables
  scanf("%" PRIu32, &width);
  scanf("%" PRIu32, &height);
  scanf("%" PRIu32, &depth);
  scanf("%lf", &fraction);
  scanf("%lf", &start[0]);
  scanf("%lf", &start[1]);
  scanf("%lf", &end[0]);
  scanf("%lf", &end[1]);
}
int main() {
  // Get stdin input
  get_input();
  // Initialize cairo
  surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cr = cairo_create(surface);

  // Set background to white
  cairo_rectangle(cr, 0, 0, width, height);
  cairo_set_source_rgb(cr, 1, 1, 1); // purple
  cairo_fill(cr);

  // Make recursive call
  recursive_call(depth, start, end);

  // Output to png and memory management
  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "output1.png");
  cairo_surface_destroy(surface);
  return 0;
}
