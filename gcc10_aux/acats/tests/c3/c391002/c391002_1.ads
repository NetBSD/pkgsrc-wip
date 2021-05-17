-- C391002.A
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
--      components in record extension are correctly supported.
--      Check that record extensions inherit all the visible components
--      of their ancestor types.
--      Check that discriminants are correctly inherited.
--
-- TEST DESCRIPTION:
--      This test defines a simple class hierarchy, where the final
--      derivations exercise the different possible "permissions" available
--      to a designer.  Extension aggregates for discriminated types are used
--      to set values of these final types.  The key difference between
--      this test and C391001 is that the types are visible, and allow the
--      creation of complex discriminated extension aggregates.  Another
--      layer of derivation is present to more robustly check that the
--      inheritance is correctly supported.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Dec 94   SAIC    Removed offending parenthesis in aggregate
--                          extensions, corrected typo: TC_MC SB TC_PC,
--                          corrected visibility errors for literals,
--                          added qualification for aggregate expressions
--                          used in extension aggregates, corrected parameter
--                          order in call to Communications.Creator
--     01 MAY 95    SAIC    Removed "limited" from the definition of Mil_Comm
--     14 OCT 95    SAIC    Fixed some value bugs for ACVC 2.0.1
--     04 MAR 96    SAIC    Altered 3 overambitious extension aggregates
--     11 APR 96    SAIC    Updated documentation for 2.1
--     27 FEB 97    PWB.CTA Deleted extra (illegal) component association
--!

----------------------------------------------------------------- C391002_1

package C391002_1 is 

  type Object is tagged private;  

  -- Constructor operation
  procedure Create( The_Plaque : in out Object );

  -- Selector operations
  function TC_Match( Left_Plaque : Object; Right_Natural : Natural )
    return Boolean;

  function Serial_Number( A_Plaque : Object ) return Natural;

  Unserialized : exception;  -- Serial_Number called before Create
  Reserialized : exception;  -- Create called twice

private
  type Object is tagged record
    Serial_Number : Natural := 0;
  end record;
end C391002_1;
