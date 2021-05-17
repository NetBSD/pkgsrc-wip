-- C3A0013.A
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
--      Check that a general access type object may reference allocated
--      pool objects as well as aliased objects. (3,4)
--      Check that formal parameters of tagged types are implicitly
--      defined as aliased; check that the 'Access of these formal
--      parameters designates the correct object with the correct
--      tag. (5)
--      Check that the current instance of a limited type is defined as
--      aliased. (5)
--
-- TEST DESCRIPTION:
--      This test takes from the hierarchy defined in C390003; making
--      the root type Vehicle limited private.  It also shifts the
--      abstraction to include the notion of a transmission, an object
--      which is contained within any vehicle.  Using an access
--      discriminant, any subprogram which operates on a transmission
--      may also reference the vehicle in which it is installed.
--
--      Class Hierarchy:
--              Vehicle         Transmission
--               /   \
--           Truck    Car
--
--      Contains:
--                Vehicle( Transmission )
--
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Dec 94   SAIC    Fixed accessibility problems
--
--!

package C3A0013_1 is
  type Vehicle is tagged limited private;
  type Vehicle_ID is access all Vehicle'Class;

  -- Constructors
  procedure Create     ( It : in out Vehicle; 
                         Wheels : Natural := 4 );
  -- Modifiers
  procedure Accelerate ( It : in out Vehicle );
  procedure Decelerate ( It : in out Vehicle );
  procedure Up_Shift   ( It : in out Vehicle );
  procedure Stop       ( It : in out Vehicle );

  -- Selectors
  function  Speed      ( It : Vehicle ) return Natural;
  function  Wheels     ( It : Vehicle ) return Natural;
  function  Gear_Factor( It : Vehicle ) return Natural;

  -- TC_Ops
  procedure TC_Validate( It : in out Vehicle; Speed_Trap : Natural );

  -- dispatching procedure used to check tag correctness
  procedure TC_Validate( It     : Vehicle;
                         TC_ID  : Character);

private

  type Transmission(Within: access Vehicle'Class) is limited record
    Engaged : Boolean := False;
    Gear    : Integer range -1..5 := 0;
  end record;

  -- Current instance of a limited type is defined as aliased

  type Vehicle is tagged limited record
    Wheels: Natural;
    Speed : Natural;
    Power_Train: Transmission( Vehicle'Access );
  end record;
end C3A0013_1;
