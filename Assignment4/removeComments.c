#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch, next;
    
    int in_string = 0;
    int in_char = 0;

    if (argc != 2)
    {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Handle string literals
        if (ch == '"' && !in_char)
        {
            in_string = !in_string;
            putchar(ch);
            continue;
        }

        // Handle character constants
        if (ch == '\'' && !in_string)
        {
            in_char = !in_char;
            putchar(ch);
            continue;
        }

        if (!in_string && !in_char && ch == '/')
        {
            next = fgetc(fp);

            // Single-line comment
            if (next == '/')
            {
                while ((ch = fgetc(fp)) != EOF && ch != '\n');

                if (ch == '\n')
                    putchar('\n');
            }

            // Multi-line comment
            else if (next == '*')
            {
                char prev = 0;

                while ((ch = fgetc(fp)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

            else
            {
                putchar('/');
                ungetc(next, fp);
            }
        }
        else
        {
            putchar(ch);
        }
    }

    fclose(fp);

    return 0;
}