-- CC60001.A
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
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that calls on formal abstract subprograms dispatch as expected.
--
-- TEST DESCRIPTION:
--      We declare a hierarchy of tagged types (the outline is borrowed from
--      foundation F392C00), declare a generic package that operates on it,
--      instantiate the generic, and then check that calls to the instance
--      properly dispatch.
--
--      A generic package like CC60001_2 below functions something like an
--      after-the-fact interface, as any tagged type with the appropriate
--      operations can instantiate it; the type is not restricted to a
--      single hierarchy.
--
-- CHANGE HISTORY:
--      29 May 2015   RLB   Created test.

package CC60001_1 is  -- Switches

  type Toggle is tagged private;    ---------------------------------- Toggle

  function Create return Toggle;
  procedure Flip   (It : in out Toggle);
  function Is_On   (It : Toggle) return Boolean;

  type Dimmer is new Toggle with private;    ------------------------- Dimmer

  type Luminance is range 0..100;

  function  Create return Dimmer;
  overriding
  procedure Flip    (It : in out Dimmer);
  procedure Brighten(It : in out Dimmer;
                      By : in Luminance := 10);
  procedure Dim     (It : in out Dimmer;
                      By : in Luminance := 10);
  function Intensity(It : Dimmer) return Luminance;
  --function Is_On   (It : Dimmer) return Boolean; -- Inherited.

  type Auto_Dimmer is new Dimmer with private;    --------------- Auto_Dimmer

  function  Create return Auto_Dimmer;
  overriding
  procedure Flip      (It: in out Auto_Dimmer);
  procedure Set_Auto  (It: in out Auto_Dimmer);
  procedure Clear_Auto(It: in out Auto_Dimmer);
  -- procedure Set_Manual(It: in out Auto_Dimmer) renames Clear_Auto;
  procedure Set_Cutin (It: in out Auto_Dimmer; Lumens: in Luminance);
  procedure Set_Cutout(It: in out Auto_Dimmer; Lumens: in Luminance);

  function Auto            (It: Auto_Dimmer) return Boolean;
  function Cutout_Threshold(It: Auto_Dimmer) return Luminance;
  function Cutin_Threshold (It: Auto_Dimmer) return Luminance;
  --function Is_On   (It : Auto_Dimmer) return Boolean; -- Inherited.

  type Duo is new Toggle with private;    ---------------------------- Duo
     -- Two switches working together.

  function Create return Duo;
  --procedure Flip   (It : in out Duo); -- Inherited.
  procedure Flip_1 (It : in out Duo) renames Flip;
  procedure Flip_2   (It : in out Duo);
  overriding
  function Is_On   (It : Duo) return Boolean;


  function TC_CW_TI( Key : Character) return Toggle'Class;

private

  type Toggle is tagged record
    On : Boolean := False;
  end record;

  type Dimmer is new Toggle with record
    Intensity : Luminance := 100;
  end record;

  type Auto_Dimmer is new Dimmer with record
    Cutout_Threshold : Luminance := 60;
    Cutin_Threshold  : Luminance := 40;
    Auto_Engaged     : Boolean := False;
  end record;

  type Duo is new Toggle with record
    On_2 : Boolean := False; -- Second physical switch.
      -- Note: If both are in the "On" position, the switch is off.
  end record;

end CC60001_1;
