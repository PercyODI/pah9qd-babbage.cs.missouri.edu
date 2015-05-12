#ifndef PARSER_H_
#define PARSER_H_

#define MAX_LINE 250

int is_phone_number(char* word);
int is_date(char* word);
int looks_like_name(char *word);
int is_email(char *word);

#endif