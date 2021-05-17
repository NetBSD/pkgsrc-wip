-- B3A2006.A
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
--      Check that, for P'Access of an access-to-subprogram type S, the
--      accessibility level of the subprogram denoted by P must not be
--      statically deeper than that of S.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      subprogram P must be at the same or a less deep nesting level than the
--      access-to-subprogram type S -- P must "live" as long as S. Nesting
--      levels are the run-time nestings of masters: block statements;
--      subprogram, task, and entry bodies; and accept statements. Packages
--      are invisible to accessibility rules.
--
--      The language rules imply that downward closures (passing the identity
--      of a more nested subprogram to a less nested subprogram) using
--      P'Access are not supported. To illustrate this, the test constructs a
--      series of iterator abstractions at various levels of nesting. Each
--      ERROR case is an attempted downward closure.
--
--      Cases where P is defined by a renaming declaration are included.
--
--      If P is a view of a subprogram defined by a renaming declaration, its
--      accessibility level is that of the renamed view.
--
--      Accessibility is checked in two contexts: P'Access is passed as an
--      actual to a subprogram (the downward closure examples); P'Access is
--      assigned to an access object.
--
--      The nesting structure is as follows:
--
--          - Library-level package                          (Level = 0)
--         |
--          - end package
--
--          - Library-level procedure (to be designated)     (Level = 0)
--         |
--          - end procedure
--
--          - Library-level function
--         |     - Nested procedure (to be designated)       (Level = 1)
--         |    |
--         |     - end procedure
--         |
--         |     - Nested task
--         |    |     - Nested procedure (to be designated)  (Level = 2)
--         |    |    |
--         |    |     - end procedure
--         |    |  begin
--         |    |     *** testing here
--         |     - end task
--         |  begin          
--         |     *** testing here
--          - end function
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package B3A2006_0 is

   type Integer_Set is private;

   type Integer_Action_L0 is access procedure (I : Integer);     -- Level = 0.

   procedure Iterate_L0 (S      : Integer_Set; 
                         Action : Integer_Action_L0);

   Result_L0 : Natural := 0;

private

   type Integer_Set is new Integer range -1000..1000;

end B3A2006_0;
