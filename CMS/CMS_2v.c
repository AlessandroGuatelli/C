#include <stdio.h>
int main() {
    FILE *in_tab, *out, *in_img, *in_par, *in_list;
    char st[255];
    char stToFind[255];
    char sep = '&', end;
    int ins = 0, cont = 0, par = 0, scelt = 0, ok = 0, chiu = 0;

    if ((in_tab = fopen("table.txt", "r")) == NULL)
    {
        printf("Impossibile aprire il file della tabella\n");
        return 0;
    }
    else
    {
        printf("Table file open correctly\n");
    }
    if ((in_par = fopen("text.txt", "r")) == NULL)
    {
        printf("Unable to open the paragraph file\n");
        return 0;
    }
    else
    {
        printf("Paragraph file open correctly\n");
    }
    if ((in_list = fopen("list.txt", "r")) == NULL)
    {
        printf("Unable to open the list file\n");
        return 0;
    }
    else
    {
        printf("List file open correctly\n");
    }
    if ((in_img = fopen("img.txt", "r")) == NULL)
    {
        printf("The image file could not be opened\n");
        return 0;
    }
    else
    {
        printf("Image file opened correctly\n");
    }
    if ((out = fopen("index.html", "w")) == NULL)
    {
        printf("Unable to open the HTML output file\n");
        return 0;
    }

    fputs("<html>\n\t<head>\n\t<link rel='stylesheet' type='text/css' href='style.css'/>\n\t</head>\n<body>", out);
    fputs("\n\t<h1>", out);
    while (! feof(in_par)) {
        char c = fgetc(in_par);
        if (c != -1) {

                if ((c=='\n') && (cont == 0))
                {
                    fputs("</h1>", out);
                    cont++;
                }
                if ((c!='\n') && (cont == 1))
                {
                    fputs("\n<h4>", out);
                    cont++;
                }
                if ((c=='\n') && (cont == 2))
                {
                    fputs("</h4>", out);
                    fputs("\n<p>", out);
                    cont++;
                }
                if ((c!='\n') && (cont == 3))
                {
                    fputs("\n<h5>", out);
                    cont++;
                }
                if ((c=='\n') && (cont == 4))
                {
                    fputs("</h5>", out);
                    fputs("\n<p>", out);
                    cont++;
                }
                if ((c=='\n') && (cont >= 4))
                {
                    par = 1;
                    cont++;
                }
                if ((c=='\n') && (par==1))
                {
                    fputs("</p>", out);
                    fputs("\n<p>", out);
                    cont++;
                    par = 0;
                }
                fputc(c, out);
        }
    }
    fputs("</p>", out);
    cont = 0;
    fputs("\n\t<table border=\"1\">\n\t\t<tr>\n\t\t\t<td>\n\t\t\t\t", out);
    while (! feof(in_tab)) {
        char c = fgetc(in_tab);

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
    fputs("\n\t\t</tr>\n\t</table>", out);
    cont = 0;
    ///0 == numbered list
    ///1 == 0 == un-numbered list
    while (! feof(in_list)) {
        char c = fgetc(in_list);
        if (c != -1)
        {
                if ((cont == 0) && (c == '0'))
                {
                    fputs("\n<ol type='1'>", out);
                    scelt = 0;
                    cont++;
                    ok = 1;
                }
                if ((cont == 0)&&(c == '1') )
                {
                    fputs("\n<ul>", out);
                    scelt = 1;
                    cont++;
                }
                if ((ok % 2 == 0) && (c=='\n'))
                {
                    fputs("\n<li>\n\t", out);
                }
                if ((c=='\n') && (ok % 2 != 0))
                {
                    fputs("</li>", out);
                    fputs("\n<li>\n\t", out);
                    cont++;
                }
                if (ok > 1)
                {
                        fputc(c, out);
                }
                ok++;
    }
    }
        fputs("\n</li>\n\t", out);
    if (scelt == 1)
    {
         fputs("</ul>", out);
    }
        if (scelt == 0)
    {
         fputs("</ol>", out);
    }
    ///odd == image link
    ///even == caption of the image
    cont = 0;
    fputs("\n\t\t\t\t<img src='", out);
    chiu = 1;
    while (! feof(in_img)) {
        char c = fgetc(in_img);
        if (c != -1)
    {

                if ((c=='\n') && (cont % 2 == 0) && (chiu == 1))
                {
                     fputs("'>", out);
                     fputs("\n<p>", out);
                    cont++;
                    chiu = 0;
                }
                if ((c!='\n') && (cont % 2 != 0))
                {
                    cont++;
                    par = 1;
                }
                if ((c=='\n') && (par==1) && (chiu == 0))
                {
                    fputs("</p>", out);
                    fputs("\n\t\t\t\t<img src='", out);
                    cont++;
                    chiu = 1;
                    par = 0;
                }
                fputc(c, out);
    }
    }
    if(cont % 2 != 0)
    {
        fputs("'>", out);
    }
    else
    {
         fputs("</p>", out);
    }
    fputs("\n</body>\n</html>", out);
    fclose(in_tab);
    fclose(in_par);
    fclose(in_img);
    fclose(out);
    printf("HTML file successfully created\n");
    printf("press any key to end-->");
    scanf("%c", &end);
    return 0;
    system("pause");
}
