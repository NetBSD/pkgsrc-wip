-- CC51D01.A
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
--      Check that, in an instance, each implicit declaration of a user-defined
--      subprogram of a formal private extension declares a view of the
--      corresponding primitive subprogram of the ancestor, and that if the
--      tag in a call is statically determined to be that of the formal type,
--      the body executed will be that corresponding to the actual type.
--
--      Check subprograms declared within a generic formal package. Check for
--      the case where the actual type passed to the formal private extension
--      is a specific tagged type. Check for several types in the same class.
--
--
-- TEST DESCRIPTION:
--      Declare a list abstraction in a generic package which manages lists of
--      elements of any nonlimited type (foundation code). Declare a package
--      which declares a tagged type and a type derived from it. Declare an
--      operation for the root tagged type and override it for the derived
--      type. Derive a type from this derived type, but do not override the
--      operation. Declare a generic subprogram which operates on lists of
--      elements of tagged types. Provide the generic subprogram with two
--      formal parameters: (1) a formal derived tagged type which represents a
--      list element type, and (2) a generic formal package with the list
--      abstraction package as template. Use the formal derived type as the
--      generic formal actual part for the formal package. Within the generic
--      subprogram, call the operation of the root tagged type. In the main
--      program, instantiate the generic list package and the generic
--      subprogram with the root tagged type and each derivative, then call
--      each instance with an object of the appropriate type.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC51D00.A
--      -> CC51D01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      04 Jan 95   SAIC    Moved declaration of type Ranked_ID_Type from
--                          main subprogram to package CC51D01_0. Removed
--                          case passing class-wide actual to instance.
--                          Updated test description and modified comments.
--
--!

package CC51D01_0 is -- This package simulates support for a personnel
                     -- database.

   type SSN_Type is new String (1 .. 9);

   type Blind_ID_Type is tagged record                   -- Root type of
      SSN : SSN_Type;                                    -- class.
      -- ... Other components.
   end record;

   procedure Update_ID (Item : in out Blind_ID_Type);    -- Parent operation.

   -- ... Other operations.


   type Name_Type is new String (1 .. 9);

   type Named_ID_Type is new Blind_ID_Type with record   -- Direct derivative
      Name : Name_Type := "Doe      ";                   -- of root type.
      -- ... Other components.
   end record;

   -- Inherits Update_ID from parent.

   procedure Update_ID (Item : in out Named_ID_Type);    -- Overrides parent's
                                                         -- implementation.


   type Ranked_ID_Type is new Named_ID_Type with record
      Level : Integer := 0;                              -- Indirect derivative
      -- ... Other components.                           -- of root type.
   end record;

   -- Inherits Update_ID from parent.

end CC51D01_0;
