-- C393012.A
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
--     Check that a non-abstract subprogram of an abstract type can be
--     called with a controlling operand that is a type conversion to
--     the abstract type.
--
--     Check that converting to the class-wide type of an abstract type
--     inside an operation of that type causes a "redispatch" of the
--     called operation.
--
-- TEST DESCRIPTION:
--     This test defines an abstract type, and further derives types from it.
--     The key feature of this test is in the "Display" procedures where
--     the bodies of these procedures convert an object to the class-wide
--     type of the root abstract type, causing a "redispatch".
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Dec 94   SAIC    Add allocation to the object initializations
--
--!

package C393012_0 is

  subtype Row_Number  is Positive  range 1..120;
  subtype Seat_Letter is Character range 'A'..'M';

  type Ticket is abstract tagged
    record
      Flight : Natural;
      Row    : Row_Number;
      Seat   : Seat_Letter;
    end record;

   function Display( T: Ticket ) return String;
   function Service( T: Ticket ) return String is abstract;

end C393012_0;
