

     --==================================================================--


with CC30002_0;
use  CC30002_0;
generic
   type Camera_Type is new CC30002_0.Camera with private;
package CC30002_1 is

   type Speed_Camera is new Camera_Type with record
      Diag_Code: Positive;
      -- ...Other components.
   end record;

   -- Implicit procedure Focus (C: in out Speed_Camera) declared in generic.
   procedure Self_Test_NonDisp (C: in out Speed_Camera);
   procedure Self_Test_Disp    (C: in out Speed_Camera'Class);

private

   -- The following explicit declaration of Set_Shutter_Speed does NOT override
   -- a corresponding implicit declaration in the generic. Therefore, its copy
   -- does NOT override the implicit declaration (inherited from the actual)
   -- in the instance.

   procedure Set_Shutter_Speed (C: in out Speed_Camera);

   -- The following explicit declaration of Focus DOES override a
   -- corresponding implicit declaration (inherited from the parent) in the
   -- generic. Therefore, its copy overrides the implicit declaration
   -- (inherited from the actual) in the instance.

   procedure Focus (C: in out Speed_Camera);  -- Overrides implicit Focus
                                              -- in generic.
end CC30002_1;
