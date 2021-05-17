-- B3A2003.A
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
--         (a) a view denoted by an object declaration.
--         (b) a view denoted by a component definition.
--         (c) a formal parameter of a tagged type.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep  "nesting level" than the
--      general access type A -- X must "live" as long as A. Nesting levels
--      are the run-time nestings of masters: block statements; subprogram,
--      task, and entry bodies; and accept statements. Packages are invisible
--      to accessibility rules.
--
--      If X is an object declared by an object declaration, its accessibility
--      level is that of the innermost enclosing master execution.
--
--      If X is a component of a composite object, its accessibility level is
--      that of the enclosing composite object.
--
--      If X is a formal parameter of a tagged type, its accessibility level
--      is the same as that of its associated master's execution.
--
--      This test declares general access types and aliased views in various
--      packages and nested subprogram bodies, and verifies that X'Access is
--      illegal when X has a deeper accessibility level than that of the type
--      of X'Access, and legal otherwise. Accessibility is checked in two
--      contexts: X'Access is assigned to an access object; X'Access is passed
--      as an actual to a subprogram.
--
--      The nesting structure is as follows:
--
--          - Library-level package
--         |                                (Level = 0)
--          - end package
--
--          - Main subprogram
--         |                                (Level = 1)
--         |     - Nested procedure
--         |    |                           (Level = 2)
--         |    |     - Nested procedure
--         |    |    |                      (Level = 3)
--         |    |    |  begin
--         |    |    |     *** Testing here
--         |    |     - end procedure
--         |    |  begin
--         |    |     *** Testing here
--         |     - end procedure
--         |  begin          
--         |     *** Testing here
--          - end Main subprogram
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Mar 95   SAIC    Changed access-to-variable types AccTag_L0, 
--                          AccTag_L1, and AccTag_L3 to access-to-constant
--                          types.
--      01 Nov 95   SAIC    Fixed bugs for ACVC 2.0.1
--
--!

package B3A2003_0 is

--
-- Record type, associated objects and access types:
-- 

   type Obj_Type is record
      C : Boolean;
   end record;

   type AccObj_L0 is access all Obj_Type;                         -- Level = 0.
   AOT0 : AccObj_L0;


--
-- Type with aliased component:
--

   -- Note that the accessibility level of a component of an object is the 
   -- same as that of the object.  

   type Rec_With_Comp is record
      C: aliased Obj_Type;         -- Aliased component.
   end record;


--
-- Tagged type, associated objects and access types:
-- 

   type Tag_Type is tagged record
      I : Integer;
   end record;

   type AccTag_L0 is access constant Tag_Type;                    -- Level = 0.
   ATT0 : AccTag_L0;


end B3A2003_0;
