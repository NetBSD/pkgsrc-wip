-- B3A2005.A
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
--      of the access type A.  Check for the case where A is an anonymous 
--      access type, and X'Access is used to initialize an access discriminant 
--      of an object created by an allocator.  
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep nesting level than the
--      general access type A -- X must "live" as long as A. The relevant
--      nesting levels are those of block statements, subprogram and task
--      bodies (packages are invisible to accessibility rules).
--
--      The accessibility level of the anonymous type of an access discriminant
--      is that of the containing object or associated constrained subtype.
--
--      If X is an object created by an allocator, its accessibility level
--      is that of the access type of the allocator.
--
--      If A is the anonymous type of an access discriminant, the rules above
--      prevent a potential dangling reference when X is created by an
--      allocator, and the accessibility level of X is deeper than that of the
--      type of the allocator. 
--
--      procedure P is
--         type Desig is ...
--         type Rec (D: access Desig) is limited...
--         type Acc is access Rec;                   -- Level = 1.
--         Global : Acc;
--
--         procedure Proc is
--            X : aliased Desig;                     -- Level = 2.
--            R : Acc := new Rec (D => X'Access);    -- ERROR:
--            -- The accessibility level of X is deeper than that of the
--            -- type of R.all's access discriminant, which is the level
--            -- of R.all, which in turn is the level of Acc.
--         begin
--            Global := R;                           -- Dangerous...
--         end Proc;
--      begin                -- X no longer exists; access discriminant of
--         . . .             -- Global.all accesses a non-existent object.
--      end P;
--
--      This test declares general access types and aliased objects in various
--      packages, nested blocks and subprogram bodies, and verifies that 
--      X'Access is illegal when X has a deeper accessibility level than that
--      of the type of X'Access, and legal otherwise. 
--
--      The nesting structure is as follows:
--
--          - Library-level package         
--         |                                                 (Level = 0)
--         |  private
--         |    *** Testing here
--          - end package
--
--          - Main subprogram               
--         |      *** testing here                           (Level = 1)
--         |     - Nested procedure
--         |    |     *** testing here                       (Level = 2)
--         |    |  begin
--         |    |     *** testing here                     
--         |     - end procedure
--         |  begin          
--         |
--          - end main subprogram
--
--
-- CHANGE HISTORY:
--      22 FEB 95   SAIC    Initial prerelease version.
--      19 Apr 95   SAIC    Changed in parameter FP_L2 to be an in out 
--                          parameter.
--
--!

package B3A2005_0 is

--
-- Types with access discriminants, and associated types:
--

   type Tag_Desig is tagged record
      I : Integer;
   end record;

   X_L0 : aliased Tag_Desig;                                      -- Level = 0.

   type Default_Lim_Disc (D: access Tag_Desig:= X_L0'Access) is limited record
      B : Boolean;
   end record;

   type AccDef_L0 is access Default_Lim_Disc;                     -- Level = 0.

private

   Default_Allocator_Obj_L0 : AccDef_L0 := new Default_Lim_Disc;      -- OK.

end B3A2005_0;
