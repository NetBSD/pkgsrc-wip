-- CD90001.A
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
--      Check that Unchecked_Conversion is supported and is reversible in
--      the cases where:
--        Source'Size = Target'Size
--        Source'Alignment = Target'Alignment
--        Source and Target are both represented contiguously
--        Bit pattern in Source is a meaningful value of Target type
--
-- TEST DESCRIPTION:
--      This test declares an enumeration type with a representation
--      specification that should fit neatly into an 8 bit object; and a
--      modular type that should also be able to fit easily into 8 bits;
--      uses size representation clauses on both of them for 8 bit
--      representations.  It then defines two instances of
--      Unchecked_Conversion; to convert both ways between the types.
--      Using several distinctive values, it checks that the conversions
--      are performed, and reversible.
--      As a second case, the above is performed with an integer type and
--      a packed array of booleans.
--
-- APPLICABILITY CRITERIA:
--      All implementations must attempt to compile this test.
--
--      For implementations validating against Systems Programming Annex (C):
--        this test must execute and report PASSED.
--
--      For implementations not validating against Annex C:
--        this test may report compile time errors at one or more points
--        indicated by "-- ANX-C RQMT", in which case it may be graded as inapplicable.
--        Otherwise, the test must execute and report PASSED.
--
--
-- CHANGE HISTORY:
--      22 JUL 95   SAIC   Initial version
--      07 MAY 96   SAIC   Changed Boolean to Character for 2.1
--      27 JUL 96   SAIC   Allowed for partial N/A to be PASS
--      14 FEB 97   PWB.CTA  Corrected "=" to "/=" in alignment check.
--      16 FEB 98   EDS    Modified documentation.
--      21 DEC 05   RLB    Corrected "=" to "/=" in other alignment check.
--!

----------------------------------------------------------------- CD90001_0

with Report;
with Unchecked_Conversion;
package CD90001_0 is

  -- Case 1 : Modular <=> Enumeration

  type Eight_Bits is mod 2**8;
    for Eight_Bits'Size use 8;

  type User_Enums is ( One, Two, Four, Eight,
                       Sixteen, Thirty_Two, Sixty_Four, One_Twenty_Eight );
    for User_Enums'Size use 8;

    for User_Enums use
                    ( One              =>   1,                -- ANX-C RQMT.
                      Two              =>   2,                -- ANX-C RQMT.
                      Four             =>   4,                -- ANX-C RQMT.
                      Eight            =>   8,                -- ANX-C RQMT.
                      Sixteen          =>  16,                -- ANX-C RQMT.
                      Thirty_Two       =>  32,                -- ANX-C RQMT.
                      Sixty_Four       =>  64,                -- ANX-C RQMT.
                      One_Twenty_Eight => 128 );              -- ANX-C RQMT.

  function EB_2_UE is new Unchecked_Conversion( Eight_Bits, User_Enums );

  function UE_2_EB is new Unchecked_Conversion( User_Enums, Eight_Bits );

  procedure TC_Check_Case_1;

  -- Case 2 : Integer <=> Packed Character array

  type Signed_16 is range -2**15+1 .. 2**15-1;
  -- +1, -1 allows for both 1's and 2's comp

  type Bits_16 is array(0..1) of Character;
  pragma Pack(Bits_16);                                       -- ANX-C RQMT.

  function S16_2_B16 is new Unchecked_Conversion( Signed_16, Bits_16 );

  function B16_2_S16 is new Unchecked_Conversion( Bits_16, Signed_16 );

  procedure TC_Check_Case_2;

end CD90001_0;
