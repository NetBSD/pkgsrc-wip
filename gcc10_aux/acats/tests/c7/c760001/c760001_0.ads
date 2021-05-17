-- C760001.A
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
--      Check that Initialize is called for objects and components of
--      a controlled type when the objects and components are not
--      assigned explicit initial values.  Check this for "simple" controlled
--      objects, controlled record components and arrays with controlled
--      components.
--
--      Check that if an explicit initial value is assigned to an object
--      or component of a controlled type then Initialize is not called.
--
-- TEST DESCRIPTION:
--      This test derives a type for Ada.Finalization.Controlled, and
--      overrides the Initialize and Adjust operations for the type.  The
--      intent of the type is that it should carry incremental values
--      indicating the ordering of events with respect to these (and default
--      initialization) operations.  The body of the test uses these values
--      to determine that the implicit calls to these subprograms happen
--      (or don't) at the appropriate times.
--
--      The test further derives types from this "root" type, which are the
--      actual types used in the test.  One of the types is "simply" derived
--      from the "root" type, the other contains a component of the first
--      type, thus nesting a controlled object as a record component in
--      controlled objects.
--
--      The main program declares objects of these types and checks the
--      values of the components to ascertain that they have been touched
--      as expected.
--
--      Note that Finalization procedures are provided.  This test does not
--      test that the calls to Finalization are made correctly.  The
--      Finalization procedures are provided to catch an implementation that
--      calls Finalization at an incorrect time.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Oct 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

---------------------------------------------------------------- C760001_0

with Ada.Finalization;
package C760001_0 is
  subtype Unique_ID is Natural;
  function Unique_Value return Unique_ID;
  -- increments each time it's called

  function Most_Recent_Unique_Value return Unique_ID;
  -- returns the same value as the most recent call to Unique_Value

  type Root_Controlled is new Ada.Finalization.Controlled with record
    My_ID      : Unique_ID := Unique_Value;
    My_Init_ID : Unique_ID := Unique_ID'First;
    My_Adj_ID  : Unique_ID := Unique_ID'First;
  end record;

  procedure Initialize( R: in out Root_Controlled );
  procedure Adjust    ( R: in out Root_Controlled );

  TC_Initialize_Calls_Is_Failing : Boolean := False;

end C760001_0;
