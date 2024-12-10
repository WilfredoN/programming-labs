#ifndef LIB_IO_H
#define LIB_IO_H

#include "lib.h"

bool save_to_text(forward_list_t *list, const char *filename);
bool load_from_text(forward_list_t *list, const char *filename);

bool save_to_binary(forward_list_t *list, const char *filename);
bool load_from_binary(forward_list_t *list, const char *filename);

#endif // LIB_IO_H