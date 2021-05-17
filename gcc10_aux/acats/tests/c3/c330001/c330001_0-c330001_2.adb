
     --==================================================================--

with Report;
with C330001_0.C330001_1;
package body C330001_0.C330001_2 is  

   procedure Assign_Private_Obj_3 is
   begin
      C330001_0.C330001_1.PrivateChild_Obj_03 := (5, "Aloha");
   end Assign_Private_Obj_3;

   ------------------------------------------------------------------
   function Raised_CE_PublicChild_Obj return Boolean is
   begin
      PublicChild_Obj_03 := (16, 13);       -- C_E, can't change constraints 
                                            -- of PublicChild_Obj_03.

      Report.Failed ("Constraint_Error not raised - Public child");

      -- Next line prevents dead assignment.

      Report.Comment ("PublicChild_Obj_03'First is" & Integer'Image 
                      (PublicChild_Obj_03'First) );
      return False;

   exception                             
      when Constraint_Error => 
         return True;                       -- Exception is expected.
      when others           => 
         return False;
   end Raised_CE_PublicChild_Obj;

   ------------------------------------------------------------------
   function Raised_CE_PrivateChild_Obj return Boolean is
   begin
      C330001_0.C330001_1.PrivateChild_Obj_04 := (21, 87, 18);      
                                            -- C_E, can't change constraints
                                            -- of PrivateChild_Obj_04.

      Report.Failed ("Constraint_Error not raised - Private child");

      -- Next line prevents dead assignment.

      Report.Comment ("PrivateChild_Obj_04'Last is" & Integer'Image 
                      (C330001_0.C330001_1.PrivateChild_Obj_04'Last) );
      return False;

   exception                             
      when Constraint_Error => 
         return True;                       -- Exception is expected.
      when others           => 
         return False;
   end Raised_CE_PrivateChild_Obj;

   ------------------------------------------------------------------
   function Verify_Public_Obj_1 return Boolean is
   begin
      return (PublicChild_Obj_01.D = 2 and PublicChild_Obj_01.S = "Hi");

   end Verify_Public_Obj_1;

   ------------------------------------------------------------------
   function Verify_Public_Obj_2 return Boolean is
   begin
      return (PublicChild_Obj_02.D  = 5       and
              PublicChild_Obj_02.C1 = "Hello" and 
              PublicChild_Obj_02.S  = 4);

   end Verify_Public_Obj_2;

   ------------------------------------------------------------------
   function Verify_Private_Obj_1 return Boolean is
   begin
      return (C330001_0.C330001_1.PrivateChild_Obj_01.D  = 4      and
              C330001_0.C330001_1.PrivateChild_Obj_01.C1 = "ACVC" and
              C330001_0.C330001_1.PrivateChild_Obj_01.S  = 15);

   end Verify_Private_Obj_1;

   ------------------------------------------------------------------
   function Verify_Private_Obj_2 return Boolean is
   begin
      return (C330001_0.C330001_1.PrivateChild_Obj_02.D  = 5       and
              C330001_0.C330001_1.PrivateChild_Obj_02.C1 = "Hello" and
              C330001_0.C330001_1.PrivateChild_Obj_02.S  = 19);

   end Verify_Private_Obj_2;

   ------------------------------------------------------------------
   function Verify_Private_Obj_3 return Boolean is
   begin
      return (C330001_0.C330001_1.PrivateChild_Obj_03.D = 5 and
              C330001_0.C330001_1.PrivateChild_Obj_03.S = "Aloha");

   end Verify_Private_Obj_3;

end C330001_0.C330001_2;
