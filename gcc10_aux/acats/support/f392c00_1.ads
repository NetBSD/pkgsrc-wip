-- F392C00.A
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
-- FOUNDATION DESCRIPTION:
--      This foundation provides a basis for tagged type and dispatching
--      tests.  Each test describes the utilizations.
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      24 OCT 95   SAIC    Updated for ACVC 2.0.1
--
--!

package F392C00_1 is  -- Switches

  type Toggle is tagged private;    ---------------------------------- Toggle

  function Create return Toggle;
  procedure Flip   ( It : in out Toggle );
  function On      ( It : Toggle'Class ) return Boolean;
  function Off     ( It : Toggle'Class ) return Boolean;

  type Dimmer is new Toggle with private;    ------------------------- Dimmer

  type Luminance is range 0..100;

  function  Create return Dimmer;
  procedure Flip    ( It : in out Dimmer );
  procedure Brighten( It : in out Dimmer;
                      By : in Luminance := 10 );
  procedure Dim     ( It : in out Dimmer;
                      By : in Luminance := 10 );
  function Intensity( It : Dimmer ) return Luminance;

  type Auto_Dimmer is new Dimmer with private;    --------------- Auto_Dimmer

  function  Create return Auto_Dimmer;
  procedure Flip      ( It: in out Auto_Dimmer );
  procedure Set_Auto  ( It: in out Auto_Dimmer );
  procedure Clear_Auto( It: in out Auto_Dimmer );
  -- procedure Set_Manual( It: in out Auto_Dimmer ) renames Clear_Auto;
  procedure Set_Cutin ( It: in out Auto_Dimmer; Lumens: in Luminance );
  procedure Set_Cutout( It: in out Auto_Dimmer; Lumens: in Luminance );

  function Auto            ( It: Auto_Dimmer ) return Boolean;
  function Cutout_Threshold( It: Auto_Dimmer ) return Luminance;
  function Cutin_Threshold ( It: Auto_Dimmer ) return Luminance;

  function TC_CW_TI( Key : Character ) return Toggle'Class;

  function TC_Non_Disp( It: Toggle ) return Boolean;
  function TC_Non_Disp( It: Dimmer ) return Boolean;
  function TC_Non_Disp( It: Auto_Dimmer ) return Boolean;

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

end F392C00_1;
