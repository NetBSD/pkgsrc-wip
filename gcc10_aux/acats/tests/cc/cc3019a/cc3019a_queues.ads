-- CC3019A.ADA

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
-- CHECK THAT INSTANTIATIONS OF NESTED GENERIC UNITS ARE PROCESSED
-- CORRECTLY.

-- JBG 11/6/85

GENERIC
     TYPE ELEMENT_TYPE IS PRIVATE;
PACKAGE CC3019A_QUEUES IS

     TYPE QUEUE_TYPE IS PRIVATE;

     PROCEDURE ADD (TO_Q : IN OUT QUEUE_TYPE;
                    VALUE : ELEMENT_TYPE);

     GENERIC
          WITH PROCEDURE APPLY (VAL : ELEMENT_TYPE);
     PROCEDURE ITERATOR (TO_Q : QUEUE_TYPE);

PRIVATE

     TYPE CONTENTS_TYPE IS ARRAY (1..3) OF ELEMENT_TYPE;
     TYPE QUEUE_TYPE IS
          RECORD
               CONTENTS : CONTENTS_TYPE;
               SIZE     : NATURAL := 0;
          END RECORD;

END CC3019A_QUEUES;
