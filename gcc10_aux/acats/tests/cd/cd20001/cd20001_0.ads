-- CD20001.A
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
--      Check that for packed records the components are packed as tightly
--      as possible subject to the Size of the component subtypes.
--      Specifically check that Boolean objects are packed one to a bit.
--
--      Check that the Component_Size for a packed array type is less than
--      or equal to the smallest of those factors of the word size that are
--      greater than or equal to the Size of the component subtype.
--      
-- TEST DESCRIPTION:
--      This test defines and packs several types, and checks that the sizes
--      of the resulting objects is as expected.
--
-- APPLICABILITY CRITERIA:
--      All implementations must attempt to compile this test.
--
--      For implementations validating against Systems Programming Annex (C):
--        this test must execute and report PASSED.
--
--      For implementations not validating against Annex C:
--        this test may report compile time errors at one or more points
--        indicated by "-- ANX-C RQMT", in which case it may be graded as
--        inapplicable.  Otherwise, the test must execute and report PASSED.
--
--
-- CHANGE HISTORY:
--      22 JUL 95   SAIC   Initial version
--      08 MAY 96   SAIC   Strengthened for 2.1
--      29 JAN 98   EDS    Deleted check that Component_Size is really a
--                         factor of Word_Size.
--!

----------------------------------------------------------------- CD20001_0

with System;
package CD20001_0 is

  type Wordlong_Bool_Array is array(1..System.Word_Size) of Boolean;
    pragma Pack(Wordlong_Bool_Array);                         -- ANX-C RQMT

  type Def_Rep_Components is range 0..2**(System.Storage_Unit-2);

  type Spec_Rep_Components is range 0..2**(System.Storage_Unit-2);
    for Spec_Rep_Components'Size use System.Storage_Unit;     -- ANX-C RQMT

  type Packed_Array_Def_Components is array(1..32) of Def_Rep_Components;
    pragma Pack(Packed_Array_Def_Components);                 -- ANX-C RQMT

  type Packed_Array_Spec_Components is array(1..32) of Spec_Rep_Components;
    pragma Pack(Packed_Array_Spec_Components);                -- ANX-C RQMT

  procedure TC_Check_Values;

end CD20001_0;
