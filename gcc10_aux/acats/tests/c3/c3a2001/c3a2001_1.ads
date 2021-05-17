-- C3A2001.A
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
--      Check that an access type may be defined to designate the
--      class-wide type of an abstract type.  Check that the access type
--      may then be used subsequently with types derived from the abstract
--      type.  Check that dispatching operations dispatch correctly, when
--      called using values designated by objects of the access type.
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
--      illustrates the relationships.
--
--              Abstract type:           Breaker(1)
--                                           |
--                                    Basic_Breaker(2)
--                                    /           \
--                           Ground_Fault(3)    Special_Breaker(4)
--
--      Test structure is a polymorphic linked list, modeling a circuit
--      as a list of components.  The type component is the access type
--      defined to designate Breaker'Class values.  The test then creates
--      some values, and traverses the list to determine correct operation.
--      This test is instrumented with a the trace facility found in
--      foundation F392C00 to simplify the verification process.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Nov 95   SAIC    Checked compilation for ACVC 2.0.1
--      23 APR 96   SAIC    Added pragma Elaborate_All
--      26 NOV 96   SAIC    Elaborate_Body changed to Elaborate_All
--
--!

with Report;
with TCTouch;
package C3A2001_1 is

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
end C3A2001_1;
