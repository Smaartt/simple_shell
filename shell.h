#ifndef SHELL
#define SHELL

#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


typedef struct list
{
	char *var;
	struct list *next;

} list_t;

void non_interactivee(list_t *env);
char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void free_double_ptr(char **strr);
void free_linked_list(list_t *list);
int _env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *i);
void not_foundd(char *str, int num, list_t *env);
void cant_cd_too(char *str, int c_n, list_t *env);
void illegal_numberr(char *str, int c_n, list_t *env);
char *int_to_string(int numm);
char *ignore_space(char *strr);
char **_str_tokk(char *strr, char *delmm);
char **c_str_tok(char *strr, char *delmm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *destt, char *srcc);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenvv(list_t **env, char **str);
int _setenvv(list_t **env, char **str);
int find_envv(list_t *env, char *str);
int promptt(char **env);
void *_realloc(void *ptr, unsigned int old_sizee, unsigned int new_sizee);
size_t get_linee(char **strr);
int t_strlen(char *strr, int poss, char delmm);
int _strcmp(char *s2, char *s3);
int _cd(char **str, list_t *env, int num);
int built_in(char **token, list_t *env, int numm, char **commandd);
#endif
