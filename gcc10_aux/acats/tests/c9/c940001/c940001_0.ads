-- C940001.A
--
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
--      Check that a protected object provides coordinated access to
--      shared data.  Check that it can be used to sequence a number of tasks.
--      Use the protected object to control a single token for which three 
--      tasks compete.  Check that only one task is running at a time and that
--      all tasks get a chance to run sometime.
--
-- TEST DESCRIPTION:
--      Declare a protected type with two entries.  A task may call the Take
--      entry to get a token which allows it to continue processing.  If it 
--      has the token, it may call the Give entry to return it.  The tasks 
--      implement a discipline whereby only the task with the token may be 
--      active.  The test does not require any specific order for the tasks 
--      to run.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      07 Jul 96   SAIC    Fixed spelling nits.
--
--!

package C940001_0 is

  type Token_Type is private;
  True_Token : constant Token_Type;   -- Create a deferred constant in order 
                                      -- to provide a component init for the
                                      -- protected object

  protected type Token_Mgr_Prot_Unit is
    entry Take (T : out Token_Type);
    entry Give (T : in out  Token_Type);
  private
    Token : Token_Type := True_Token;
  end Token_Mgr_Prot_Unit;

  function Init_Token return Token_Type;   -- call to initialize an 
                                           -- object of Token_Type
  function Token_Value (T : Token_Type) return Boolean;
                                           -- call to inspect the value of an
                                           -- object of Token_Type
private
  type Token_Type is new boolean;
  True_Token : constant Token_Type := true;
end C940001_0;
