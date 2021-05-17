
with C831001_Root;
package C831001_0 is

   type Zoom_Camera is tagged private;

   procedure Self_Test (C : in out Zoom_Camera'Class);

   procedure Set_Exposure (C : in out Zoom_Camera;
                           X : in     C831001_Root.Exposure);


   -- ...Additional operations.


   not overriding
   function TC_Correct_Result (C : Zoom_Camera;
                               D : C831001_Root.Depth_Of_Field;
                               S : C831001_Root.Shutter_Speed) return Boolean;

   function TC_Shutter (C : in out Zoom_Camera'Class)
      return C831001_Root.Shutter_Speed;

private

   type Magnification is (Low, Medium, High);

   type Zoom_Camera is new C831001_Root.Remote_Camera with record
      Mag : Magnification;
   end record;

   -- procedure Focus (C     : in out Zoom_Camera;               -- Implicitly
   --                  Depth : in     Depth_Of_Field)            -- declared
                                                                 -- here.

   overriding
   procedure Focus (C     : in out Zoom_Camera;
                    Depth : in     C831001_Root.Depth_Of_Field);
      -- Overrides inherited operation.

   -- For the remote zoom camera, perhaps the focusing algorithm is different
   -- in some way, so the original Focus operation is overridden here.

   -- Since the partial view is not an extension, the overriding operation
   -- must be declared after the full type. This version of Focus, although
   -- not visible for type Zoom_Camera from outside the package, can still be
   -- dispatched to.

   -- Note: C831001_Root.Set_Shutter_Speed is inherited by Zoom_Camera from
   -- C831001_Root.Remote_Camera, but since the operation never becomes visible
   -- within the immediate scope of Zoom_Camera, it is never implicitly
   -- declared.

   -- The original Set_Exposure is inherited here as well; it then is
   -- immediately overridden. This completion is clearly overriding.
   overriding
   procedure Set_Exposure (C : in out Zoom_Camera;
                           X : in     C831001_Root.Exposure) is null;

   function TC_Shutter (C : in out Zoom_Camera'Class)
      return C831001_Root.Shutter_Speed is
         (Get_Shutter_Speed(C)); -- Dispatching call.

end C831001_0;
