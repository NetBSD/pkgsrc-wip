-- BA11003.A
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
--      Check that a child library unit may not have anything other than a
--      library package or generic library package as its parent unit.
--      Check that nested units cannot have child units.
--      Check that child of a generic package may not be anything other than
--      a generic unit or a renaming of some other child of the same generic
--      unit.
--      Check that a child of an instance of a generic package must be an
--      instance or a renaming of a library unit.
--
-- TEST DESCRIPTION:
--      Declare public children subprograms.  Declare a public child
--      of a nested package.  Declare a public non-generic child package
--      of a generic package.  Instantiate the generic package.  Declare
--      a child of this instance.
--
--      LEGAL ITEMS:      _0 _2 _4 _5 _7 _9 _11 _12 _13 _14
--      ILLEGAL ITEMS:    _1 _3 _6 _8 _10
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      08 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

-- Procedure as a parent.

procedure BA11003_0 is
   I : Integer := 1;
begin
   I := I + I;
   -- Real body of procedure goes here.
end BA11003_0;
