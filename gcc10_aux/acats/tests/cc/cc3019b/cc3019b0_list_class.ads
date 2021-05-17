-- CC3019B0.ADA

--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--  THIS IS GENERIC PACKAGE WHICH IS USED TO CHECK THE LEVEL OF
--  NESTED GENERICS SUPPORTED BY AN IMPLEMENTATION.
--
-- HISTORY:
--         EDWARD V. BERARD, 31 AUGUST 1990

GENERIC
     
     TYPE ELEMENT IS LIMITED PRIVATE ;
          
     WITH PROCEDURE ASSIGN (SOURCE        : IN OUT ELEMENT ;
                            DESTINATION   : IN OUT ELEMENT) ;
                                
     WITH FUNCTION "=" (LEFT  : IN ELEMENT ;
                        RIGHT : IN ELEMENT) RETURN BOOLEAN ;
                                       
PACKAGE CC3019B0_LIST_CLASS IS
     
     TYPE LIST IS LIMITED PRIVATE ;
          
     OVERFLOW    : EXCEPTION ;
     UNDERFLOW    : EXCEPTION ;
          
     PROCEDURE ADD    (THIS_ELEMENT        : IN OUT ELEMENT ;
                       TO_THIS_LIST        : IN OUT LIST) ;
                       
     PROCEDURE DELETE (THIS_ELEMENT      : IN OUT ELEMENT ;
                       FROM_THIS_LIST    : IN OUT LIST) ;
                           
     PROCEDURE COPY   (THIS_LIST           : IN OUT LIST ;
                       TO_THIS_LIST        : IN OUT LIST) ;
                           
     PROCEDURE CLEAR  (THIS_LIST           : IN OUT LIST) ;
                               
     GENERIC
          
          WITH PROCEDURE PROCESS (THIS_ELEMENT    : IN  ELEMENT ;
                                  CONTINUE        : OUT BOOLEAN) ;
                                         
     PROCEDURE ITERATE (OVER_THIS_LIST    : IN LIST) ;
                               
     FUNCTION NUMBER_OF_ELEMENTS (IN_THIS_LIST : IN LIST)
          RETURN NATURAL ;
          
     FUNCTION "=" (LEFT  : IN LIST ;
                   RIGHT : IN LIST) RETURN BOOLEAN ;
               
PRIVATE
     
     TYPE LIST_TABLE IS ARRAY (POSITIVE RANGE 1 .. 10) OF ELEMENT ;
          
     TYPE LIST IS RECORD
          LENGTH        : NATURAL := 0 ;
          ACTUAL_LIST   : LIST_TABLE ;
     END RECORD ;
          
END CC3019B0_LIST_CLASS ;
