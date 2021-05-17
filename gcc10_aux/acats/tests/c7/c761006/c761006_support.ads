-- C761006.A
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
--      Check that Program_Error is raised when:
--        * an exception is raised if Finalize invoked as part of an
--          assignment operation; or
--        * an exception is raised if Adjust invoked as part of an assignment
--          operation, after any other adjustment due to be performed are
--          performed; or
--        * an exception is raised if Finalize invoked as part of a call on
--          Unchecked_Deallocation, after any other finalizations to be
--          performed are performed.
--
-- TEST DESCRIPTION:
--      This test defines these four controlled types:
--        Good
--        Bad_Initialize
--        Bad_Adjust
--        Bad_Finalize
--      The type name conveys the associated failure.  The operations in type
--      good will "touch" the boolean array indicating correct path
--      utilization for the purposes of checking "other <operations> are
--      performed", where <operations> ::= initialization, adjusting, and
--      finalization
--
--
--
-- CHANGE HISTORY:
--      12 APR 94   SAIC   Initial version
--      02 MAY 96   SAIC   Visibility fixed for 2.1
--      13 FEB 97   PWB.CTA Corrected value of Events_Occurring at line 286
--      01 DEC 97   EDS    Made correction wrt RM 7.6(21)
--      16 MAR 01   RLB    Corrected Adjust cases to avoid problems with
--                         RM 7.6.1(16/1) from Technical Corrigendum 1.
--      05 JUL 12   RLB    Redid Unchecked_Deallocation case to handle
--                         the fact that the behavior is unspecified (see
--                         AI95-0179-1). Also fixed indentation.
--
--!

------------------------------------------------------------- C761006_Support

package C761006_Support is

  type Events is ( Good_Initialize, Good_Adjust, Good_Finalize );

  type Event_Array is array(Events) of Boolean;

  Events_Occurring : Event_Array := (others => False);

  Propagating_Exception : exception;

  procedure Raise_Propagating_Exception(Do_It: Boolean);

  function Unique_Value return Natural;

end C761006_Support;
