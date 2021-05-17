
     --==================================================================--


package C392005_0.C392005_1 is

   type Auto_Speed is new Remote_Camera with private;


   -- procedure Focus (C     : in out Auto_Speed;      -- Implicitly declared
   --                  Depth : in     Depth_Of_Field)  -- here.

   -- For the improved remote camera, shutter speed can be set manually,
   -- so it is declared as a public operation.

   -- The order of declarations for Set_Aperture and Set_Shutter_Speed are
   -- reversed from the original declarations to trap potential compiler
   -- problems related to subprogram ordering.

   function Set_Aperture (C : Auto_Speed) return Aperture;    -- Overrides
                                                              -- inherited op.

   procedure Set_Shutter_Speed (C     : in out Auto_Speed;    -- Overrides
                                Speed : in     Shutter_Speed);-- inherited op.

   -- Set_Shutter_Speed and Set_Aperture override the operations inherited
   -- from the parent, even though the inherited operations are not implicitly
   -- declared until the private part below.

   type New_Camera is private;

   function TC_Get_Aper (C: New_Camera) return Aperture;

   -- ...Other operations.

private
   type Film_Speed is (One_Hundred, Two_Hundred, Four_Hundred);

   type Auto_Speed is new Remote_Camera with record
      ASA : Film_Speed;
   end record;

   -- procedure Set_Shutter_Speed (C     : in out Auto_Speed;    -- Implicitly
   --                              Speed : in     Shutter_Speed) -- declared
                                                                 -- here.

   -- function Set_Aperture (C : Auto_Speed) return Aperture;    -- Implicitly
                                                                 -- declared.

   procedure Focus (C     : in out Auto_Speed;                -- Overrides
                    Depth : in     Depth_Of_Field);           -- inherited op.

   -- For the improved remote camera, perhaps the focusing algorithm is
   -- different, so the original Focus operation is overridden here.

   Auto_Camera : Auto_Speed;

   type New_Camera is record
      Aper : Aperture := Set_Aperture (Auto_Camera);  -- Calls the overridden,
   end record;                                        -- not the inherited op.

end C392005_0.C392005_1;
