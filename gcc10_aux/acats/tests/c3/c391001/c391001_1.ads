-- C391001.A
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
-- OBJECTIVE:
--      Check that structures nesting discriminated records as
--      components in record extension are correctly supported.  Check
--      for this using limited private structures.
--      Check that record extensions inherit all the visible components
--      of their ancestor types. 
--      Check that discriminants are correctly inherited.
--
-- TEST DESCRIPTION:
--      This test defines a textbook object, a serial number plaque.
--      This object is used in each of several other structures modeled
--      after those used in an existing antenna modeling software system.
--      Record types discriminated and undiscriminated are nested to
--      produce a layered design.  Some parametrization is programmatic;
--      some parametrization is data-driven.
--
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--      19 Apr 95   SAIC    Added "limited" to full type def of "Object"
--
--!
 
 package C391001_1 is 
   type Object is tagged limited private;
   -- Constructor operation
   procedure Create( The_Plaque : in out Object );
   -- Selector operations
   function "="( Left_Plaque,Right_Plaque : Object ) return Boolean;
   function TC_Match( Left_Plaque : Object; Right_Natural : Natural )
     return Boolean;
   function Serial_Number( A_Plaque : Object ) return Natural;
   Unserialized : exception;  -- Serial_Number called before Create
   Reserialized : exception;  -- Create called twice
 private
   type Object is tagged limited record
     Serial_Number : Natural := 0;
   end record;
 end C391001_1;
