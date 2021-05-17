-- C393001.A
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
--      Check that an abstract type can be declared, and in turn concrete
--      types can be derived from it.  Check that the definition of 
--      actual subprograms associated with the derived types dispatch
--      correctly.
--
-- TEST DESCRIPTION:
--      This test declares an abstract type Breaker in a package, and
--      then derives from it.  The type Basic_Breaker defines the least
--      possible in order to not be abstract.  The type Ground_Fault is
--      defined to inherit as much as possible, whereas type Special_Breaker
--      overrides everything it can.  The type Special_Breaker also includes
--      an embedded Basic_Breaker object.  The main program then utilizes
--      each of the three types of breaker, and to ascertain that the
--      overloading and tagging resolution are correct, each "Create"
--      procedure is called with a unique value.  The diagram below
--      illustrates the relationships.  This test is derived from C3A2001.
--
--              Abstract type:           Breaker
--                                           |
--                                    Basic_Breaker (Short)
--                                    /           \
--                     (Sharp) Ground_Fault    Special_Breaker (Shock)
--
--      Test structure is an array of class-wide objects, modeling a circuit
--      as a list of components.  The test then creates some values, and
--      traverses the list to determine correct operation.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    Revised for 2.0.1
--
--!

----------------------------------------------------------------- C393001_1

with Report;
package C393001_1 is

  type Breaker is abstract tagged private;
  type Status  is ( Power_Off, Power_On, Tripped, Failed );

  procedure Flip ( The_Breaker : in out Breaker ) is abstract;
  procedure Trip ( The_Breaker : in out Breaker ) is abstract;
  procedure Reset( The_Breaker : in out Breaker ) is abstract;
  procedure Fail ( The_Breaker : in out Breaker );

  procedure Set ( The_Breaker : in out Breaker'Class; To_State : Status );

  function  Status_Of( The_Breaker : Breaker ) return Status;

private
  type Breaker is abstract tagged record
    State : Status := Power_Off;
  end record;
end C393001_1;
