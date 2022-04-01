#include<library_Managment_system.h>

/**
 * @brief function to issue the book
 * 
 * @param id 
 * @return test_values 
 */

test_values issuebook(int id)
{
    char name1[20];
    FILE *fp=NULL;
    fp = fopen("bookLibrary.dat","rb");
    if(fp==NULL)
    {
        printf("\nERROR: While Opening File in Issuing Book\\n");
        return fail;
    }
    else{

    scanf("%19s student name",name1);
    book *book_to_find=(book*)malloc(sizeof(book));
    while(fread(book_to_find,sizeof(book),1,fp))
    {
        if(book_to_find->book_id==id)
        {
            
            printf("\nBOOK_ID: %d\t\tBOOK_NAME: %s\t\tBOOK_AUTHOR: %s",book_to_find->book_id,book_to_find->book_name,book_to_find->author_name);
            printf("\n Book is issued to %s",name1);
            fclose(fp);
            free(book_to_find);
            return pass;
        }
    }
    
    fclose(fp);
    free(book_to_find);
    printf("\nMentioned book is not present\n");
    
    return fail;
    }
}
