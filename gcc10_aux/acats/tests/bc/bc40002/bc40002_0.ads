-- BC40002.A
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
--      Check that, for a generic formal object of mode in:
--         - If the formal object is of tagged type T, the type of the actual
--           must be T.
--         - If the formal object is of type T'Class, the type of the actual
--           must be a type in that class.
--
--      Check that, for a generic formal object of mode in out:
--         - If the formal object is of tagged type T, the type of the actual
--           must be T.
--         - If the formal object is of type T'Class, the type of the actual
--           must be T'Class.
--
-- TEST DESCRIPTION:
--      Declare a tagged type PT, type extension T, and a type DT derived from
--      T.  Declare formal objects of modes in and in out, and test the 
--      following combinations of types for the formal and actual objects:
--
--         Mode of | Type of  | Type of  |
--         Formal  |  Formal  |  Actual  | Legal?
--         --------------------------------------
--           In    |    T     |    T     |   Y
--                 |          |    PT    |   N
--                 |          |    DT    |   N
--                 |          | T'Class  |   N
--                 |          | DT'Class |   N
--         --------|----------|----------|-------
--           In    | T'Class  |    T     |   Y
--                 |          |    PT    |   N
--                 |          |    DT    |   Y
--                 |          | T'Class  |   Y
--                 |          | DT'Class |   Y
--         --------|----------|----------|-------
--          In Out |    T     |    T     |   Y
--                 |          |    PT    |   N
--                 |          |    DT    |   N
--                 |          | T'Class  |   N
--                 |          | DT'Class |   N
--         --------|----------|----------|-------
--          In Out | T'Class  |    T     |   N
--                 |          |    PT    |   N
--                 |          |    DT    |   N
--                 |          | T'Class  |   Y
--                 |          | DT'Class |   N
--         --------------------------------------
--
--
-- CHANGE HISTORY:
--      02 Feb 95   SAIC    Initial version.
--
--!

package BC40002_0 is

   type PT is tagged record
      C : Boolean := True;
   end record;

   type T is new PT with record
      C1 : Integer := 0;
   end record;

   type DT is new T with record
      C2 : String (1 .. 100) := (others => ' ');
   end record;

end BC40002_0;
