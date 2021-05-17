-- BDD2001.A
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
--	Check that an attribute reference for the stream attributes
--	'Input, 'Output, 'Class'Input, and 'Class'Output cannot be used
--	if the attributes are not available, which is usually true for
--	limited types, including composite types containing limited
--	components.
--
-- TEST DESCRIPTION:
--      A common user error associated with the above mentioned attributes
--      would be an attempt to output/input to/from a stream file with an
--      object of a limited type, especially an object of a composite type
--      that contains a limited component.
--
--      This test consists of a variety of limited type declarations, and the
--      declaration of objects of these types.  Attempts are then made to
--      invoke the Stream oriented attributes using these types and objects.
--      Since these attributes are not defined for limited types, these
--      attempted usages should be indicated as compile time errors.
--      We have attempted full coverage of all defined types in this test,
--      but this coverage is spread across 'Input/'Output and
--      'Class'Input/'Class'Output (i.e., types tested by 'Output would not
--      be tested with 'Input.)
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      07 Apr 95   SAIC    Modified definition of type Comp_With_Lim_Disc.
--      28 Feb 96   SAIC    Modified based on ACVC Reviewer commentary.
--      19 Nov 96   SAIC    Removed references to 'Input attribute subtest.
--      15 Mar 07   RLB     Updated the objective to reflect terminology
--                          changes in the Amendment. Removed unneeded with.
--
--!

package BDD2001_0 is

   type Limited_Type  is limited private;
   type Limited_Enum  is limited private;

   type Root_Type     is tagged limited private;

   type New_Root_Type is tagged limited
      record
         Limited_Comp : Limited_Type;
   end record;

   type Extended_Type is new Root_Type with private;

   type Root_With_Limited_Comp_Type is tagged limited
      record
         Limited_Comp : Limited_Type;
   end record;

   type Extended_With_Limited_Comp_Type is limited private;


private

   type Limited_Type is
      record
         Component : Integer := -100;
   end record;

   type Limited_Enum is (Black, White);

   type Root_Type is tagged limited
      record
         Component : String (1..21) := "Non-limited Component";
   end record;

   type Extended_Type is new Root_Type with
      record
         Limited_Comp : Limited_Type;
   end record;

   type Extended_With_Limited_Comp_Type is
     new Root_With_Limited_Comp_Type with
      record
         Extended_Comp : Limited_Type;
   end record;

end BDD2001_0;
