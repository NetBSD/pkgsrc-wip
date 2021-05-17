-- C854001.A
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
--      Check that a subprogram declaration can be completed by a
--      subprogram renaming declaration. In particular, check that such a
--      renaming-as-body can be given in a package body to complete a
--      subprogram declared in the package specification. Check that calls
--      to the subprogram invoke the body of the renamed subprogram.  Check
--      that a renaming allows a copy of an inherited or predefined subprogram
--      before overriding it later.  Check that renaming a dispatching 
--      operation calls the correct body in case of overriding.
--
-- TEST DESCRIPTION:
--      This test declares a record type, an integer type, and a tagged type
--      with a set of operations in a package. A renaming of a predefined 
--      equality operation of a tagged type is also defined in this package.
--      The predefined operation is overridden in the private part. In a 
--      separate package, a subtype of the record type and integer type 
--      are declared.  Subset of the full set of operations for the record 
--      and types is reexported using renamings-as-bodies. Other operations 
--      are given explicit bodies.  The test verifies that the appropriate 
--      body is executed for each operation on the subtype.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      07 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

package C854001_0 is

   type Component is (Op_Of_Type, Op_Of_Subtype, Initial_Value);

   type Root is record
      Called : Component := Op_Of_Subtype;
   end record;

   procedure Root_Proc (P: in out Root);
   procedure Over_Proc (P: in out Root);

   function Root_Func return Root;
   function Over_Func return Root;

   type Short_Int is range 1 .. 98;

   function "+" (P1, P2 : Short_Int) return Short_Int;
   function Name (P1, P2 : Short_Int) return Short_Int;

   type Tag_Type is tagged record
      C : Component := Initial_Value;
   end record;
   -- Inherits predefined operator "=" and others.

   function Predefined_Equal (P1, P2 : Tag_Type) return Boolean
     renames "=";             
   -- Renames predefined operator "=" before overriding.

private
   function "=" (P1, P2 : Tag_Type) 
     return Boolean;                   -- Overrides predefined operator "=".


end C854001_0;
