-- C413001.A
--
--                             Grant of Unlimited Rights
--
--     AdaCore holds unlimited rights in the software and documentation
--     contained herein. Unlimited rights are the same as those granted
--     by the U.S. Government for older parts of the Ada Conformity
--     Assessment Test Suite, and are defined in DFAR 252.227-7013(a)(19).
--     By making this public release, AdaCore intends to confer upon all
--     recipients unlimited rights equal to those held by the Ada Conformity
--     Assessment Authority. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever,
--     and to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. ADACORE MAKES NO EXPRESS OR IMPLIED WARRANTY AS
--     TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE SOFTWARE,
--     DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE OR
--     DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--     This test is based on one submitted by AdaCore; AdaCore retains
--     the copyright on the test.
--
--*
--  OBJECTIVE:
--
--     Check that for the prefixed view L.R, if L represents an object or value
--     of a tagged type T, that R may represent a subprogram with a first
--     parameter of the type T that is declared immediately in the declarative
--     region of an ancestor of T.
--
--     Check that for the prefixed view L.R, if L represents an object or value
--     of a tagged type T, that R may represent a subprogram with a first
--     parameter of a classwide type that covers T that is declared immediately
--     in the declarative region of an ancestor of T.
--
--  CHANGE HISTORY:
--     16 Jul 2004  JM   Initial version.
--     27 Sep 2007  RLB  Converted to ACATS format.
--
--!
package C413001P is
   type TP is tagged record
      Data  : Integer := 999;
   end record;

   procedure Base_Proc  (X : in out TP);
   procedure Base_Proc  (X : in out TP; Value : in Integer);
   function  Base_Func  (X : TP) return Integer;
   function  Base_Func  (X : TP; Value : Integer) return Integer;
   --  These subprograms (Base_Proc and Base_Func) are not redefined
   --  in the extension objects. They are used to check the object.operation
   --  notation applied to inherited subprograms (with and without formals).

   procedure Prim_Proc (X : in out TP);
   procedure Prim_Proc (X : in out TP; Value : Integer);
   function  Prim_Func (X : TP) return Integer;
   function  Prim_Func (X : TP; Value : Integer) return Integer;
   --  These subprograms (Prim_Proc and Prim_Func) are used to check that
   --  the right subprogram is called when they are redefined in extensions

   procedure Class_Wide_Proc (X : in out TP'Class);
   procedure Class_Wide_Proc (X : in out TP'Class; Value : Integer);
   function  Class_Wide_Func (X : TP'Class) return Integer;
   function  Class_Wide_Func (X : TP'Class; Value : Integer) return Integer;
   --  These subprograms are used to check that the right class-wide subprogram
   --  is called even when they are redefined in extensions.

end C413001P;
