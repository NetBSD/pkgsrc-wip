-- C94004C.ADA

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
-- CHECK THAT A MAIN PROGRAM TERMINATES WITHOUT WAITING FOR TASKS THAT
-- DEPEND ON A LIBRARY PACKAGE AND THAT SUCH TASKS ARE NOT TERMINATED BY
-- MAIN PROGRAM TERMINATION.

-- CASE C:  TASK OBJECT DECLARED IN LIBRARY PACKAGE USED BY MAIN PROGRAM
--          AND WAITING AT A SELECTIVE WAIT WITH TERMINATE.

-- JRK 10/8/81
-- SPS 11/21/82
-- JBG 12/6/84
-- JRK 11/21/85  RENAMED FROM C94004C-B.ADA; REVISED ACCORDING TO
--               AI-00399.
-- JRK 10/24/86  RENAMED FROM E94004C-B.ADA; REVISED ACCORDING TO
--               REVISED AI-00399.
-- PWN 09/11/94  REMOVED PRAGMA PRIORITY FOR ADA 9X.
-- RLB 06/28/19  Replaced excessive delays with Impdef constants.

WITH SYSTEM; USE SYSTEM;
PACKAGE C94004C_PKG IS

     TASK TYPE TT IS
          ENTRY E;
     END TT;

END C94004C_PKG;
