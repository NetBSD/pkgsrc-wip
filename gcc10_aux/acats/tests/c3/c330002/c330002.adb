
     --==================================================================--

with Report;
with C330002_0;
use  C330002_0;

procedure C330002 is  

begin
   Report.Test ("C330002", "Check that if a subtype indication of a "      &
                "variable object defines an indefinite subtype, then "     & 
                "there is an initialization expression.  Check that "      &
                "the object remains so constrained throughout its "        &
                "lifetime.  Check that Constraint_Error is raised "        &
                "if an attempt is made to change bounds as well as "       &
                "discriminants of the objects of the indefinite "          &
                "subtypes.  Check for cases of tagged record and generic " &
                "formal types");

   TagObj_Block:
   declare
      TObj_ByAgg  : Tag_Type := (5, "Hello");    -- Initial assignment is
                                                 -- aggregate.   
      TObj_ByObj  : Tag_Type := TObj_ByAgg;      -- Initial assignment is
                                                 -- an object.   
      TObj_ByFunc : Tag_Type := Tag_Value;       -- Initial assignment is
                                                 -- function return value.
      Ren_Obj     : Tag_Type renames TObj_ByAgg;        

   begin

      begin
         if (TObj_ByAgg.Disc /= 5) or (TObj_ByAgg.S /= "Hello") then
            Report.Failed ("Wrong initial values for TObj_ByAgg");
         end if;
           
         TObj_ByAgg := (2, "Hi");                -- C_E, can't change the 
                                                 -- value of the discriminant.

         Avoid_Optimization_and_Fail (TObj_ByAgg, "Subtest 1");

      exception
         when Constraint_Error => null;          -- Exception is expected.
         when others           => 
            Report.Failed ("Unexpected exception - Subtest 1");
      end;


      begin
         Assign_Tag (Ren_Obj);                   -- C_E, can't change the 
                                                 -- value of the discriminant.

         Avoid_Optimization_and_Fail (Ren_Obj, "Subtest 2");

      exception
         when Constraint_Error => null;          -- Exception is expected.
         when others           => 
            Report.Failed ("Unexpected exception - Subtest 2");
      end;


      begin
         if (TObj_ByObj.Disc /= 5) or (TObj_ByObj.S /= "Hello") then
            Report.Failed ("Wrong initial values for TObj_ByObj");
         end if;

         TObj_ByObj := (3, "Bye");               -- C_E, can't change the 
                                                 -- value of the discriminant.

         Avoid_Optimization_and_Fail (TObj_ByObj, "Subtest 3");

      exception
         when Constraint_Error => null;          -- Exception is expected.
         when others           => 
            Report.Failed ("Unexpected exception - Subtest 3");
      end;


      begin
         if (TObj_ByFunc.Disc /= 4) or (TObj_ByFunc.S /= "ACVC") then
            Report.Failed ("Wrong initial values for TObj_ByFunc");
         end if;

         TObj_ByFunc := (5, "Aloha");            -- C_E, can't change the 
                                                 -- value of the discriminant.

         Avoid_Optimization_and_Fail (TObj_ByFunc, "Subtest 4");

      exception
         when Constraint_Error => null;          -- Exception is expected.
         when others           => 
            Report.Failed ("Unexpected exception - Subtest 4");
      end;

   end TagObj_Block;


   ArrObj_Block:
   declare
      Arr_Const   :  constant Array_Type               
                  := (9, 7, 6, 8); 
      Arr_ByAgg   :  Array_Type                  -- Initial assignment is
                  := (10, 11, 12);               -- aggregate.            
      Arr_ByFunc  :  Array_Type                  -- Initial assignment is
                  := Array_Value;                -- function return value.
      Arr_ByObj   :  Array_Type                  -- Initial assignment is
                  := Arr_ByAgg;                  -- object.

      Arr_Obj     :  array (Positive range <>) of Integer 
                  := (1, 2, 3, 4, 5);
    begin

      begin
         if (Arr_Const'First /= 1) or (Arr_Const'Last /= 4) then
            Report.Failed ("Wrong bounds for Arr_Const");
         end if;

         if (Arr_ByAgg'First /= 1) or (Arr_ByAgg'Last /= 3) then
            Report.Failed ("Wrong bounds for Arr_ByAgg");
         end if;

         if (Arr_ByFunc'First /= 1) or (Arr_ByFunc'Last /= 2) then
            Report.Failed ("Wrong bounds for Arr_ByFunc");
         end if;

         if (Arr_ByObj'First /= 1) or (Arr_ByObj'Last /= 3) then
            Report.Failed ("Wrong bounds for Arr_ByObj");
         end if;

         Assign_Array (Arr_ByObj);               -- C_E, Arr_ByObj bounds are
                                                 -- 1..3.

         Report.Failed ("Constraint_Error not raised - Subtest 5");

      exception
            when Constraint_Error => null;        -- Exception is expected.
            when others           => 
               Report.Failed ("Unexpected exception - Subtest 5");
      end;


      begin
         if (Arr_Obj'First /= 1) or (Arr_Obj'Last /= 5) then
            Report.Failed ("Wrong bounds for Arr_Obj");
         end if;

         for I in 0 .. 5 loop
            Arr_Obj (I + 1) := I + 5;             -- C_E, Arr_Obj bounds are
         end loop;                                -- 1..5.

         Report.Failed ("Constraint_Error not raised - Subtest 6");

      exception
            when Constraint_Error => null;        -- Exception is expected.
            when others           => 
               Report.Failed ("Unexpected exception - Subtest 6");
      end;

   end ArrObj_Block;


   GenericObj_Block:
   declare
      type Rec (Disc : Small_Num) is 
        record     
           S : Small_Num := Disc;
        end record;

      Rec_Obj : Rec := (2, 2);
      package IGen is new Gen (Rec, Rec_Obj);

   begin
      IGen.Gen_Obj := (3, 3);                    -- C_E, can't change the 
                                                 -- value of the discriminant.

      Report.Failed ("Constraint_Error not raised - Subtest 7");

      -- Next line prevents dead assignment.
      Report.Comment ("Disc is" & Integer'Image (IGen.Gen_Obj.Disc));

   exception
      when Constraint_Error => null;             -- Exception is expected.
      when others           => 
         Report.Failed ("Unexpected exception - Subtest 7");

   end GenericObj_Block;

   Report.Result;

end C330002;
