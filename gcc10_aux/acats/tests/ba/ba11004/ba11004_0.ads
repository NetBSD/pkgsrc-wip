-- BA11004.A
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
 --      Check that a child library subprogram is not primitive subprogram
 --      (i.e, is not inherited by types derived from a type declared in
 --      the parent).
 --
 -- TEST DESCRIPTION:
 --      Declare a type and two primitive subprograms in the parent package.
 --      Declare public child subprograms that have the same profiles as the
 --      the subprograms from the parent package.  In another package, derive 
 --      a new type from the parent's type.
 --      
 --      In the main program, declare a new type.  Call the inherited 
 --      operations from the parent.  Call the children subprograms.
 --
 --
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
 --!
 
 package BA11004_0 is
 
    type Visible_Integer is range 1..100;
 
    function Inherited_Function (I : Visible_Integer) 
      return Visible_Integer;                  
 
    procedure Inherited_Procedure (I : in     Visible_Integer;
                                   R :    out Visible_Integer);
 
 end BA11004_0;
