-- B394A05.A
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
--      Check that a type derived from a synchronized interface must be one
--      of a task, protected, or synchronized interface, protected type,
--      task type, or a private extension.
--
-- TEST DESCRIPTION:
--      Try a synchronized interface in each possible kind of interface list:
--          interface definitions;
--          derived type extensions;
--          private type extensions;
--          task types;
--          single task objects;
--          protected types;
--          single protected objects;
--          formal derived type extensions;
--          formal interface definitions.
--      Also, try private extensions and formal private extensions derived from
--      both a task type and a protected type.
--
-- CHANGE HISTORY:
--     30 Oct 2007 RLB Created test.
--     05 Dec 2008 RLB Corrected declarations that violate 7.3(7.1/2) and
--                     12.5.1(5/2).
--
with F394A00;
package B394A05 is

    type Interf01 is interface and F394A00.Sync_Interface;           -- ERROR:
    type Interf02 is limited interface and F394A00.Sync_Interface;   -- ERROR:
    type Interf03 is synchronized interface
                             and F394A00.Sync_Interface;             -- OK.
    type Interf04 is task interface and F394A00.Sync_Interface;      -- OK.
    type Interf05 is protected interface and F394A00.Sync_Interface; -- OK.
    type Interf06 is limited interface and F394A00.Lim_Interface
                             and F394A00.Sync_Interface;             -- ERROR:

    type Der01 is limited new F394A00.Lim_Interface
                   and F394A00.Sync_Interface with null record;      -- ERROR:
    type Der02 is limited new Interf03
                   and F394A00.Lim_Interface with null record;       -- ERROR:
    type Der03 is limited new F394A00.Sync_Interface
                                              with null record;      -- ERROR:

    type Priv01 is synchronized new F394A00.Lim_Interface
                   and F394A00.Sync_Interface with private;          -- OK.
    type Priv02 is synchronized new Interf03
                   and F394A00.Lim_Interface with private;           -- OK.
    type Priv03 is synchronized new F394A00.Sync_Interface
                                              with private;          -- OK.

    task type Tsk01 is new F394A00.Sync_Interface with end Tsk01;    -- OK.
    task Tsk02 is new F394A00.Sync_Interface
                  and F394A00.Sync_Interface with end Tsk02;         -- OK.
    task Tsk03 is new Interf03 with end Tsk03;                       -- OK.
    task type Tsk04 is new F394A00.Task_Interface
                                    and Interf03 with end Tsk04;     -- OK.

    protected type Prot01 is new F394A00.Sync_Interface with
                                                      end Prot01;    -- OK.
    protected Prot02 is new Interf03 with end Prot02;                -- OK.
    protected type Prot03 is new F394A00.Sync_Interface
                                    and Interf03 with end Prot03;    -- OK.

    generic
        type GInterf01 is interface and F394A00.Sync_Interface;      -- ERROR:
        type GInterf02 is limited interface
                                       and F394A00.Sync_Interface;   -- ERROR:
        type GInterf03 is synchronized interface
                                 and F394A00.Sync_Interface;         -- OK.
        type GInterf04 is task interface and F394A00.Sync_Interface; -- OK.
        type GInterf05 is protected interface and
                                             F394A00.Sync_Interface; -- OK.

        type GDer01 is synchronized new F394A00.Sync_Interface
                                                with private;        -- OK.
        type GDer02 is synchronized new Interf03 and F394A00.Sync_Interface
                                                with private;        -- OK.

    package Bad is
        type Interf01 is interface and F394A00.Sync_Interface;       -- ERROR:
        type Interf02 is limited interface
                                 and F394A00.Sync_Interface;         -- ERROR:
        type Interf03 is task interface and GInterf03;               -- OK.
        type Interf04 is limited interface and GInterf03;            -- ERROR:

        type Der01 is limited new Interf03 and F394A00.Lim_Interface
                                                with null record;    -- ERROR:
        type Der02 is limited new F394A00.Lim_Interface
                  and F394A00.Sync_Interface with null record;       -- ERROR:
        type Der03 is limited new GInterf03 with null record;        -- ERROR:

    private
        type Interf05 is synchronized interface
                               and F394A00.Sync_Interface;           -- OK.
        type Interf06 is limited interface
                             and F394A00.Sync_Interface;             -- ERROR:
        type Interf07 is limited interface and GInterf04;            -- ERROR:
        type Der04 is limited new GInterf03 with null record;        -- ERROR:
        type Der05 is limited new F394A00.Sync_Interface
                       and F394A00.Lim_Interface with null record;   -- ERROR:
    end Bad;
private
    protected type Priv01 is new F394A00.Lim_Interface
                   and F394A00.Sync_Interface with end Priv01;       -- OK.
    protected type Priv02 is new Interf03
                   and F394A00.Lim_Interface with end Priv02;        -- OK.
    protected type Priv03 is new F394A00.Sync_Interface with
                                                  end Priv03;        -- OK.
end B394A05;
