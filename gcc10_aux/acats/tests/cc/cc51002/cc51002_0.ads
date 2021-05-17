-- CC51002.A
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
--      Check that, for formal derived tagged types, the formal parameter
--      names and default expressions for a primitive subprogram in an
--      instance are determined by the primitive subprogram of the ancestor
--      type, but that the primitive subprogram body executed is that of the
--      actual type.
--
-- TEST DESCRIPTION:
--      Define a root tagged type in a library-level package and give it a
--      primitive subprogram. Provide a default expression for a non-tagged
--      parameter of the subprogram. Declare a library-level generic subprogram
--      with a formal derived type using the root type as ancestor. Call
--      the primitive subprogram of the root type using named association for
--      the tagged parameter, and provide no actual for the defaulted
--      parameter. Extend the root type in a second package and override the
--      root type's subprogram with one which has different parameter names
--      and no default expression for the non-tagged parameter. Instantiate
--      the generic subprogram for each of the tagged types in the class and
--      call the instances.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CC51002_0 is  -- Root message type and operations.

   type Recipients is (None, Root, Sysop, Local, Remote);

   type Msg_Type is tagged record                             -- Root type of
      Text : String (1 .. 10);                                -- class.
   end record;

   function Send (Msg : in Msg_Type;                          -- Primitive
                  To  : Recipients := Local) return Boolean;  -- subprogram.

   -- ...Other message operations.

end CC51002_0;
