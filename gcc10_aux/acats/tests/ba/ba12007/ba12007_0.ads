-- BA12007.A
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
--      Check that the rename of a child unit (i.e. a library unit with  
--      an expanded name) does not make declarations within ancestors of
--      the child visible.
--
--      Check that a parent unit name (in the defining declaration of a
--      child unit) does not designate a renaming declaration.
--
-- TEST DESCRIPTION:
--      Declare a parent package.  Declare a public child package.  Declare 
--      a public grandchild package.  Declare a public grandchild function.
--      Declare a public generic grandchild.  
--      Rename the public grandchild package, the public grandchild function,
--      and the public grandchild generic package as compilation units.  
--      In separate packages, "with"s the renamed package and accesses the 
--      grandparent and parent types.
--      Rename the public child package as a compilation unit.
--      In separate packages, accesses the renamed package as a parent unit
--      name.
--
--                      BA12007_0         BA12007_5  BA12007_6, etc
--                           |
--                           |
--                       BA12007_1
-- renamed as           /    | _14\
--                     /     |     \              
--              BA12007_2 BA12007_3 BA12007_4
-- renamed as          _8        _9        _10
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      14 Mar 95   SAIC    Changed with BA12007_14.BA12007_2 to be ERROR;
--                          Modified function renaming. Added new case. 
--      07 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--      07 Sep 96   SAIC    ACVC 2.1
--
--!

-- Parent package

package BA12007_0 is

   -- Type definitions.

   type Parent_Type is range 1 .. 10;

end BA12007_0;
