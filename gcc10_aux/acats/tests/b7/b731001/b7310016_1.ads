-- B7310010.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE
--     Check the requirements of 7.3.1 for inheritance of characteristics and
--     primitive operations, including characteristics and operations that
--     become available later in the declarative part.
--     The test cases here are inspired by the AARM examples given
--     in AARM-7.3.1(7.a-7.v).
--
-- TEST DESCRIPTION
--     See AARM-7.3.1.
--     Never mind that many of the calls here would raise Program_Error
--     if they were executed, because the function body has not yet been
--     elaborated.
--
-- TEST FILES:
--      This test consists of the following files:
--      -> B7310010.A
--         B7310011.A
--         B7310012.A
--         B7310013.A
--         B7310014.A
--         B7310015.A
--         B7310016.AM
--
-- PASS/FAIL CRITERIA:
--      Files B7310011.A, B7310012.A, B7310013.A, B7310014.A, and B7310015.A
--      contain errors. All errors in these files must be detected to pass the
--      test.
--
-- CHANGE HISTORY:
--      29 JUN 1999   RAD   Initial Version.
--      16 DEC 1999   RLB   Revised to insure that units don't depend on other
--                          units containing errors.
--!

package B7310016_1 is
    -- Root package for the whole test.
    pragma Pure;

    type Enum is (Just_One_Literal);
    function Bool_Op(B: Boolean) return Enum;

private
    type Another_Enum is (Just_One_Literal);
    function Bool_Op(B: Boolean) return Another_Enum;
end B7310016_1;
