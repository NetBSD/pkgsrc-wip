-- C392002.A
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
--      Check that the use of a class-wide formal parameter allows for the 
--      proper dispatching of objects to the appropriate implementation of 
--      a primitive operation.  Check this in the case where the root tagged
--      type is defined in a generic package, and the type derived from it is
--      defined in that same generic package.
--
-- TEST DESCRIPTION:
--      Declare a root tagged type, and some associated primitive operations.
--      Extend the root type, and override one or more primitive operations, 
--      inheriting the other primitive operations from the root type.
--      Derive from the extended type, again overriding some primitive
--      operations and inheriting others (including some that the parent 
--      inherited).
--      Define a subprogram with a class-wide parameter, inside of which is a 
--      call on a dispatching primitive operation.  These primitive operations
--      modify global variables (the class-wide parameter has mode IN).
--     
--  The following hierarchy of tagged types and primitive operations is 
--  utilized in this test:
--
--
--    type Vehicle (root)
--            |
--    type Motorcycle
--            |
--            | Operations
--            |   Engine_Size
--            |   Catalytic_Converter
--            |   Emissions_Produced
--            |
--    type Automobile (extended from Motorcycle)
--            |
--            | Operations
--            |   (Engine_Size)       (inherited)
--            |   Catalytic_Converter (overridden)
--            |   Emissions_Produced  (overridden)
--            |
--    type Truck (extended from Automobile)
--            |
--            | Operations
--            |   (Engine_Size)         (inherited twice - Motorcycle)
--            |   (Catalytic_Converter) (inherited - Automobile)
--            |   Emissions_Produced    (overridden)
-- 
--
-- In this test, we are concerned with the following selection of dispatching
-- calls, accomplished with the use of a Vehicle'Class IN procedure 
-- parameter :
--
--                       \ Type
--               Prim. Op \   Motorcycle      Automobile        Truck
--                         \------------------------------------------------ 
--             Engine_Size |      X               X               X
--     Catalytic_Converter |      X               X               X
--     Emissions_Produced  |      X               X               X
--
--
--
-- The location of the declaration and derivation of the root and extended
-- types will be varied over a series of tests.  Locations of declaration
-- and derivation for a particular test are marked with an asterisk (*).
--
-- Root type:
--       
--       Declared in package.                                          
--    *  Declared in generic package.
--
-- Extended types:
--
--    *  Derived in parent location.
--       Derived in a nested package.
--       Derived in a nested subprogram.
--       Derived in a nested generic package.
--       Derived in a separate package.
--       Derived in a separate visible child package.
--       Derived in a separate private child package.
--
-- Primitive Operations:
--
--    *  Procedures with same parameter profile.
--       Procedures with different parameter profile.
--    *  Functions with same parameter profile.
--       Functions with different parameter profile.
--    *  Mixture of Procedures and Functions.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      09 May 96   SAIC    Made single-file for 2.1
--
--!

------------------------------------------------------------------- C392002_0

-- Declare the root and extended types, along with their primitive
-- operations in a generic package.

generic

   type Cubic_Inches     is range <>;
   type Emission_Measure is digits <>;
   Emissions_per_Engine_Cubic_Inch : Emission_Measure;

package C392002_0 is       -- package Vehicle_Simulation

   --
   -- Equipment types and their primitive operations.
   --

   -- Root type.

   type Vehicle is abstract tagged 
      record 
         Weight : Integer;
         Wheels : Positive;
      end record;

   -- Abstract operations of type Vehicle.
   function Engine_Size         (V : in Vehicle) return Cubic_Inches
            is abstract;
   function Catalytic_Converter (V : in Vehicle) return Boolean
            is abstract;
   function Emissions_Produced  (V : in Vehicle) return Emission_Measure
            is abstract;

   --

   type Motorcycle is new Vehicle with
      record
         Size_Of_Engine : Cubic_Inches;
      end record;

   -- Primitive operations of type Motorcycle.
   function Engine_Size         (V : in Motorcycle) return Cubic_Inches;
   function Catalytic_Converter (V : in Motorcycle) return Boolean;
   function Emissions_Produced  (V : in Motorcycle) return Emission_Measure;

   --
                          
   type Automobile is new Motorcycle with
      record
         Passenger_Capacity : Integer;
      end record;

   -- Function Engine_Size inherited from parent (Motorcycle).
   -- Primitive operations (Overridden).
   function Catalytic_Converter (V : in Automobile) return Boolean;
   function Emissions_Produced  (V : in Automobile) return Emission_Measure;
                          
   --

   type Truck is new Automobile with
      record
         Hauling_Capacity : Natural;
      end record;

   -- Function Engine_Size inherited twice.
   -- Function Catalytic_Converter inherited from parent (Automobile).
   -- Primitive operation (Overridden).
   function Emissions_Produced  (V : in Truck) return Emission_Measure;

end C392002_0;
