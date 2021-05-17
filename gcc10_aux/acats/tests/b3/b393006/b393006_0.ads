-- B393006.A
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
--      Check that, if a non-abstract type is derived from an abstract formal
--      private type within the generic declaration, an instantiation is
--      rejected if primitive subprograms that require overriding are
--      inherited by the derived type from the actual (parent) type
--      and they are not overridden.
--
-- TEST DESCRIPTION:
--      Check cases where the primitive subprogram is declared abstract,
--      cases where the primitive subprogram is a function with a controlling
--      result, and cases where the primitive subprogram is a function with
--      a controlling access result. Include a case where the parent of the
--      derived type is the formal type of a formal package, and a case
--      where a null extension is checked.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    ACVC 2.0.1 fixes: added context clause. Renamed
--                          from BC51014.
--      28 Feb 96   SAIC    ACVC 2.0.1 fixes: moved declaration of Proc in
--                          B393006_0 to visible part. Relabeled Instance6
--                          case from OK to ERROR. Corrected commentary.
--      01 Jun 98   EDS     Delete the private part of generic package B393006_1
--                          and delete the body of generic package B393006_1.
--      23 Oct 07   RLB     Updated terminology of objective.
--
--!

generic
   type Formal_Type is abstract tagged private;     -- Abstract formal private
package B393006_0 is                                -- type.

   type Derived_Type is new Formal_Type with record -- Non-abstract derivative.
      Field : Natural := 0;
   end record;
   -- In the instance, inherits primitive subprograms of the actual.


   function Func (E : Derived_Type)                 -- Primitive function:
     return Derived_Type;                           -- overrides Func of actual
                                                    -- (if any).

   procedure Proc (Parm : Derived_Type);            -- Primitive procedure:
                                                    -- overrides Proc of actual
end B393006_0;                                      -- (if any).
