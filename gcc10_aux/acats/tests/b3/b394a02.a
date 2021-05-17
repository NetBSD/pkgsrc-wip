-- B394A02.A
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
--      Check that a descendant of a non-limited interface cannot be limited.
--
-- TEST DESCRIPTION:
--      Try a non-limited interface in each kind of interface list for limited
--      types:
--          interface definitions;
--          derived type extensions;
--          private type extensions;
--          task types;
--          protected types;
--          single tasks;
--          single protected objects;
--          formal derived type extensions;
--          formal interface definitions.
--
-- CHANGE HISTORY:
--     29 Oct 2007 RLB Created test.
--     16 May 2008 RLB Corrected reference to wrong type.
--
with F394A00;
package B394A02 is

    type Interf01 is interface and F394A00.Non_Lim_Interface;        -- OK.
    type Interf02 is limited interface and F394A00.Non_Lim_Interface;-- ERROR:
    type Interf03 is synchronized interface
                                and F394A00.Non_Lim_Interface;       -- ERROR:
    type Interf04 is task interface and F394A00.Non_Lim_Interface;   -- ERROR:
    type Interf05 is protected interface and Interf01;               -- ERROR:

    type Der01 is new Interf01 and F394A00.Non_Lim_Interface
                                            with null record;        -- OK.
    type Der02 is limited new Interf01 and F394A00.Lim_Interface
                                            with null record;        -- ERROR:
    type Der03 is limited new F394A00.Lim_Interface and
                   F394A00.Non_Lim_Interface with null record;       -- ERROR:

    type Priv01 is new Interf01 and F394A00.Non_Lim_Interface
                                            with private;            -- OK.
    type Priv02 is limited new Interf01 and F394A00.Lim_Interface
                                            with private;            -- ERROR:
    type Priv03 is limited new F394A00.Lim_Interface and
                   F394A00.Non_Lim_Interface with private;           -- ERROR:
    type Priv04 is synchronized new Interf01 with private;           -- ERROR:
    type Priv05 is synchronized new F394A00.Non_Lim_Interface and
                   F394A00.Lim_Interface with private;               -- ERROR:

    task type Tsk01 is new F394A00.Non_Lim_Interface with end Tsk01; -- ERROR:
    task Tsk02 is new Interf01 with end Tsk02;                       -- ERROR:
    task type Tsk03 is new F394A00.Task_Interface and
              Interf01 with end Tsk03;                               -- ERROR:
    task Tsk04 is new F394A00.Non_Lim_Interface and
              F394A00.Task_Interface with end Tsk04;                 -- ERROR:

    protected type Prot01 is new F394A00.Non_Lim_Interface with
                                                         end Prot01; -- ERROR:
    protected Prot02 is new Interf01 with end Prot02;                -- ERROR:
    protected type Prot03 is new F394A00.Prot_Interface and
              Interf01 with end Prot03;                              -- ERROR:
    protected Prot04 is new F394A00.Non_Lim_Interface and
              F394A00.Prot_Interface with end Prot04;                -- ERROR:

    generic
        type GInterf01 is interface and F394A00.Non_Lim_Interface;   -- OK.
        type GInterf02 is limited interface
                                       and F394A00.Non_Lim_Interface;-- ERROR:
        type GInterf03 is synchronized interface
                                 and F394A00.Non_Lim_Interface;      -- ERROR:
        type GInterf04 is task interface
                                 and F394A00.Non_Lim_Interface;      -- ERROR:
        type GInterf05 is protected interface and GInterf01;         -- ERROR:

        type GDer01 is new GInterf01 and F394A00.Non_Lim_Interface
                                                with private;        -- OK.
        type GDer02 is limited new GInterf01 and F394A00.Lim_Interface
                                                with private;        -- ERROR:
        type GDer03 is limited new F394A00.Lim_Interface
                and F394A00.Non_Lim_Interface with private;          -- ERROR:
        type GDer04 is synchronized new GInterf01 with private;      -- ERROR:
        type GDer05 is synchronized new F394A00.Non_Lim_Interface
                                                  with private;      -- ERROR:

    package Bad is
        type Interf01 is limited interface
                                       and F394A00.Non_Lim_Interface;-- ERROR:
        type Interf02 is synchronized interface
                                    and F394A00.Non_Lim_Interface;   -- ERROR:
        type Der01 is limited new B394A02.Interf01
                      and F394A00.Lim_Interface with null record;    -- ERROR:
        type Der02 is limited new F394A00.Lim_Interface and
                       F394A00.Non_Lim_Interface with null record;   -- ERROR:
    private
        type Interf03 is task interface
                                    and F394A00.Non_Lim_Interface;   -- ERROR:
        type Interf04 is protected interface and GInterf01;          -- ERROR:
        type Der03 is limited new GInterf01 and F394A00.Lim_Interface
                                                with null record;    -- ERROR:
        type Der04 is limited new F394A00.Lim_Interface and GDer01
                                                with null record;    -- ERROR:
    end Bad;

private
    -- Completions of above. Any errors are optional as they are just
    -- repeating errors in the original declarations, and we don't
    -- require that they are given twice.

    type Priv01 is new Interf01 and F394A00.Non_Lim_Interface
                                            with null record;        -- OK.
    type Priv02 is limited new Interf01 and F394A00.Lim_Interface
                                 with null record;        -- OPTIONAL ERROR:
    type Priv03 is limited new F394A00.Lim_Interface and
        F394A00.Non_Lim_Interface with null record;       -- OPTIONAL ERROR:

    protected type Priv04 is new Interf01 with end Priv04;-- OPTIONAL ERROR:
    protected type Priv05 is new  F394A00.Non_Lim_Interface and
                   F394A00.Lim_Interface with end Priv05; -- OPTIONAL ERROR:

end B394A02;
