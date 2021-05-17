-- LXD70011.A
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
--      See LXD70012.AM.
--
-- TEST FILES:
--      This test consists of the following files:
--          LXD70010.A     A text file with the Restrictions pragma
--       => LXD70011.A     A Library task with several children
--          LXD70012.AM    The main program
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Nov 95   SAIC    ACVC 2.0.1 - added hierarchy to tasks
--      30 Sep 96   SAIC    Multi-file prolog convention fix.
--      17 Feb 00   RLB     Corrected so test runs correctly if not rejected.
--      02 Feb 17   RLB     Added missing error tag (and location indicator).
--
--!

package  LXD70011 is

   task Driver_Control is
      entry Normal_Shut_Down;
      entry Disaster_Shut_Down;
   end Driver_Control;

end  LXD70011;
