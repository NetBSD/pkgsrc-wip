-- C640001.A
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
--      Check that the prefix of a subprogram call with an actual parameter
--      part may be an implicit dereference of an access-to-subprogram value.
--      Check that, for an access-to-subprogram type whose designated profile
--      contains parameters of a tagged generic formal type, an access-to-
--      subprogram value may designate dispatching and non-dispatching
--      operations, and that dereferences of such a value call the appropriate
--      subprogram.
--
-- TEST DESCRIPTION:
--      The test declares a tagged type (Table) with a dispatching operation
--      (Clear), as well as a derivative (Table2) which overrides that
--      operation. A subprogram with the same name and profile as Clear is
--      declared in a separate package -- it is therefore not a dispatching
--      operation of Table. For the purposes of the test, each version of Clear
--      modifies the components of its parameter in a unique way.
--
--      Additionally, an operation (Reset) of type Table is declared which
--      makes a re-dispatching call to Clear, i.e.,
--
--         procedure Reset (A: in out Table) is
--         begin
--            ...
--            Clear (Table'Class(A));  -- Re-dispatch based on tag of actual.
--            ...
--         end Reset;   
--
--      An access-to-subprogram type is declared within a generic package,
--      with a designated profile which declares a parameter of a generic
--      formal tagged private type.
--
--      The generic is instantiated with type Table. The instance defines an
--      array of access-to-subprogram values (which represents a table of
--      operations to be performed sequentially on a single operand).
--      Access values designating the dispatching version of Clear, the
--      non-dispatching version of Clear, and Reset (which re-dispatches to
--      Clear) are placed in this array.
--
--      In the instance, each subprogram in the array is called by implicitly
--      dereferencing the corresponding access value. For the dispatching and
--      non-dispatching versions of Clear, the actual parameter passed is of
--      type Table. For Reset, the actual parameter passed is a view conversion
--      of an object of type Table2 to type Table, i.e., Table(Table2_Obj).
--      Since the tag of the operand never changes, the call to Clear within
--      Reset should execute Table2's version of Clear.
--
--      The main program verifies that the appropriate version of Clear is
--      called in each case, by checking that the components of the actual are
--      updated as expected.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C640001_0 is

   -- Data type artificial for testing purposes.

   Row_Len : constant := 10;

   T : constant Boolean := True;
   F : constant Boolean := False;

   type Row_Type is array (1 .. Row_Len) of Boolean;

   function Is_True  (A : in Row_Type) return Boolean;
   function Is_False (A : in Row_Type) return Boolean;


   Init : constant Row_Type := (T, F, T, F, T, F, T, F, T, F);

   type Table is tagged record                  -- Tagged type.
      Row1 : Row_Type := Init;
      Row2 : Row_Type := Init;
   end record;

   procedure Clear (A : in out Table);          -- Dispatching operation.

   procedure Reset (A : in out Table);          -- Re-dispatching operation.

   -- ...Other operations.


   type Table2 is new Table with null record;   -- Extension of Table (but
                                                -- structurally identical).

   procedure Clear (A : in out Table2);         -- Overrides parent's op.

   -- ...Other operations.


end C640001_0;
