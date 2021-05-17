-- B83024F0M.ADA

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
-- OBJECTIVE:
--     IF A DECLARATION IN THE DECLARATIVE REGION OF A GENERIC PACKAGE
--     HIDES AN OUTER DECLARATION OF A HOMOGRAPH, THEN CHECK THAT A USE
--     OF THE COMMON IDENTIFIER WHICH WOULD BE A LEGAL REFERENCE TO THE
--     OUTER DECLARATION MUST BE REJECTED IF IT IS ILLEGAL AS A
--     REFERENCE TO THE INNER, IF THE GENERIC PACKAGE BODY IS SEPARATELY
--     COMPILED, BUT NOT AS A SUBUNIT.

-- APPLICABILITY CRITERIA:
--     THIS TEST IS APPLICABLE TO ALL ADA 95 IMPLEMENTATIONS.

-- TEST FILES:
--      THIS TEST CONSISTS OF THE FOLLOWING FILES:
--      -> B83024F0M.ADA - (THIS FILE) MAIN PROGRAM.
--         B83024F1.ADA -- PACKAGE BODY FOR B83024F_P1.
--         B83024F2.ADA -- PACKAGE BODY FOR B83024F_P2.
--         B83024F3.ADA -- PACKAGE BODY FOR B83024F_P3.

-- HISTORY:
--     BCB 08/30/88  CREATED ORIGINAL TEST.
--     LDC 10/10/90  SPLIT PACKAGE BODIES INTO SEPARATE FILES.
--     PWN 12/27/94  ADDED A PROCEDURE TO KEEP PACKAGE BODIES LEGAL.
--     RLB 09/13/99  UPDATED APPLICABILITY CRITERIA AND HEADERS FOR ADA 95.

GENERIC
     TYPE T IS PRIVATE;
     X : T;
FUNCTION B83024F_GEN_FUN RETURN T;
