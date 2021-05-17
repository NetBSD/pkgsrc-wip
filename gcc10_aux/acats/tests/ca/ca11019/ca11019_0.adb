 -- parent.child

     --=================================================================--

-- parent body depends on private generic child
with CA11019_0.CA11019_1;     -- Private generic child.

pragma Elaborate (CA11019_0.CA11019_1);
package body CA11019_0 is

   -- instantiate the generic child with data types needed by the 
   -- package interface services
   package Data_1_Ops is new CA11019_1
     (Data_Type => Data_1);
 
   package Data_2_Ops is new CA11019_1
     (Data_Type => Data_2);

   package Data_3_Ops is new CA11019_1
     (Data_Type => Data_3);

   ---------------------------------------------------------

   procedure Add_1 (Data : Data_1; To : in out Data_Collection) is
   begin
      -- maybe do other stuff here
      Data_1_Ops.Add (Data, To);
      -- and here
   end;

   ---------------------------------------------------------

   function Statistical_Op_1 (Data : Data_Collection) return Data_1 is
   begin
      -- maybe use generic operation(s) in some complicated ways
      -- (but simplified out, for the sake of testing)
      return Data_1_Ops.Op (Data);
   end;

   ---------------------------------------------------------

   procedure Add_2 (Data : Data_2; To : in out Data_Collection) is
   begin
      Data_2_Ops.Add (Data, To);
   end;

   ---------------------------------------------------------

   function Statistical_Op_2 (Data : Data_Collection) return Data_2 is
   begin
      return Data_2_Ops.Op (Data);
   end;

   ---------------------------------------------------------

   procedure Add_3 (Data : Data_3; To : in out Data_Collection) is
   begin
      Data_3_Ops.Add (Data, To);
   end;

   ---------------------------------------------------------

   function Statistical_Op_3 (Data : Data_Collection) return Data_3 is
   begin
      return Data_3_Ops.Op (Data);
   end;

end CA11019_0;
