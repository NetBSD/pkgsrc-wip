
-----------------------------------------------------------------------

WITH REPORT; USE REPORT;
PRAGMA ELABORATE (REPORT);
PACKAGE BODY CA5006A0 IS
   RAISED : BOOLEAN := FALSE;

   FUNCTION P_E_RAISED RETURN BOOLEAN IS
   BEGIN
      RETURN RAISED;
   END P_E_RAISED;

   PROCEDURE SHOW_PE_RAISED IS
   BEGIN
      RAISED := TRUE;
   END SHOW_PE_RAISED;

BEGIN
     TEST ( "CA5006A", "CHECK THAT A PROGRAM IS NOT REJECTED JUST " &
                       "BECAUSE THERE IS NO WAY TO ELABORATE " &
                       "SECONDARY UNITS SO PROGRAM_ERROR WILL BE " &
                       "AVOIDED" );

                         
END CA5006A0;
