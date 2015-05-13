#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

double clamp(double x, double min, double max)
{
	    return x < min ? min : x > max ? max : x;
}

double smoothstep(double x, double edge0, double edge1)
{
	    x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
		    return x * x * (3 - 2 * x);
}

enum color { RED = 0, GREEN, BLUE };

/* Image pixel lookup. */
#define P(image, x, y, color) image->data[y * image->width * 3 + x * 3 + color]

struct image {
	    size_t width, height;
		    uint8_t *data;
};

void image_init(struct image *im, size_t width, size_t height)
{
	    im->width = width;
		    im->height = height;
			    im->data = calloc(im->width * im->height, 3);
}

void image_read(struct image *im, FILE *in)
{
	    size_t width, height;
		    fscanf(in, "P6\n%zu %zu\n255\n", &width, &height);
			    image_init(im, width, height);
				    fread(im->data, width * height, 3, in);
}

void image_write(const struct image *im, FILE *out)
{
	    fprintf(out, "P6\n%zu %zu\n255\n", im->width, im->height);
		    fwrite(im->data, im->width * im->height, 3, out);
}

void image_destroy(struct image *im)
{
	    free(im->data);
		    im->data = NULL;
}

void image_scaledown(struct image *out, const struct image *in, int scale)
{
	    size_t w = in->width / scale, h = in->height / scale;
		    image_init(out, w, h);
			    for (size_t y = 0; y < h; y++) {
					        for (size_t x = 0; x < w; x++) {
								            for (int c = 0; c < 3; c++) {
												                int sum = 0;
																                for (size_t yy = y * scale; yy < (y + 1) * scale; yy++) {
																					                    for (size_t xx = x * scale; xx < (x + 1) * scale; xx++) {
																											                        sum += P(in, xx, yy, c);
																																	                    }
																										                }
																				                P(out, x, y, c) = sum / (scale * scale * 1.0);
																								            }
											        }
							    }
}

void image_halftone(struct image *out, const struct image *in, int scale)
{
	    size_t w = in->width * scale, h = in->height * scale;
		    image_init(out, w, h);
			    double scale2 = scale / 2.0;
				    double smooth = 0.25;
					    for (size_t y = 0; y < h; y++) {
							        for (size_t x = 0; x < w; x++) {
										            size_t inx = x / scale, iny = y / scale;
													            double radius = ((255 - P(in, inx, iny, RED)) +
																		                             (255 - P(in, inx, iny, GREEN)) +
																									                              (255 - P(in, inx, iny, BLUE))) / (3 * 255.0);
																            double cx = fabs((x % scale) - scale2) / scale2,
																				                      cy = fabs((y % scale) - scale2) / scale2;
																			            double colorx = smoothstep(cx, radius - smooth, radius + smooth),
																							                      colory = smoothstep(cy, radius - smooth, radius + smooth);
																						            int color = colorx > colory ? colorx * 255 : colory * 255;
																									            P(out, x, y, RED)   = color;
																												            P(out, x, y, GREEN) = color;
																															            P(out, x, y, BLUE)  = color;
																																		        }
									    }
}

int main(int argc, char **argv)
{
	    int quantization = argc > 1 ? atoi(argv[1]) : 4;
		    struct image input, scaled, output;
			    image_read(&input, stdin);
				    image_scaledown(&scaled, &input, quantization);
					    image_halftone(&output, &scaled, quantization * 2);
						    image_write(&output, stdout);
							    image_destroy(&input);
								    image_destroy(&scaled);
									    image_destroy(&output);
										    return 0;
}
