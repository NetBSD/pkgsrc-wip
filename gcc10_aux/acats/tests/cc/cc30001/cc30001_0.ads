-- CC30001.A
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
--      Check that if a non-overriding primitive subprogram is declared for
--      a type derived from a formal derived tagged type, the copy of that
--      subprogram in an instance can override a subprogram inherited from the
--      actual type.
--
-- TEST DESCRIPTION:
--      User writes program to handle both mail messages and system messages.
--
--      Mail messages are created by instantiating a generic "mail" package
--      with a root message type. System messages are created by
--      instantiating the generic with a system message type derived from the
--      root in a separate package. The system message type has a primitive
--      subprogram called Send.
--
--      Inside the generic, a "mail" type is derived from the generic formal
--      derived type, and a "Send" operation is declared.
--
--      Declare a root tagged type T. Declare a generic package with a formal
--      derived type using the root tagged type as ancestor. In the generic,
--      derive a type from the formal derived type and declare a primitive
--      subprogram for it. In a separate package, declare a derivative DT of
--      the root tagged type T and declare a primitive subprogram which is
--      type conformant with (and hence, overridable for) the primitive
--      declared in the generic. Instantiate the generic for DT. Make both
--      dispatching and non-dispatching calls to the primitive subprogram. In
--      both cases the version of the subprogram in the instance should be
--      called (since it overrides the implementation inherited from the
--      actual).
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Apr 95   SAIC    Replaced call involving instance for root tagged
--                          type with a dispatching call involving instance
--                          for derived type. Updated commentary. Moved
--                          instantiations (and related commentary) to
--                          library-level to avoid accessibility violation.
--                          Commented out instantiation for root tagged type.
--      27 Feb 97   PWB.CTA Added elaboration pragma.
--!

package CC30001_0 is  -- Root message type.

   type Msg_Type is tagged record
      Text         : String (1 .. 20);
      Message_Sent : Boolean;
   end record;

end CC30001_0;
