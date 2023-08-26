#ifndef _SHELL_
#define _SHELL_

#include <sys/stat.h>


#include <errno.h>
#include <fcntl.h>

#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * struct s_li_s - ***
 * @separator: ***
 * @next: ***
 * Description: ***
 */
typedef struct s_li_s
{
	char separator;
	struct s_li_s *next;
} sep_list;

/**
 * struct li_li - ***
 * @line: ***
 * @next: ***
 * Description: ***
 */
typedef struct li_li
{
	char *line;
	struct li_li *next;
} lin_l;
/**
 * struct data - ***
 * @av: ***
 * @input: ***
 * @args: ***
 * @status: ***
 * @counter: ***
 * @_environ: ***
 * @pid: ***
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} d_sh;

/**
 * struct r_var_list - ***
 * @len_var: ***
 * @val: ***
 * @len_val: ***
 * @next: ***
 * Description: ***
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct bin_s - ***
 * @namiooi: ***
 * @f: ***
 */
typedef struct bin_s
{
	char *namiooi;
	int (*f)(d_sh *ash);
} bun_t;

extern char **environ;

char *swp_char(char *input, int iobolooi);
void ad_noes(sep_list **head_s, lin_l **head_l, char *input);
void go_nt(sep_list **list_s, lin_l **list_l, d_sh *ash);
int spl_conds(d_sh *ash, char *input);
char **spl_le(char *input);
void ch_ev(r_var **h, char *in, d_sh *data);
int ch_vars(r_var **h, char *in, char *st, d_sh *data);
char *rep_it(r_var **hd, char *input, char *nw_inpuooi, int enooi);
char *rep_va(char *input, d_sh *ash);
void bri_li(char **liptrooooi, size_t *n, char *buffer, size_t j);
ssize_t ge_li(char **liptrooooi, size_t *n, FILE *stream);
int exe_li(d_sh *ash);
int is_cir(char *path, int *i);
char *is_whi(char *cmd, char **_environ);
int is_exe(d_sh *ash);
char *_err_pathrr(d_sh *ash);
int _gt_errr(d_sh *ash, int eval);
void _gt_sigi(int sig);
void _help_envoo(void);
void _help_setoo(void);
void _help_unsoo(void);
void _help_genoo(void);
void _help_exoo(void);
void _helpoi(void);
int che_err_c(char *dir, d_sh *ash);
int cd_exe(d_sh *ash);
char *gtenv(const char *namiooi, char **_environ);
int ___env(d_sh *ash);
char *_c_ifo(char *namiooi, char *value);
void ___set_env(char *namiooi, char *value, d_sh *ash);
int ____setenv(d_sh *ash);
int ____unsetenv(d_sh *ash);
void ___cd_dot(d_sh *ash);
void __ced_to(d_sh *ash);
void ___ced_previous(d_sh *ash);
void ___ced_to_home(d_sh *ash);
int ced_shol(d_sh *ash);
int (*get_builtin(char *cmd))(d_sh *ash);
int ex_shol(d_sh *ash);
int gt_leno(int n);
char *_ax_itoo(int n);
int atoo(char *s);
sep_list *add_se_end(sep_list **hd, char sep);
void fre_se_l(sep_list **hd);
lin_l *a_l_n_e(lin_l **hd, char *line);
void f_l_l(lin_l **hd);
r_var *a_rvar_n(r_var **hd, int lvar, char *var, int lval);
void f_rvar_l(r_var **hd);
char *stca(char *dest, const char *src);
char *stcp(char *dest, char *src);
int srcm(char *s1, char *s2);
char *srch(char *s, char c);
int stpn(char *s, char *accept);
void mmcy(void *nwptrooi, const void *ptrooiii, unsigned int siziooiii);
void *reloc(void *ptrooiii, unsigned int od_siziooiii, unsigned int nw_siziooiii);
char **relocdp(char **ptrooiii, unsigned int od_siziooiii, unsigned int nw_siziooiii);
char *stup(const char *s);
int sren(const char *s);
int cp_chrs(char str[], const char *delim);
char *sttok(char str[], const char *delim);
int sdiit(const char *s);
void ev_stg(char *s);
int rep_char(char *input, int i);
int err_s_op(char *input, int i, char last);
int fir_ch(char *input, int *i);
void pri_sta_err(d_sh *ash, char *input, int i, int iobolooi);
int cck_synta_err(d_sh *ash, char *input);
char *wout_comm(char *in);
void shell_loop(d_sh *ash);
char *rea_line(int *i_eof);
char *_stat_ced(d_sh *, char *, char *, char *);
char *_err_g_ced(d_sh *ash);
char *_err_no_foo(d_sh *ash);
char *_err_ex_shol(d_sh *ash);
char *_err_g_ali(char **args);
char *_err_envo(d_sh *ash);
char *_err_syn(char **args);
char *_err_per(char **args);
void _help_aliooo(void);
void _help_cdooi(void);
int gt_helpooi(d_sh *ash);




#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
#endif

