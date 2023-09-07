/* Author : Ivan Nazarenko
   Date: 06/09/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>


int main(int argc, char* argv[]) {
    FILE* pFile = NULL;
    /* Setup syslog logging with facility LOG_USER */
    openlog(NULL, 0, LOG_USER);

    /* Validate number of arguments */
    if(argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d\n", argc - 1);
        return 1;
    }

    /* Open file for writing */
    pFile = fopen(argv[1], "w");
    /* Check file has been opened */
    if(pFile == NULL) {
        syslog(LOG_ERR, "Failed to open the file: %s", strerror(errno));
        return 1;
    }

    /* Write string to file */
    fprintf(pFile, "%s\n", argv[2]);
    /* Check if a string writing is successful */
    if(errno) {
        syslog(LOG_ERR, "Failed to write to the file: %s", strerror(errno));
        fclose(pFile);
        pFile = NULL;
        return 1;
    }
    /* Log the successful operation */
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    /* Close the file */
    fclose(pFile);
    pFile = NULL;
    /* Normal exit without any error status */
    return EXIT_SUCCESS;
}

