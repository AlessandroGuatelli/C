#include <stdio.h>

int main() {
    FILE *in, *out;
    char st[255];
    char stToFind[255];
    char sep;
    int ins = 0;

    if ((in = fopen("content.txt", "r")) == NULL)
    {
        printf("The content file could not be opened\n");
        return 0;
    }
    else
    {
        printf("Content file open correctly\n");
    }
    if ((out = fopen("index.html", "w")) == NULL)
    {
        printf("Unable to open the html output file\n");
        return 0;
    }
    else
    {
        printf("Open html output file correctly\n");
    }

    printf("Enter the separator character:\n");
    scanf("%c", &sep);

    fputs("<html>\n\t<head>\n\t<link rel='stylesheet' type='text/css' href='style.css'/>\n\t</head>\n<body>\n\t<table border=\"1\">\n\t\t<tr>\n\t\t\t<td>\n\t\t\t\t", out);
    while (! feof(in)) {
        char c = fgetc(in);

        if (c != -1) {
                if (c==sep)
                {
                    fputs("\n\t\t\t</td>\n\t\t\t<td>\n\t\t\t\t", out);
                    ins = 1;
                }
                if (c=='\n')
                {
                    fputs("</td>\n\t\t</tr>\n\t\t\t<tr>\n\t\t\t\t<td>", out);
                    ins = 1;
                }
                if (!ins)fputc(c, out);
                ins = 0;
        }
        else  fputs("\n\t\t\t</td>", out);
    }
    fputs("\n\t\t</tr>\n\t</table>\n</body>\n</html>", out);
    fclose(in);
    fclose(out);
    printf("HTML file successfully created\n");
    return 0;
    system("pause");
}
