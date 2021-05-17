-- B840001.A
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
--      Check that the name in a use type clause must denote a subtype. Check
--      that only the primitive operators of the type determined by the
--      subtype mark in a use type clause are use-visible (in particular, that
--      the primitive operators of no other type declared in the same
--      package are use-visible). Check that the scope of a use type clause
--      in the private part of a library unit does not include the visible
--      part of any public descendant of that library unit.
--
-- TEST DESCRIPTION:
--      The test checks that the name in a use-type clause may be a direct
--      name or an expanded name of a subtype declared in a parent or
--      child unit, but that it may not be the name of a package.
--
--      The test checks that, for a package which declares two types for which
--      the primitive operators have the same names, only the operators of the
--      type named in the use type clause are made directly visible. It also
--      checks that the name of the type named in the use type clause is not
--      made directly visible, nor are explicitly or implicitly declared
--      primitive subprograms of the type which are not primitive operators.
--
--      The test checks that, for a use type clause in the private part of
--      a library unit, the primitive operators of the named type are made
--      directly visible in the visible and private parts of a private child
--      unit and in the private part of a public child unit, but not in the
--      visible part of a public child unit.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package B840001_0 is

   type My_Integer is range -128 .. 127;

   -- Equality operators (=, /=) implicitly declared here.
   -- Ordering operators (<, <=, >, >=) implicitly declared here.
   -- Binary adding operators (+, -) implicitly declared here.
   -- Unary adding operators (+, -) implicitly declared here.
   -- Multiplying operators (*, /, mod, rem) implicitly declared here.
   -- Highest precedence operators (abs, **) implicitly declared here.

   function Int_Op return My_Integer;

   MyInt01 : My_Integer := 1;
   MyInt02 : My_Integer := 2;

   -------

   type Der_Integer is new My_Integer;

   -- Equality operators (=, /=) implicitly declared here.
   -- Ordering operators (<, <=, >, >=) implicitly declared here.
   -- Binary adding operators (+, -) implicitly declared here.
   -- Unary adding operators (+, -) implicitly declared here.
   -- Multiplying operators (*, /, mod, rem) implicitly declared here.
   -- Highest precedence operators (abs, **) implicitly declared here.

   -- function Int_Op return Der_Integer implicitly declared here.

   DerInt01 : Der_Integer := 1;
   DerInt02 : Der_Integer := 2;

end B840001_0;
