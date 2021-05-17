-- C760002.A
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
--      Check that assignment to an object of a (non-limited) controlled
--      type causes the Adjust operation of the type to be called.
--      Check that Adjust is called after copying the value of the
--      source expression to the target object.
--
--      Check that Adjust is called for all controlled components when
--      the containing object is assigned.  (Test this for the cases
--      where the type of the containing object is controlled and
--      noncontrolled; test this for initialization as well as
--      assignment statements.)
--
--      Check that for an object of a controlled type with controlled
--      components, Adjust for each of the components is called before
--      the containing object is adjusted.
--
--      Check that an Adjust procedure for a Limited_Controlled type is
--      not called by the implementation.
--
-- TEST DESCRIPTION:
--      This test is loosely "derived" from C760001.
--
--      Visit Tags:
--        D - Default value at declaration
--        d - Default value at declaration, limited root
--        I - initialize at root controlled
--        i - initialize at root limited controlled
--        A - adjust at root controlled
--        X,Y,Z,x,y,z - used in test body
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Correct test assertion logic for Sinister case
--
--!

---------------------------------------------------------------- C760002_0

with Ada.Finalization;
package C760002_0 is
  subtype Unique_ID is Natural;
  function Unique_Value return Unique_ID;
  -- increments each time it's called

  function Most_Recent_Unique_Value return Unique_ID;
  -- returns the same value as the most recent call to Unique_Value

  type Root is tagged record
    My_ID      : Unique_ID := Unique_Value;
    Visit_Tag  : Character := 'D';  -- Default
  end record;

  procedure Initialize( R: in out Root );
  procedure Adjust    ( R: in out Root );

  type Root_Controlled is new Ada.Finalization.Controlled with record
    My_ID      : Unique_ID := Unique_Value;
    Visit_Tag  : Character := 'D'; ---------------------------------------- D
  end record;

  procedure Initialize( R: in out Root_Controlled );
  procedure Adjust    ( R: in out Root_Controlled );

  type Root_Limited_Controlled is
       new Ada.Finalization.Limited_Controlled with record
    My_ID      : Unique_ID := Unique_Value;
    Visit_Tag  : Character := 'd'; ---------------------------------------- d
  end record;

  procedure Initialize( R: in out Root_Limited_Controlled );
  procedure Adjust    ( R: in out Root_Limited_Controlled );

end C760002_0;
