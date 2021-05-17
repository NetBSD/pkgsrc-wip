-- B394A03.A
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
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--*
--
-- OBJECTIVE:
--      Check that a type derived from a task interface must be either a
--      task interface, task type, or a private extension.
--
--      Check that a private extension cannot be derived from both a
--      task interface and a protected interface.
--
-- TEST DESCRIPTION:
--      Try a task interface in each possible kind of non-task interface list:
--          interface definitions;
--          derived type extensions;
--          private type extensions;
--          protected types;
--          single protected objects;
--          formal derived type extensions;
--          formal interface definitions.
--      Also, try private extensions and formal private extensions derived from
--      both a task type and a protected type.
--
-- CHANGE HISTORY:
--     29 Oct 2007 RLB Created test.
--     05 Dec 2008 RLB Corrected declarations that violate 7.3(7.1/2) and
--                     12.5.1(5/2).
--
with F394A00;
package B394A03 is

    type Interf01 is interface and F394A00.Task_Interface;           -- ERROR:
    type Interf02 is limited interface and F394A00.Task_Interface;   -- ERROR:
    type Interf03 is synchronized interface
                             and F394A00.Task_Interface;             -- ERROR:
    type Interf04 is task interface and F394A00.Task_Interface;      -- OK.
    type Interf05 is protected interface and F394A00.Task_Interface; -- ERROR:
    type Interf06 is limited interface and F394A00.Lim_Interface
                             and F394A00.Task_Interface;             -- ERROR:

    type Der01 is limited new F394A00.Lim_Interface
                   and F394A00.Task_Interface with null record;      -- ERROR:
    type Der02 is limited new Interf04
                   and F394A00.Lim_Interface with null record;       -- ERROR:
    type Der03 is limited new F394A00.Task_Interface
                                              with null record;      -- ERROR:

    type Priv01 is synchronized new F394A00.Lim_Interface
                   and F394A00.Task_Interface with private;          -- OK.
    type Priv02 is synchronized new Interf04
                   and F394A00.Lim_Interface with private;           -- OK.
    type Priv03 is synchronized new F394A00.Task_Interface
                                              with private;          -- OK.
    type Priv04 is synchronized new F394A00.Task_Interface
                     and F394A00.Prot_Interface with private;        -- ERROR:
        -- A private extension derived from both protected and task types.

    task type Tsk01 is new F394A00.Task_Interface with end Tsk01;    -- OK.
    task Tsk02 is new F394A00.Sync_Interface
                  and F394A00.Task_Interface with end Tsk02;         -- OK.

    protected type Prot01 is new F394A00.Task_Interface with
                                                      end Prot01;    -- ERROR:
    protected Prot02 is new Interf04 with end Prot02;                -- ERROR:
    protected type Prot03 is new F394A00.Prot_Interface
                                    and Interf04 with end Prot03;    -- ERROR:

    generic
        type GInterf01 is interface and F394A00.Task_Interface;      -- ERROR:
        type GInterf02 is limited interface
                                       and F394A00.Task_Interface;   -- ERROR:
        type GInterf03 is synchronized interface
                                 and F394A00.Task_Interface;         -- ERROR:
        type GInterf04 is task interface and F394A00.Task_Interface; -- OK.
        type GInterf05 is protected interface and
                                             F394A00.Task_Interface; -- ERROR:

        type GDer01 is synchronized new F394A00.Task_Interface
                                                with private;        -- OK.
        type GDer02 is synchronized new Interf04 and F394A00.Task_Interface
                                                with private;        -- OK.
        type GDer03 is synchronized new F394A00.Prot_Interface
                     and F394A00.Task_Interface with private;        -- ERROR:
            -- A private extension derived from both protected and task types.

    package Bad is
        type Interf01 is interface and F394A00.Task_Interface;       -- ERROR:
        type Interf02 is limited interface
                                 and F394A00.Task_Interface;         -- ERROR:
        type Interf03 is protected interface and GInterf04;          -- ERROR:

        type Der01 is limited new Interf04 and F394A00.Lim_Interface
                                                with null record;    -- ERROR:
        type Der02 is limited new F394A00.Lim_Interface
                  and F394A00.Task_Interface with null record;       -- ERROR:
        type Der03 is limited new GInterf04 with null record;        -- ERROR:

        type Priv01 is synchronized new GInterf04
                         and F394A00.Prot_Interface with private;    -- ERROR:
            -- A private extension derived from both protected and task types.
    private
        type Interf04 is synchronized interface
                               and F394A00.Task_Interface;           -- ERROR:
        type Interf05 is protected interface
                             and F394A00.Task_Interface;             -- ERROR:
        type Interf06 is limited interface and GInterf04;            -- ERROR:
        type Der04 is limited new GInterf04 with null record;        -- ERROR:
        type Der05 is limited new F394A00.Task_Interface
                       and F394A00.Lim_Interface with null record;   -- ERROR:
        task type Priv01 is new GInterf04
           and F394A00.Prot_Interface with end Priv01;-- OPTIONAL ERROR: Previously reported.
    end Bad;
private
    task type Priv01 is new F394A00.Lim_Interface
                   and F394A00.Task_Interface with end Priv01;       -- OK.
    task type Priv02 is new Interf04
                   and F394A00.Lim_Interface with end Priv02;        -- OK.
    task type Priv03 is new F394A00.Task_Interface with end Priv03;  -- OK.
    task type Priv04 is new F394A00.Task_Interface
       and F394A00.Prot_Interface with end Priv04;   -- OPTIONAL ERROR: Previously reported.
end B394A03;
