-- C393011.A
--
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
--
-- TEST OBJECTIVE:
--      Check that an abstract extended type can be derived from an abstract
--      type, and that a a non-abstract type may then be derived from the
--      second abstract type.
--
-- TEST DESCRIPTION:
--      Define an abstract type with three primitive operations, two of them
--      abstract.  Derive an extended type from it, inheriting the non-
--      abstract operation, overriding one of the abstract operations with
--      a non-abstract operation, and overriding the other abstract operation
--      with an abstract operation.  The extended type is therefore abstract;
--      derive an extended type from it.  Override the abstract operation with
--      a non-abstract operation; inherit one operation from the original
--      abstract type, and inherit one operation from the intermediate 
--      abstract type.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!
 
 Package C393011_0 is
     -- Definitions
 
   type Status_Enum is (None, Unhandled, Pending, Handled);
   type Serial_Type is new Integer range 0 .. Integer'Last;
   subtype Priority_Type is Integer range 0..10;
 
   type Display_Enum is (Bit_Bucket, TTY, Console, Big_Screen);
 
   Next : Serial_Type := 1;
   Display_Device : Display_Enum := Bit_Bucket;
 
 end C393011_0;
