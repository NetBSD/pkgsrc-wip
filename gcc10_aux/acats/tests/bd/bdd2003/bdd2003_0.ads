-- BDD2003.A
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
--      Check that an attribute reference for the stream attributes
--      'Write and 'Read is illegal if the attributes are not available,
--	which is usually true for limited types, including
--      task types and composite types containing limited components.
--
-- TEST DESCRIPTION:
--      A common user error associated with the 'Write and 'Read attributes
--      would be an attempt to reference these attributes with objects of a
--      limited type, especially an object of a composite type that contains
--      a limited component.   Numerous limited types are defined, and
--      objects of each of these types are used in attempted 'Read and
--      'Write attribute references. Each attempt should be flagged by the
--      compiler as illegal.
--      At the end of the test, the 'Read and 'Write attributes for a limited
--      type are specified, using an attribute definition clause.  References
--      to these attributes should then be legal.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      07 Apr 95   SAIC    Modified definition of type with access
--                          discriminant, as well as the declaration of an
--                          object of this type.
--      15 Mar 07   RLB     Renamed test so it is near the rules being
--                          tested (and the other similar test). Updated
--                          the objective to reflect terminology changes in
--                          the Amendment.
--      06 Feb 18   RLB     Added error location indicators.
--
--!

package BDD2003_0 is

   type Limited_Type  is limited private;

   type Root_Type is tagged limited
      record
         Component : String (1..21) := "Non-limited Component";
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

   type Extended_Type is new Root_Type with
      record
         Limited_Comp : Limited_Type;
   end record;

   type Extended_With_Limited_Comp_Type is
     new Root_Type with
      record
         Extended_Comp : Limited_Type;
   end record;

end BDD2003_0;
