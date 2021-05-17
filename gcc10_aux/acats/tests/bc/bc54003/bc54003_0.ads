-- BC54003.A
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
--      Check that, for a formal access-to-subprogram subtype, the
--      corresponding parameter and result types of the designated
--      profiles of the formal and actual must be the same. Specifically,
--      check for the case where the parameters in the profile of the formal
--      type are themselves formal types.
--
-- TEST DESCRIPTION:
--      Two profiles are subtype conformant if:
--         (a) They have the same number of parameters;
--         (b) Both have a result if either does;
--         (c) The corresponding parameter and result types are the same and
--             the subtypes statically match;
--         (d) Corresponding parameters have identical modes and both or
--             neither are explicitly aliased parameters;
--         (e) For access parameters, the designated subtypes statically
--             match;
--         (f) The associated calling conventions are the same.
--
--      The test declares generics with formal access-to-subprogram types
--      (access-to-procedure and access-to-function). Access-to-subprogram
--      types are declared to be passed as actuals, each with a designated
--      profile in which the parameter/result types are the same as, are
--      subtypes of, or are derived types of the parameter/result types in
--      the profile of the formal. Cases where the types are explicitly the
--      same or where one is a subtype of the other are legal, whereas cases
--      where one type is derived from the other are illegal.
--
--      Note: Ada 95 only required mode conformance in this case. This
--      was changed by AI05-0288-1.
--
--      The following situations are checked:
--
--         - A parameter type in the profile of the formal access-to-subprogram
--           type is an abstract formal derived type declared in the same
--           formal part.
--         - A parameter type in the profile of the formal access-to-subprogram
--           type is a formal private type declared in the same formal part.
--         - A parameter type in the profile of the formal access-to-subprogram
--           type is a formal discrete type declared in the formal part of
--           a formal package (one level of indirection).
--         - A parameter type in the profile of the formal access-to-subprogram
--           type is a formal array type declared in the formal part of
--           a formal package, which is itself declared in the formal part of
--           a formal package (two levels of indirection).
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      05 Nov 95   SAIC    ACVC 2.0.1 fixes: Added unknown discriminant part
--                          to generic BC54003_3.Formal_Derived_Parameter.
--      25 Mar 13   RLB     Modified as AI05-0288-1 requires subtype conformance
--                          in this case. Conflicting cases are commented out.
--      06 Mar 14   RLB     Replaced above cases as errors.
--
--!

package BC54003_0 is

--
-- Support declarations:
--

   type Parent is abstract tagged null record;

   -- ...(Abstract) operations of Parent type.


   type Child is new Parent with record
      Component : Integer;
   end record;

   -- ...(Overriding) operations of Child type.


   type Child_Op_Ptr is access                     -- Access-to-subprogram type
     procedure (Parm: in Child);                   -- to be passed as actual.

   type Class_Op_Ptr is access                     -- Access-to-subprogram type
     procedure (Parm: in Parent'Class);            -- to be passed as actual.



   subtype Message   is     String (1 .. 25);
   subtype Short_Msg is     String (1 .. 10);
   type New_String   is new String (1 .. 25);

   type String_Op_Ptr  is access                   -- Access-to-subprogram type
     procedure (Parm: in out String);              -- to be passed as actual.

   type Message_Op_Ptr is access                   -- Access-to-subprogram type
     procedure (Parm: in out Message);             -- to be passed as actual.

end BC54003_0;
