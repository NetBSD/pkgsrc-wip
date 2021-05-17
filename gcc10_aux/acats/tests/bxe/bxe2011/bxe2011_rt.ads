-- BXE2011.A
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
--      Check that a value of a remote access-to-subprogram type can only
--      be converted to another conformant remote access-to-subprogram type.
--      Check that the prefix of an access attribute_reference that yields 
--      a value of a remote access-to-subprogram type shall statically
--      denote a conformant remote subprogram.
--      Check that a value of a remote access-to-class-wide type can only 
--      be converted to another remote access-to-class-wide type.
--      Check that the Storage_Pool and Storage_Size attributes are not
--      defined for remote access-to-class-wide types.
--
-- TEST DESCRIPTION:
--      This test consists of a Remote_Types package, a Remote_Call_Interface
--      package and a normal package.  
--      The Remote_Types and RCI packages contains declarations of remote access
--      types and are expected to compile without error.  The normal package
--      contains additional declarations and a selection of both legal
--      and illegal uses of the remote types.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations:
--          supporting the Distribution Annex, and
--          supporting the Remote_Call_Interface pragma.
--
--
-- CHANGE HISTORY:
--      25 APR 95   SAIC    Initial version
--      12 APR 99   RLB     Repaired to properly check conversion of remote
--                          access types.
--!
 
package BXE2011_RT is
  -- This package specification should compile without error
  pragma Remote_Types;

  -- the following types are remote access types  
  type NoParmPtr is access procedure;
  type OneParmPtr is access procedure (X : Integer);

  -- the following procedures are NOT remote procedures
  procedure None;
  procedure One (P : Integer);
  
  -- tagged types
  type Tagged_Type is tagged limited private;
  procedure TT_Proc (TT : access Tagged_Type);

  -- remote access to class wide type
  type Class_Wide_Ptr is access all Tagged_Type'Class;
 
private
  type Tagged_Type is
    tagged limited record
       B_Field : Boolean;
    end record;
end BXE2011_RT;
