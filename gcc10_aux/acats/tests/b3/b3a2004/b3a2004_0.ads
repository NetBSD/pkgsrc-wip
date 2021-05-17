-- B3A2004.A
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
--      Check that, for X'Access of a general access type A, the accessibility
--      level of the view denoted by X must not be statically deeper than that 
--      of the access type A.
--
--      Check for cases where X is:
--         (a) a renaming of an aliased view.
--         (b) a dereference of an access-to-object value.
--         (c) a view conversion of an aliased view.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep "nesting level" than the
--      general access type A -- X must "live" as long as A. Nesting levels
--      are the run-time nestings of masters: block statements; subprogram,
--      task, and entry bodies; and accept statements. Packages are invisible
--      to accessibility rules.
--
--      If X is a view of an object denoted by a renaming declaration, its
--      accessibility level is that of the renamed view.
--
--      If X is a view of an object denoted by a dereference of an access
--      value, its accessibility level is that of the associated access type.
--
--      If X is a view conversion, its accessibility level is the same as that
--      of its operand.
--
--      This test declares general access types and aliased views in various
--      packages and nested blocks and task bodies, and verifies that X'Access
--      is illegal when X has a deeper accessibility level than that of the
--      type of X'Access, and legal otherwise. Accessibility is checked in two
--      contexts: X'Access is assigned to an access object; X'Access is passed
--      as an actual to a subprogram.
--
--      The nesting structure is as follows:
--
--          - Library-level package
--         |                                     (Level = 0)
--          - end package
--
--          - Main subprogram
--         |                                     (Level = 1)
--         |  begin          
--         |     - Nested block
--         |    |                                (Level = 2)
--         |    |     - Nested task
--         |    |    |                           (Level = 3)
--         |    |    |  begin
--         |    |    |     *** Testing here
--         |    |    |     - Accept statement    (Level = 4)
--         |    |    |   |      *** Testing here
--         |    |    |     - end accept
--         |    |     - end task
--         |    |  begin
--         |    |     *** Testing here
--         |     - end block
--         |     *** Testing here
--          - end Main subprogram
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Mar 95   SAIC    Changed access-to-variable type AccTag_L3 to
--                          access-to-constant type.
--
--!

package B3A2004_0 is

--
-- Record type, associated objects and access types:
-- 

   type Obj_Type is record
      Comp : Integer := 10;
   end record;

   type AccObj_L0 is access all Obj_Type;                         -- Level = 0.
   GAT0   : AccObj_L0;
   Obj_L0 : aliased Obj_Type;                                     -- Level = 0.
   AAT0   : array (1 .. 4) of aliased Obj_Type;                   -- Level = 0.


--
-- Type with aliased component:
--

   -- Note that the accessibility level of an aliased component is
   -- determined from where the composite *object* is declared, and not
   -- from where the composite *type* is declared. 

   type Rec_With_Comp is record
      C: aliased Obj_Type;         -- Aliased component.
   end record;


--
-- Tagged types, associated objects and access types:
-- 

   type Tag_Type is tagged record
      I : Integer;
   end record;

   type Der_Type is new Tag_Type with record
      B : Boolean;
   end record;

   type AccTag_L0 is access all Tag_Type;                         -- Level = 0.
   ATT0   : AccTag_L0;
   Der_L0 : aliased Der_Type;                                     -- Level = 0.


end B3A2004_0;
