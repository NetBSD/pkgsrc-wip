
with C3A0007_0;
package C3A0007_1 is

   type Priority_Button is new C3A0007_0.Button
     with record
        Priority : Integer := 0;
      end record;

   -- Inherits procedure Push from Button
   -- Inherits procedure Set_Response from Button

   -- Override procedure Response from Button
   procedure Response (B : in out Priority_Button);

   -- Primitive operation of the extension
   procedure Set_Priority (B : in out Priority_Button);

end C3A0007_1;
