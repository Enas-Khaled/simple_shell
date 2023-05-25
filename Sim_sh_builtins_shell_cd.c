#include "shell.h"

/**
 * Sim_sh_shell_cd - to change the current working dir in shell
 * @args: array of args for a input
 *
 * Return - Not return Any value
 */
void Sim_sh_shell_cd(char **args)
{
        char *home, *expanded, *rest, *p, *sh_dir = args[1];
        size_t home_len, rest_len;
        int num;

        if (sh_dir == NULL)
        { /* If no argument is provided, change to HOME directory */
                sh_dir = Sim_sh_getenv("HOME");
                if (sh_dir == NULL)
                {
                        Sim_sh_puterror("cd: No HOME directory found\n");
                        return;
                }
        }
        if (sh_dir[0] == '~')
        { /* Expand tilde (~) to HOME directory */
                home = Sim_sh_getenv("HOME");
                if (home == NULL)
                        Sim_sh_puterror("cd: No HOME directory found\n");
                rest = sh_dir + 1;
                home_len = _strlen(home);
                rest_len = _strlen(rest);
                expanded = malloc(home_len + rest_len + 1);
                if (expanded == NULL)
                {
                        Sim_sh_puterror("cd: Memory allocation error\n");
                        return;
                }
                p = expanded;
                _memcpy(p, home, home_len);
                p += home_len;
                _memcpy(p, rest, rest_len);
                p += rest_len;
                *p = '\0';
                sh_dir = expanded;
        }
        num = chdir(sh_dir);
        if (num == -1)
                perror("cd");
        if (sh_dir != args[1]) /* Free memory */
                free(sh_dir);
}

