-- F393A00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation provides a simple background for a class family
--      based on an abstract type.  It is to be used to test the
--      dispatching of various forms of subprogram defined/inherited and
--      overridden with the abstract type.
--
--  type                       procedures                  functions
--  ----                       ----------                  ---------
--  Object                     Initialize, Swap(abstract)  Create(abstract)
--        Object'Class                                     Initialized
--    Windmill is new Object   Swap, Stop, Add_Spin        Create, Spin
--      Pump is new Windmill   Set_Rate                    Create, Rate
--      Mill is new Windmill   Swap, Stop                  Create
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!
 
package F393A00_0 is
   procedure TC_Touch ( A_Tag : Character );
   procedure TC_Validate( Expected: String; Message: String );
end F393A00_0;
