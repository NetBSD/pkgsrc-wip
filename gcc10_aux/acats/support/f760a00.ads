-- F760A00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation declares a controlled type and limited types for use
--      in tests verifying that limited aggregates and function calls are
--      built-in-place.
--
-- CHANGE HISTORY:
--      30 Apr 07   RLB   Created.
--      17 Aug 07   RLB   Added Use_Cnst to fix test error.
--      28 Feb 14   RLB   Renamed test as rules have moved.
--
--!

with TCTouch, Report;
with Ada.Finalization;
package F760A00 is

    type TC_Copy_Check is new Ada.Finalization.Controlled with private;

    procedure Initialize (Object : in out TC_Copy_Check);

    procedure Adjust (Object : in out TC_Copy_Check);

    procedure Finalize (Object : in out TC_Copy_Check);

    procedure Check_TC_Copy_Check;
       -- Verify that TC_Copy_Check works properly.

    procedure Use_It (Object : in out TC_Copy_Check);
    procedure Use_Cnst (Object : in TC_Copy_Check);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

    type Lim_Rec is limited record
        A : Integer;
        B : Boolean;
        TC : TC_Copy_Check; -- Always default initialize.
    end record;

    procedure Check_Init (Object : in Lim_Rec; Message : in String);

    procedure Check_Fin_Lim_Rec (Message : in String);

    procedure Use_It (Object : in out Lim_Rec);
    procedure Use_Cnst (Object : in Lim_Rec);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

    type Lim_Array is array (Positive range <>) of Lim_Rec;

    procedure Check_Init (Object : in Lim_Array; Message : in String);

    procedure Check_Fin_Lim_Array (Length : in Natural; Message : in String);

    procedure Use_It (Object : in out Lim_Array);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

    type Lim_Tagged is tagged limited record
        R : Lim_Rec;
        TC : TC_Copy_Check; -- Always default initialize.
    end record;

    procedure Check_Init (Object : in Lim_Tagged'Class; Message : in String);

    procedure Check_Fin_Lim_Tagged (Message : in String);

    procedure Use_It (Object : in out Lim_Tagged'Class);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

    protected type Prot is
       function Get return Natural;
       procedure Set (Val : in Natural);
       procedure Use_It;
    private
       Value : Natural := 0;
       TC : TC_Copy_Check;
    end Prot;

    procedure Check_Init (Object : in Prot; Message : in String);

    procedure Check_Fin_Prot (Message : in String);

    procedure Use_It (Object : in out Prot);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

    type Lim_Comp is record
       P : Prot;
       N : Natural;
       TC : TC_Copy_Check; -- Always default initialize.
    end record;

    procedure Check_Init (Object : in Lim_Comp; Message : in String);

    procedure Check_Fin_Lim_Comp (Message : in String);

    procedure Use_It (Object : in out Lim_Comp);
       -- Ensure that Object is not removed by optimization
       -- as a dead variable.

private

    type TC_Copy_Check is new Ada.Finalization.Controlled with record
        Val : Natural := 10;
    end record;

end F760A00;
