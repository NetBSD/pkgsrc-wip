

PACKAGE BODY LA5008F0 IS

     PROCEDURE P IS BEGIN NULL; END P;

     GENERIC
     PACKAGE LA5008F0P IS
     END LA5008F0P;

     PACKAGE BODY LA5008F0P IS SEPARATE;     -- OPTIONAL ERROR:
                                             -- CORRESPONDING BODY NOT
                                             -- IN SAME COMPILATION FILE
                                             -- AS ITS DECLARATION.

END LA5008F0;
