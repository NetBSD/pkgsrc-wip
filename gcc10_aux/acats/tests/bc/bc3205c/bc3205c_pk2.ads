-- BC3205C.ADA

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
-- OBJECTIVE:
--     CHECK THAT AN INSTANTIATION IS ILLEGAL IF A FORMAL LIMITED/NON-
--     LIMITED PRIVATE TYPE WITH UNKNOWN DISCRIMINANTS IS USED IN AN
--     ALLOCATOR, A VARIABLE OBJECT DECLARATION, A RECORD COMPONENT
--     DECLARATION, OR AN ARRAY TYPE DEFINITION.

--     TEST WHEN THE INSTANTIATIONS, GENERIC SPECIFICATION, AND GENERIC
--     BODY ARE IN SEPARATE PROGRAM UNITS WITHIN THE SAME COMPILATION.
--     THE INSTANTIATIONS ARE COMPILED BEFORE THE GENERIC BODY.

-- HISTORY:
--     SPS 07/14/82
--     JBG 03/8/84
--     JBG 04/29/85
--     THS 04/16/90  SPLIT TEST TO BC3205I.ADA.
--     JRL 05/03/96  CHANGED OBJECTIVE AND TEST TO REFLECT ADA95 RULES.


GENERIC
     TYPE P (<>) IS PRIVATE;
     TYPE L IS LIMITED PRIVATE;
PACKAGE BC3205C_PK2 IS
   procedure Dummy;
END BC3205C_PK2;
