/****************************************************************

 gui.h

 =============================================================

 Copyright 1996-2018 Tom Barbalet. All rights reserved.

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or
 sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.

 This software and Noble Ape are a continuing work of Tom Barbalet,
 begun on 13 June 1996. No apes or cats were harmed in the writing
 of this software.

 ****************************************************************/

/*NOBLEMAKE VAR=""*/

#ifndef NOBLEAPE_GUI_H
#define NOBLEAPE_GUI_H

#ifndef	_WIN32

#include "../noble/noble.h"
#include "../universe/universe.h"
#include "../entity/entity.h"

#else

#include "..\noble\noble.h"
#include "..\universe\universe.h"
#include "..\entity\entity.h"

#endif

#define	TERRAINWINDOW(alpha)   (alpha)
#define	VIEWWINDOW(alpha)      (alpha + TERRAIN_WINDOW_AREA)
#define GRAPHWINDOW(alpha)     (alpha + (MAP_AREA + TERRAIN_WINDOW_AREA))

#define IS_WINDOW_KIND(x,y)			(((x)>>(y))&1)

enum colour_type
{
    COLOUR_GREY      =   (252),
    COLOUR_YELLOW    =   (253),
    COLOUR_RED_DARK  =   (254),
    COLOUR_RED       =   (255)
};

#define	NON_INTERPOLATED COLOUR_GREY


#define	spot_colour(alpha,spx,spy,col)	alpha[((spx)|((spy)<<8))]=(col)

/*	Graphics Metrics */

#define BRAIN_MAGI					1152


/*	Icon Offset */
#define	ICONOFFSET					27

typedef struct
{
    n_byte	* screen;
    n_byte	* background;
}
n_background8;

typedef struct
{
    n_byte  * screen;
    n_byte	  color;
}
n_color8;


typedef n_int (*control_file_handle)(n_byte * buff, n_uint len);

typedef void  (*control_mp_define)(n_byte * data);

/*
 n_uint braincode_standard_deviation(noble_being * local_being);
 void braincode_number_of_instructions(
 noble_being * local_being,
 n_int * no_of_sensors,
 n_int * no_of_actuators,
 n_int * no_of_operators,
 n_int * no_of_conditionals,
 n_int * no_of_data);
 */
/* graph functions */
/*void graph_line(n_byte * buffer, n_int img_width, n_int img_height, n_int prev_x, n_int prev_y, n_int x, n_int y, n_byte r,n_byte g,n_byte b,n_byte thickness);*/
void graph_honor_distribution(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height);
void graph_ideosphere(noble_simulation * sim, n_byte * buffer, n_int img_width, n_int img_height);
void graph_genepool(noble_simulation * sim, n_byte * buffer, n_int img_width, n_int img_height);
void graph_relationship_matrix(noble_simulation * sim, n_byte * buffer, n_int img_width, n_int img_height);
void graph_pathogens(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height);
void graph_age_demographic(noble_simulation * sim, n_byte * buffer, n_int img_width, n_int img_height);
void graph_heights(noble_simulation * sim, n_byte * buffer, n_int img_width, n_int img_height);
void graph_phasespace(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height, n_byte graph_type, n_byte data_type);
void graph_braincode(noble_simulation * sim, noble_being * local_being, n_byte * buffer, n_int img_width, n_int img_height, n_byte clear);

void graph_preferences(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height);
void graph_vascular(n_genetics * being,
                    n_byte * buffer,
                    n_int img_width, n_int img_height,
                    n_int tx, n_int ty, n_int bx, n_int by,
                    n_byte thickness,
                    n_byte clear,
                    n_int shoulder_angle, n_int elbow_angle, n_int wrist_angle,
                    n_int hip_angle, n_int knee_angle,
                    n_byte show_skeleton_keypoints);
void graph_socialsim(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height);
void graph_meet_places(noble_simulation * sim, n_byte update_type, n_byte * buffer, n_int img_width, n_int img_height);

n_int draw_toggle_weather(void);

n_int draw_toggle_brain(void);

n_int draw_toggle_braincode(void);

n_int draw_toggle_territory(void);

void  draw_terrain_coord(n_int * co_x, n_int * co_y);

void draw_fit(n_byte * points, n_byte2 * color_fit);

extern n_byte land_points[];
extern n_byte fur_points[];

void draw_color_time(n_byte2 * color_fit, n_byte2 time);

void draw_undraw_clear(void);

n_byte * draw_pointer(n_byte which_one);

n_byte * draw_color_fit();

void draw_about(n_constant_string platform);

void draw_string(n_constant_string str, n_int off_x, n_int off_y, n_join * draw);

void  draw_cycle(n_int mod, n_int dim_x, n_int dim_y);

n_byte * draw_offscreen(n_byte * value);

void draw_update_drag(n_byte drag_on, n_int x1, n_int x2, n_int y1, n_int y2);

#endif /* NOBLEAPE_GUI_H */

/*NOBLEMAKE END=""*/

/*NOBLEMAKE SET="draw.c"*/
/*NOBLEMAKE SET="control.c"*/
