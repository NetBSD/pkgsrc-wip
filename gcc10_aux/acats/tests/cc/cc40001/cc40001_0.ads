-- CC40001.A
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
--      Check that adjust is called on the value of a constant object created
--      by the evaluation of a generic association for a formal object of
--      mode in.
--
--      Check that those values are also subsequently finalized.
--
-- TEST DESCRIPTION:
--      Create a backdrop of a controlled type sufficient to check that the
--      correct operations get called at appropriate times.  Create a generic
--      unit that takes a formal parameter of a formal type.  Create instances
--      of this generic using various "levels" of the controlled type.  Check
--      the same case for a generic child unit.
--
--      The cases tested are where the type of the formal object is:
--        a visible classwide type  : CC40001_2
--        a formal private type     : CC40001_3
--        a formal tagged type      : CC40001_4
--
--      To more fully take advantage of the features of the language, and
--      present a test which is "user oriented" this test utilizes multiple
--      aspects of the language in combination.  Using Ada.Strings.Unbounded
--      in combination with Ada.Finalization and Ada.Calendar to build layers
--      of an object oriented system will likely be very common in actual
--      practice.  A common paradigm in the language will also be the use of
--      a parent package defining "basic" tagged types, and child packages
--      will expand on those types via derivation.  The model used in this
--      test is a simple type containing a character identity (used in the
--      identity).  The next level of type add a timestamp.  Further levels
--      might add location information, etc. however for the purposes of this
--      test we stop at the second layer, as it is sufficient to test the
--      stated objective.
--
--
-- CHANGE HISTORY:
--      06 FEB 96   SAIC   Initial version
--      30 APR 96   SAIC   Added finalization checks for 2.1
--      13 FEB 97   PWB.CTA  Moved global objects into bodies, after Initialize
--                         body is elaborated; counted finalizations correctly.
--!

----------------------------------------------------------------- CC40001_0

with Ada.Finalization;
with Ada.Strings.Unbounded;
package CC40001_0 is

  type States is ( Erroneous, Defaulted, Initialized, Reset, Adjusted );

  type Simple_Object(ID: Character) is
    new Ada.Finalization.Controlled with
      record
        TC_Current_State : States := Defaulted;
        Name : Ada.Strings.Unbounded.Unbounded_String;
      end record;

  procedure User_Operation( COB: in out Simple_Object; Name : String );
  procedure Initialize( COB: in out Simple_Object );
  procedure Adjust    ( COB: in out Simple_Object );
  procedure Finalize  ( COB: in out Simple_Object );

  Finalization_Count : Natural;

end CC40001_0;
