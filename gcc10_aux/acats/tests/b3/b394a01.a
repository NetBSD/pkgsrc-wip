-- B394A01.A
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
--      Check that the subtype named in an interface list must denote
--      an interface.
--
-- TEST DESCRIPTION:
--      Try each kind of type in an interface list. Especially try abstract
--         tagged types.
--      Try each kind of interface list:
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
--
with F394A00;
package B394A01 is

    type Interf01 is interface and F394A00.Non_Lim_Interface;        -- OK.
    type Interf02 is limited interface and F394A00.Lim_Interface;    -- OK.
    type Interf03 is synchronized interface
                             and F394A00.Sync_Interface;             -- OK.
    type Interf04 is task interface and F394A00.Task_Interface;      -- OK.
    type Interf05 is protected interface and F394A00.Prot_Interface; -- OK.
    type Interf06 is interface and F394A00.Abstract_Non_Lim_Record;  -- ERROR:
    type Interf07 is limited interface
                             and F394A00.Abstract_Lim_Record;        -- ERROR:
    type Interf08 is interface and F394A00.Abstract_Non_Lim_Private; -- ERROR:
    type Interf09 is limited interface
                             and F394A00.Abstract_Lim_Private;       -- ERROR:
    type Interf10 is interface and F394A00.Tagged_Non_Lim_Record;    -- ERROR:
    type Interf11 is limited interface
                             and F394A00.Tagged_Lim_Record;          -- ERROR:
    type Interf12 is interface and F394A00.Non_Lim_Intf_Der;         -- ERROR:
    type Interf13 is limited interface and F394A00.Lim_Intf_Der;     -- ERROR:
    type Interf14 is interface and F394A00.An_Int;                   -- ERROR:
    type Interf15 is interface and F394A00.A_Fixed;                  -- ERROR:
    type Interf16 is interface and F394A00.A_Float;                  -- ERROR:
    type Interf17 is interface and F394A00.An_Enum;                  -- ERROR:
    type Interf18 is interface and F394A00.An_Array_of_Int;          -- ERROR:
    type Interf19 is interface and F394A00.An_Array_of_Tagged;       -- ERROR:
    type Interf20 is protected interface and F394A00.Prot_Typ;       -- ERROR:
    type Interf21 is task interface and F394A00.Task_Typ;            -- ERROR:

    type Der01 is new Interf01 and F394A00.Non_Lim_Interface
                                            with null record;        -- OK.
    type Der02 is limited new Interf02 and F394A00.Lim_Interface
                                            with null record;        -- OK.
    type Der03 is new Interf01 and F394A00.Abstract_Non_Lim_Record
                                            with null record;        -- ERROR:
    type Der04 is limited new F394A00.Lim_Interface
               and F394A00.Abstract_Lim_Record with null record;     -- ERROR:
    type Der05 is new Interf01 and F394A00.Abstract_Non_Lim_Private
                                            with null record;        -- ERROR:
    type Der06 is limited new F394A00.Lim_Interface
              and F394A00.Abstract_Lim_Private with null record;     -- ERROR:
    type Der07 is new Interf01 and F394A00.Tagged_Non_Lim_Record
                                            with null record;        -- ERROR:
    type Der08 is limited new F394A00.Lim_Interface
              and F394A00.Tagged_Lim_Record with null record;        -- ERROR:
    type Der09 is new Interf01 and F394A00.Non_Lim_Intf_Der
                                            with null record;        -- ERROR:
    type Der10 is limited new F394A00.Lim_Interface
                   and F394A00.Lim_Intf_Der with null record;        -- ERROR:
    type Der11 is new Interf01 and F394A00.An_Int with null record;  -- ERROR:
    type Der12 is limited new Interf02 and F394A00.A_Float
                                            with null record;        -- ERROR:

    type Priv01 is new Interf01 and F394A00.Non_Lim_Interface
                                                with private;        -- OK.
    type Priv02 is limited new Interf02 and F394A00.Lim_Interface
                                                with private;        -- OK.
    type Priv03 is new Interf01 and F394A00.Abstract_Non_Lim_Record
                                                with private;        -- ERROR:
    type Priv04 is limited new F394A00.Lim_Interface
                and F394A00.Abstract_Lim_Record with private;        -- ERROR:
    type Priv05 is new Interf01 and F394A00.Abstract_Non_Lim_Private
                                          with private;              -- ERROR:
    type Priv06 is limited new F394A00.Lim_Interface
                and F394A00.Abstract_Lim_Private with private;       -- ERROR:
    type Priv07 is new Interf01 and F394A00.Tagged_Non_Lim_Record
                                                    with private;    -- ERROR:
    type Priv08 is limited new F394A00.Lim_Interface
                and F394A00.Tagged_Lim_Record with private;          -- ERROR:
    type Priv09 is new Interf01 and F394A00.Non_Lim_Intf_Priv
                                               with private;         -- ERROR:
    type Priv10 is limited new F394A00.Lim_Interface
                             and F394A00.Lim_Intf_Priv with private; -- ERROR:
    type Priv11 is new Interf01 and F394A00.An_Enum with private;    -- ERROR:
    type Priv12 is limited new Interf02 and
                    F394A00.An_Array_of_Tagged with private;         -- ERROR:

    task type Tsk01 is new F394A00.Task_Interface with end Tsk01;    -- OK.
    task Tsk02 is new F394A00.Sync_Interface with end Tsk02;         -- OK.
    task type Tsk03 is new F394A00.Lim_Interface with end Tsk03;     -- OK.
    task Tsk04 is new F394A00.Abstract_Lim_Record with end Tsk04;    -- ERROR:
    task type Tsk05 is new F394A00.Abstract_Lim_Private with
                                                       end Tsk05;    -- ERROR:
    task Tsk06 is new Interf04 and F394A00.Tagged_Lim_Record with
                                                       end Tsk06;    -- ERROR:
    task type Tsk07 is new Interf04 and F394A00.Lim_Intf_Der with
                                                       end Tsk07;    -- ERROR:
    task Tsk08 is new Interf04 and F394A00.An_Enum with end Tsk08;   -- ERROR:
    task type Tsk09 is new F394A00.An_Array_of_Tagged with end Tsk09;-- ERROR:
    task Tsk10 is new F394A00.Task_Typ with end Tsk10;               -- ERROR:
    task type Tsk11 is new Interf04 and F394A00.Task_Typ with
                                                       end Tsk11;    -- ERROR:

    protected type Prot01 is new F394A00.Prot_Interface with
                                                      end Prot01;    -- OK.
    protected Prot02 is new F394A00.Sync_Interface with end Prot02;  -- OK.
    protected type Prot03 is new F394A00.Lim_Interface with
                                                     end Prot03;     -- OK.
    protected Prot04 is new F394A00.Abstract_Lim_Record with
                                                      end Prot04;    -- ERROR:
    protected type Prot05 is new F394A00.Abstract_Lim_Private with
                                                       end Prot05;   -- ERROR:
    protected Prot06 is new Interf05 and F394A00.Tagged_Lim_Record with
                                                       end Prot06;   -- ERROR:
    protected type Prot07 is new Interf05 and F394A00.Lim_Intf_Der with
                                                       end Prot07;   -- ERROR:
    protected Prot08 is new Interf05 and F394A00.A_Fixed with
                                                       end Prot08;   -- ERROR:
    protected type Prot09 is new F394A00.An_Array_of_Int with
                                                       end Prot09;   -- ERROR:
    protected Prot10 is new F394A00.Prot_Typ with end Prot10;        -- ERROR:
    protected type Prot11 is new Interf05 and F394A00.Prot_Typ with
                                                       end Prot11;   -- ERROR:

    generic
        type Abstract_Lim_Formal is abstract tagged limited private;
        type GInterf01 is interface and F394A00.Non_Lim_Interface;   -- OK.
        type GInterf02 is limited interface
                                       and F394A00.Lim_Interface;    -- OK.
        type GInterf03 is synchronized interface
                                 and F394A00.Sync_Interface;         -- OK.
        type GInterf04 is task interface and F394A00.Task_Interface; -- OK.
        type GInterf05 is protected interface and
                                             F394A00.Prot_Interface; -- OK.
        type GInterf06 is interface and
                                   F394A00.Abstract_Non_Lim_Record;  -- ERROR:
        type GInterf07 is limited interface
                                 and F394A00.Abstract_Lim_Record;    -- ERROR:
        type GInterf08 is interface and
                                   F394A00.Abstract_Non_Lim_Private; -- ERROR:
        type GInterf09 is limited interface
                                 and F394A00.Abstract_Lim_Private;   -- ERROR:
        type GInterf10 is interface and
                                   F394A00.Tagged_Non_Lim_Record;    -- ERROR:
        type GInterf11 is limited interface
                                 and F394A00.Tagged_Lim_Record;      -- ERROR:
        type GInterf12 is interface and F394A00.Non_Lim_Intf_Der;    -- ERROR:
        type GInterf13 is limited interface and F394A00.Lim_Intf_Der;-- ERROR:
        type GInterf14 is interface and F394A00.An_Int;              -- ERROR:
        type GInterf15 is interface and Abstract_Lim_Formal;         -- ERROR:
        type GInterf16 is interface and GInterf01;                   -- OK.
        type GInterf17 is protected interface and F394A00.Prot_Typ;  -- ERROR:
        type GInterf18 is task interface and F394A00.Task_Typ;       -- ERROR:

        type GDer01 is new Interf01 and F394A00.Non_Lim_Interface
                                                with private;        -- OK.
        type GDer02 is limited new Interf02 and F394A00.Lim_Interface
                                                with private;        -- OK.
        type GDer03 is new Interf01 and F394A00.Abstract_Non_Lim_Record
                                                with private;        -- ERROR:
        type GDer04 is limited new F394A00.Lim_Interface
                and F394A00.Abstract_Lim_Record with private;        -- ERROR:
        type GDer05 is new Interf01 and F394A00.Abstract_Non_Lim_Private
                                          with private;              -- ERROR:
        type GDer06 is limited new F394A00.Lim_Interface
                and F394A00.Abstract_Lim_Private with private;       -- ERROR:
        type GDer07 is new Interf01 and F394A00.Tagged_Non_Lim_Record
                                                    with private;    -- ERROR:
        type GDer08 is limited new F394A00.Lim_Interface
                and F394A00.Tagged_Lim_Record with private;          -- ERROR:
        type GDer09 is new Interf01 and F394A00.Non_Lim_Intf_Priv
                                               with private;         -- ERROR:
        type GDer10 is limited new F394A00.Lim_Interface
                             and F394A00.Lim_Intf_Priv with private; -- ERROR:
        type GDer11 is new Interf01 and F394A00.An_Enum with private;-- ERROR:
        type GDer12 is limited new Interf02 and
                        F394A00.An_Array_of_Tagged with private;     -- ERROR:
        type GDer13 is limited new Interf02
                               and GInterf02 with private;           -- OK.
        type GDer14 is limited new GInterf02
                               and Abstract_Lim_Formal with private; -- ERROR:

    package Bad is
        type Interf01 is interface
                               and F394A00.Abstract_Non_Lim_Record;  -- ERROR:
        type Interf02 is limited interface
                                 and F394A00.Abstract_Lim_Record;    -- ERROR:
        type Interf03 is limited interface
                                 and Abstract_Lim_Formal;            -- ERROR:
        type Der01 is new Interf01 and F394A00.Abstract_Non_Lim_Private
                                                with null record;    -- ERROR:
        type Der02 is limited new F394A00.Lim_Interface
                  and F394A00.Abstract_Lim_Private with null record; -- ERROR:
        type Der03 is limited new F394A00.Lim_Interface
                  and Abstract_Lim_Formal with null record;          -- ERROR:
    private
        type Interf04 is interface
                               and F394A00.Abstract_Non_Lim_Private; -- ERROR:
        type Interf05 is limited interface
                             and F394A00.Abstract_Lim_Private;       -- ERROR:
        type Interf06 is limited interface
                                 and Abstract_Lim_Formal;            -- ERROR:
        type Der04 is new Interf01 and F394A00.Non_Lim_Intf_Der
                                                with null record;    -- ERROR:
        type Der05 is limited new F394A00.Lim_Interface
                       and F394A00.Lim_Intf_Der with null record;    -- ERROR:
        type Der06 is new GInterf01
                  and Abstract_Lim_Formal with null record;          -- ERROR:
    end Bad;

private
    -- Completions of above. Any errors are optional as they are just
    -- repeating errors in the original declarations, and we don't
    -- require that they are given twice.
    type Priv01 is new Interf01 and F394A00.Non_Lim_Interface
                                                 with null record;   -- OK.
    type Priv02 is limited new Interf02 and F394A00.Lim_Interface
                                                with null record;    -- OK.
    type Priv03 is new Interf01
       and F394A00.Abstract_Non_Lim_Record with null record;-- OPTIONAL ERROR:
    type Priv04 is limited new F394A00.Lim_Interface
           and F394A00.Abstract_Lim_Record with null record;-- OPTIONAL ERROR:
    type Priv05 is new Interf01 and
         F394A00.Abstract_Non_Lim_Private with null record; -- OPTIONAL ERROR:
    type Priv06 is limited new F394A00.Lim_Interface
        and F394A00.Abstract_Lim_Private with null record;  -- OPTIONAL ERROR:
    type Priv07 is new Interf01
        and F394A00.Tagged_Non_Lim_Record with null record; -- OPTIONAL ERROR:
    type Priv08 is limited new F394A00.Lim_Interface
            and F394A00.Tagged_Lim_Record with null record; -- OPTIONAL ERROR:
    type Priv09 is new Interf01
            and F394A00.Non_Lim_Intf_Priv with null record; -- OPTIONAL ERROR:
    type Priv10 is limited new F394A00.Lim_Interface
                and F394A00.Lim_Intf_Priv with null record; -- OPTIONAL ERROR:
    type Priv11 is new Interf01 and F394A00.An_Enum
                                       with null record;    -- OPTIONAL ERROR:
    type Priv12 is limited new Interf02 and
       F394A00.An_Array_of_Tagged with null record;         -- OPTIONAL ERROR:

end B394A01;
