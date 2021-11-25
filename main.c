#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nom[50][50];                    //tableau des noms des clients.
    char prenom[50][50];                //tableau des prenoms des clients.
    char cin[10][10];                  //tableau des cin des clients.
    double montant[10],D,R;           // Montant: montant de client.// R: variable pour opération Retrait.// D: le montant que vous souhaitez deposer ou retirer.// R: un montant pour afficher les compte superieur ou inferieur cette montant.
    char CIN[10];                    // Pour rechercher un compte.
    char new_nom[20][20];           // pour stocker inf de chaque compte apres le tri
    int i,j,X,NC,choix,n=0,op,ch;  //X: nombre de compte // NC: nombre de choix pour 1eme menu (************** Gestion Bancair **************)// n: Total de nombre de compte// choix: nombre de choix pour 2eme menu (Menu principal)// op: nombre de choix pour 3eme menu  (menu de operation)// ch:nombre de choix pour 3eme menu  (menu de affichage)


    //debut de application


    do
    {
        printf("-----------------------\n");
        printf("************** Gestion Bancair **************\n");
        printf("-----------------------\n");
        printf("1: Introduire un compte bancaire \n\n");
        printf("2: Introduire plusieurs comptes bancaires \n\n");
        printf("saisir le numero de choix s'il vous plait: ");
        scanf("%d",&NC);
        printf("\n");
        system ("cls");

        if(NC<1 || NC>2)
        {
            printf("\n\n************** veuillez choisir un nombre entre 1 et 2 **************\n\n");
            system ("pause");
            system ("cls");
        }
        else
            break;


    }
    while(NC<1 || NC>2);



    switch(NC)
    {

    //Introduire un compte bancaire

    case 1:

saisir:
        printf("\n************** Saisir les informations de client **************\n");
        printf("\n-----------------------\n\n");
        printf("***** entrer votre nom: ");
        scanf("%s",nom[n]);
        printf("\n");
        printf("***** entrer votre prenom: ");
        scanf("%s",prenom[n]);
        printf("\n");
        printf("***** entrer votre cin: ");
        scanf("%s",cin[n]);
        printf("\n");
        printf("***** entrer votre montant: ");
        scanf("%lf",&montant[n]);
        printf("\n");
        n++;
        system ("cls");
        break;

    //Introduire plusieurs comptes bancaires

    case 2:

saisir2:
        printf("\n************** Saisir les informations des clients **************\n");
        printf("\n-----------------------\n\n");
        printf("***** Entrez le nombre des comptes: ");
        scanf("%d",&X);
        int f=n;
        for (i=f; i<X+f; i++)
        {

            printf("-----------------------\n\n");
            printf("***** Compte N %d *****\n",i+1);
            printf("entrer votre nom: ");
            scanf("%s",nom[i]);
            printf("\n");
            printf("entrer votre prenom: ");
            scanf("%s",prenom[i]);
            printf("\n");
            printf("entrer votre cin: ");
            scanf("%s",cin[i]);
            printf("\n");
            printf("entrer votre montant: ");
            scanf("%lf",&montant[i]);
            printf("\n");
            n++;

        }
        system ("cls");
        break;

    }




    do
    {
        do
        {
            //Menu principal

            printf("-----------------------\n");
            printf("**************  Menu principal  **************\n");
            printf("-----------------------\n\n");
            printf(" 1: Introduire un compte bancaire \n\n");
            printf(" 2: Introduire plusieurs comptes bancaires \n\n");
            printf(" 3: Operation\n\n");
            printf(" 4: Affichage\n\n");
            printf(" 5: fidelisation\n\n");
            printf(" 6: Quitter le programme\n\n");
            printf("saisir le numero de choix s'il vous plait: ");
            scanf("%d",&choix);
            printf("\n\n");
            system ("cls");

            if(choix<1 || choix>6)
            {

                printf("\n\n************** veuillez choisir un nombre entre 1 et 6 **************\n\n");
                system ("pause");
                system ("cls");
            }
            else
                break;

        }
        while(choix<1 || choix>6);


        switch(choix)
        {
        case 1:

            goto saisir;
            break;

        case 2:

            goto saisir2;
            break;

        case 3:

                //menu de Operation
                menu_de_Operation:
                printf("\n-----------------------\n");
                printf("\n **************  Operation  **************\n\n");
                printf("-----------------------\n\n");
                printf("choisir votre operation \n");
                printf("1: Depot\n\n");
                printf("2: Retraite\n\n");
                printf("choisir votre operation s'il vous plait: ");
                scanf("%d",&op);
                system ("cls");

                if(op<1 || op>2)
                {

                    printf("\n\n************** veuillez choisir un nombre entre 1 et 2 **************\n\n");
                    system ("pause");
                    system ("cls");
                    goto menu_de_Operation;
                }
                else


                    switch(op)
                    {

                    //Depot

                    case 1:

                        printf("\n\n **************  Depot  **************\n\n");
                        printf("entre votre CIN :");
                        scanf("%s",CIN);
                        printf("\n");
                        for (i=0; i<n; i++)
                        {
                            if( strcmp(CIN, cin[i] ) ==0 )
                            {
                                printf("Entrez le montant que vous souhaitez deposer: ");
                                scanf("%lf",&D);
                                printf("\n");
                                montant[i]=montant[i]+D;
                                printf("nouveau montant %.2f \n\n",montant[i]);

                            }
                            else printf("ce compte n'existe pas: \n\n");
                            break;
                        }
                        system("pause");
                        system("cls");
                        break;

                    //Retraite

                    case 2:

                        printf("\n\n **************  Retraite  **************\n\n");
                        printf("entre votre CIN :");
                        scanf("%s",CIN);
                        printf("\n");
                        for (i=0; i<n; i++)
                        {
                            if( strcmp (CIN, cin[i] ) ==0 )
                            {
                                printf("Entrez le montant que vous souhaitez retirer: ");
                                scanf("%lf",&D);
                                printf("\n");
                                if(montant[i]>D)
                                {
                                    montant[i]=montant[i]-D;
                                    printf("nouveau montant %.2f \n\n",montant[i]);
                                }
                                else
                                {
                                    printf("\nLe montant que vous souhaitez retirer est superieur au montant que vous avez \n\n");
                                }

                            }
                            else printf("ce compte n'existe pas: \n\n");
                            break;
                        }
                        system("pause");
                        system("cls");
                        break;
                    }


            break;

        //Menu Affichage

        case 4:
            menu_affichage:
            printf("\n-----------------------\n");
            printf("**************  Menu Affichage  **************\n");
            printf("-----------------------\n\n");
            printf(" 1: Affichage par order ascendant\n\n");
            printf(" 2: Affichage par order descendant\n\n");
            printf(" 3: Entret un montant pour afficher les compte superieur ton montant\n\n");
            printf(" 4: Entret un montant pour afficher les compte inferieur ton montant\n\n");
            printf(" 5: Recherche par cin\n\n");
            printf("saisir le numero de choix s'il vous plait: ");
            scanf("%d",&ch);
            system ("cls");
            if(ch<1 || ch>5)
            {

                printf("\n\n************** veuillez choisir un nombre entre 1 et 5 **************\n\n");
                system ("pause");
                system ("cls");
                goto menu_affichage;
            }
            else

                switch(ch)
                {



                case 1:
                    //Affichage par order ascendant

                    printf("\n************** 1: Affichage par order ascendant  **************\n\n");

                    for(i=0; i<n-1; i++)
                    {
                        for(j=i+1; j<n; j++)
                        {

                            if(montant[i]>montant[j])
                            {

                                int tmp;

                                tmp=montant[i];
                                montant[i]=montant[j];
                                montant[j]=tmp;

                                strcpy(new_nom,nom[i]);
                                strcpy(nom[i],nom[j]);
                                strcpy(nom[j],new_nom);

                                strcpy(new_nom,prenom[i]);
                                strcpy(prenom[i],prenom[j]);
                                strcpy(prenom[j],new_nom);

                                strcpy(new_nom,cin[i]);
                                strcpy(cin[i],cin[j]);
                                strcpy(cin[j],new_nom);
                            }
                        }
                    }

                    for (i=0; i<n; i++)
                    {
                        printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);
                    }

                    system("pause");
                    system("cls");

                    break;

                case 2:

                    //Affichage par order descendant

                    printf("\n************** 2: Affichage par order descendant  **************\n\n");

                    for(i=0; i<n-1; i++)
                    {
                        for(j=i+1; j<n; j++)
                        {

                            if(montant[i]<montant[j])
                            {

                                int tmp;

                                tmp=montant[i];
                                montant[i]=montant[j];
                                montant[j]=tmp;

                                strcpy(new_nom,nom[i]);
                                strcpy(nom[i],nom[j]);
                                strcpy(nom[j],new_nom);

                                strcpy(new_nom,prenom[i]);
                                strcpy(prenom[i],prenom[j]);
                                strcpy(prenom[j],new_nom);

                                strcpy(new_nom,cin[i]);
                                strcpy(cin[i],cin[j]);
                                strcpy(cin[j],new_nom);
                            }
                        }
                    }

                    for (i=0; i<n; i++)
                    {
                        printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);
                    }

                    system("pause");
                    system("cls");
                    break;

                case 3:

                    //afiicher les compte superieur R

                    printf("\n************** 3: Affichage des compte superieur R  **************\n\n");

                    printf("entre un montant: ");
                    scanf("%lf",&R);

                    for(i=0; i<n-1; i++)
                    {
                        for(j=i+1; j<n; j++)
                        {
                            if(montant[i]>montant[j])
                            {

                                int tmp;

                                tmp=montant[i];
                                montant[i]=montant[j];
                                montant[j]=tmp;

                                strcpy(new_nom,nom[i]);
                                strcpy(nom[i],nom[j]);
                                strcpy(nom[j],new_nom);

                                strcpy(new_nom,prenom[i]);
                                strcpy(prenom[i],prenom[j]);
                                strcpy(prenom[j],new_nom);

                                strcpy(new_nom,cin[i]);
                                strcpy(cin[i],cin[j]);
                                strcpy(cin[j],new_nom);



                            }
                        }
                    }
                    for (i=0; i<n; i++)
                    {
                        if(montant[i]>R)
                            printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);

                    }

                    system("pause");
                    system("cls");

                    break;

                case 4:

                    //afiicher les compte inferieur R

                    printf("\n************** 4: Affichage des compte inferieur R  **************\n\n");

                    printf("entre un montant: ");
                    scanf("%lf",&R);

                    for(i=0; i<n-1; i++)
                    {
                        for(j=i+1; j<n; j++)
                        {
                            if(montant[i]<montant[j])
                            {

                                int tmp;

                                tmp=montant[i];
                                montant[i]=montant[j];
                                montant[j]=tmp;

                                strcpy(new_nom,nom[i]);
                                strcpy(nom[i],nom[j]);
                                strcpy(nom[j],new_nom);

                                strcpy(new_nom,prenom[i]);
                                strcpy(prenom[i],prenom[j]);
                                strcpy(prenom[j],new_nom);

                                strcpy(new_nom,cin[i]);
                                strcpy(cin[i],cin[j]);
                                strcpy(cin[j],new_nom);
                            }
                        }
                    }
                    for (i=0; i<n; i++)
                    {
                        if(montant[i]<R)
                            printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);
                    }

                    system("pause");
                    system("cls");
                    break;

                case 5:

                    // Recherche par cin

                    printf("\n************** 5: Recherche par cin  **************\n\n");

                    printf("entre votre CIN :");
                    scanf("%s",CIN);


                    for (i=0; i<n; i++)
                    {
                        if( strcmp (CIN, cin[i] ) ==0 )
                        {
                            printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);
                            break;

                        }
                        else

                            printf("ce compte n'existe pas: \n\n");
                        break;
                    }


                    system("pause");
                    system("cls");
                    break;




                }
            break;

        case 5:

            // fidelisation

            printf("\n************** 5: Fidelisation  **************\n\n");

            for(i=0; i<n-1; i++)
            {
                for(j=i+1; j<n; j++)
                {

                    if(montant[i]<montant[j])
                    {

                        int tmp;

                        tmp=montant[i];
                        montant[i]=montant[j];
                        montant[j]=tmp;

                        strcpy(new_nom,nom[i]);
                        strcpy(nom[i],nom[j]);
                        strcpy(nom[j],new_nom);

                        strcpy(new_nom,prenom[i]);
                        strcpy(prenom[i],prenom[j]);
                        strcpy(prenom[j],new_nom);

                        strcpy(new_nom,cin[i]);
                        strcpy(cin[i],cin[j]);
                        strcpy(cin[j],new_nom);
                    }
                }
            }
            if(n>=3)
            {
                for(i=0; i<3; i++)
                {
                    montant[i]=montant[i] + montant[i]*1.3/100;
                    printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);

                }
            }
            else
            {
                for(i=0; i<n; i++)
                {
                    montant[i]=montant[i] + montant[i]*1.3/100;
                    printf("\n info de compte N%d:\n nom: %s\n prenom: %s\n cin: %s \n montant %.2f \n",i+1,nom[i],prenom[i],cin[i],montant[i]);
                }
            }

            system("pause");
            system("cls");

            break;

        }
    }
    while(choix!=6);

    system ("cls");
    printf("\n\n**************************** Au revoir cher client ****************************\n\n");





    return 0;
}
