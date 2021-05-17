-- BC51015.A
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
--      Check that if the actual type corresponding to a non-tagged formal
--      private type is tagged, an instance is illegal if a (non-tagged)
--      derived type is declared in the visible part. Check that an instance
--      is legal if the derived type is declared in the private part or in
--      the body.
--
-- TEST DESCRIPTION:
--      Legality rules are (generally) rechecked in the visible part of an
--      instance, but not in the private part or the body. In this case, the
--      parent type of the derived type is tagged, and the legality rules
--      require that the derived type have a record_extension_part; it does
--      not. Therefore, if the derived type is declared in the visible part
--      (where the rule is rechecked), the instance is illegal. However, if
--      the derived type is declared in the private part or body (where the
--      rule is not rechecked), the instance is legal.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package BC51015_0 is

   type Tagged_Type is tagged record
      Component : Integer := 6;
   end record;

   procedure Primitive (Parm : Tagged_Type);

   type Private_Ext is new Tagged_Type with private;

private
   type Private_Ext is new Tagged_Type with null record;
end BC51015_0;
