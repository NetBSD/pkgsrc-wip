-- C460010.A
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
--      Check that, for an array aggregate without an others choice assigned
--      to an object of a constrained array subtype, Constraint_Error is not
--      raised if the length of each dimension of the aggregate equals the
--      length of the corresponding dimension of the target object, even if
--      the bounds of the corresponding index ranges do not match.
--
-- TEST DESCRIPTION:
--      The test verifies that sliding of array bounds is performed on array
--      aggregates that are part of a larger aggregate, where the bounds of
--      the corresponding index ranges do not match but the lengths of the
--      corresponding dimensions are the same. Both aggregates containing
--      named associations and positional associations are checked. Cases
--      involving static and nonstatic index constraints, as well as pre-
--      defined and modular integer index subtypes, are included.
--
--
-- CHANGE HISTORY:
--      15 Apr 96   SAIC    Prerelease version for ACVC 2.1.
--      20 Oct 96   SAIC    Removed unnecessary parentheses and type
--                          conversions.
--
--!

with Report;
pragma Elaborate (Report);

package C460010_0 is

  type Modular_Type is mod 10;  -- Range 0 .. 9.


  Two  : Modular_Type := Modular_Type (Report.Ident_Int(2));
  Four : Modular_Type := Modular_Type (Report.Ident_Int(4));

  type Array_Modular_Index is array (Modular_Type range <>) of Integer;

  subtype Array_Static_Modular_Constraint    is Array_Modular_Index(2..4);
  subtype Array_Nonstatic_Modular_Constraint is Array_Modular_Index(Two..Four);

end C460010_0;
