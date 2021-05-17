-- C760011.A
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
--      Check that the anonymous objects of a controlled type associated with
--      function results and aggregates are finalized no later than the
--      end of the innermost enclosing declarative_item or statement.  Also
--      check this for function calls and aggregates of a noncontrolled type
--      with controlled components.
--
-- TEST DESCRIPTION:
--      This test defines a controlled type with a discriminant, the
--      discriminant is use as an index into a global table to indicate that
--      the object has been finalized.  The controlled type is used as the
--      component of a non-controlled type, and the non-controlled type is
--      used for the same set of tests.  Following is a table of the tests
--      performed and their associated tag character.
--
--      7.6(21) allows for the optimizations that remove these temporary
--      objects from ever existing.  As such this test checks that in the
--      case the object was initialized (the only access we have to
--      determining if it ever existed) it must subsequently be finalized.
--
-- CASE TABLE:
--      A - aggregate test, controlled
--      B - aggregate test, controlled
--      C - aggregate test, non_controlled
--      D - function test, controlled
--      E - function test, non_controlled
--      F - formal parameter function test, controlled
--      G - formal parameter aggregate test, controlled
--      H - formal parameter function test, non_controlled
--      I - formal parameter aggregate test, non_controlled
--
--      X - scratch object, not consequential to the objective
--      Y - scratch object, not consequential to the objective
--      Z - scratch object, not consequential to the objective
--
--
-- CHANGE HISTORY:
--      22 MAY 95   SAIC    Initial version
--      24 APR 96   SAIC    Minor doc fixes, visibility patch
--      14 NOV 96   SAIC    Revised for release 2.1
--
--!

------------------------------------------------------------------- C760011_0

with Ada.Finalization;
package C760011_0 is
  type Tracking_Array is array(Character range 'A'..'Z') of Boolean;

  Initialized : Tracking_Array := (others => False);
  Finalized   : Tracking_Array := (others => False);

  type Controlled_Type(Tag : Character) is
    new Ada.Finalization.Controlled with record
      TC_Component : String(1..4) := "ACVC";
    end record;
  procedure Initialize( It: in out Controlled_Type );
  procedure Finalize  ( It: in out Controlled_Type );
  function Create(With_Tag: Character) return Controlled_Type;

  type Non_Controlled(Tag : Character := 'Y') is record
    Controlled_Component : Controlled_Type(Tag);
  end record;
  procedure Initialize( It: in out Non_Controlled );
  procedure Finalize  ( It: in out Non_Controlled );
  function Create(With_Tag: Character) return Non_Controlled;

  Under_Debug : constant Boolean := False;  -- construction lines

end C760011_0;
