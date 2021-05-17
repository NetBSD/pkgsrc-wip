-- BA12002.A
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
--      Check that the with-clause of a public second level descendant of
--      some library unit cannot include a private descendant of the same
--      ancestor.
--
-- TEST DESCRIPTION:
--      Declare a grandparent package.  Declare a private parent package.
--      Declare a private grandchild function.  Declare a public grandchild 
--      procedure.  Declare a public parent package.  Declare a public
--      grandchild package.
--
--                               BA12002_0
--                               /       \
--                              /         \
--                       BA12002_1     BA12002_4
--                       (private)           \
--                        /     \             \
--                       /       \             \
--                  BA12002_2   BA12002_3    BA12002_5
--                  (private)  
--      
--      The specification of the public grandchild, BA12002_5, "with"s 
--      the following library units:
--
--         (a) the private parent package, BA12002_1.
--         (b) the private grandchild procedure, BA12002_2.
--         (c) the public grandchild function, BA12002_3.
--      
--      All cases (a) through (c) should cause compile-time errors.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Grandparent

package BA12002_0 is

   type Grandparent_Type is range 101 .. 500;

end BA12002_0;
