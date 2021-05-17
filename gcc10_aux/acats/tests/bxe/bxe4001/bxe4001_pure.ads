-- BXE4001.A
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
--      Check that pragma Asynchronous can only be applied to one of
--      the following three categories of items:
--      Remote procedures where the formal parameters of the procedures
--      are all of mode in;
--      The first subtype of a remote access-to-procedure type where 
--      the formal parameters of the designated profile of the type 
--      are all of mode in;
--      Remote access-to-class-wide types.
--
-- TEST DESCRIPTION:  
--      This test consists of 4 package specifications.  
--      The first package is a pure package providing declarations
--      that are used by the other packages.  This is the only package
--      that is expected to compile without error.
--      The remaining packages consist of a normal package, a remote types
--      package, and a remote call interface package.  These packages 
--      contain a selection of legal and illegal declarations.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Distribution Annex and the Remote_Call_Interface pragma.
--
--
-- CHANGE HISTORY:
--     20 JUN 95   SAIC    Initial version for 2.1
--     01 MAY 96   SAIC    Added additional test suggested by reviewers 
--     26 JUN 98   EDS     Created private part for last few lines of
--                         package BXE4001_Types so access type is legal.
--!

----------------------------------------------------------------------------

package BXE4001_Pure is
  -- this package should compile without error
  pragma Pure;

  type Tagged_Type_1 is tagged limited private;
  procedure Primitive_1a (T : access Tagged_Type_1);

  type Tagged_Type_2 is tagged limited private;
  procedure Primitive_2a (T : access Tagged_Type_2;  X : out Integer);
  function  Primitive_2b (T : access Tagged_Type_2) return Boolean;

private
  type Tagged_Type_1 is tagged limited record
      Component : Character;
    end record;
  type Tagged_Type_2 is tagged limited record
      Component : Character;
    end record;
end BXE4001_Pure;
