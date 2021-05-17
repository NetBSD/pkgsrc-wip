-- C410001.A
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
--      Check that evaluating an access to subprogram variable containing
--      the value null causes the exception Constraint_Error.
--      Check that the default value for objects of access to subprogram
--      types is null.
--
-- TEST DESCRIPTION:
--      This test defines a few simple access_to_subprogram types, and
--      objects of those types.  It checks that the default values for
--      these objects is null, and that an attempt to make a subprogram
--      call via one of this objects containing a null value causes the
--      predefined exception Constraint_Error.  The check is performed
---     both with the default null value, and with an explicitly assigned
--      null value, after the object has been used to successfully designate
--      and call a subprogram.
--
--
-- CHANGE HISTORY:
--      05 APR 96   SAIC   Initial version
--      04 NOV 96   SAIC   Revised for 2.1 release
--      26 FEB 97   PWB.CTA Initialized variable before passing to function
--!

----------------------------------------------------------------- C410001_0

package C410001_0 is

  -- used to "switch state" in the software
  Expect_Exception : Boolean;

  -- define a minimal mixture of access_to_subprogram types

  type Proc_Ref is access procedure;

  type Func_Ref is access function(I:Integer) return Integer;

  type Proc_Para_Ref is access procedure(P:Proc_Ref);

  type Func_Para_Ref is access function(F:Func_Ref) return Integer;

  type Prot_Proc_Ref is access protected procedure;

  type Prot_Func_Ref is access protected function return Boolean;

  -- define some subprograms for them to reference

  procedure Proc;

  function Func(I:Integer) return Integer;

  procedure Proc_Para( Param : Proc_Ref );

  function Func_Para( Param : Func_Ref ) return Integer;

  protected Prot_Obj is
    procedure Prot_Proc;
    function Prot_Func return Boolean;
  end Prot_Obj;

end C410001_0;
