
package body C452003_Root.Child is

   pragma Assertion_Policy (Check);

   Global_Save : Any_Child_Ptr := null;

   procedure Save (Obj : access Child_Type) is
   begin
      if Obj.Id /= 0 then
         Global_Save := Any_Child_Ptr (Obj); -- Always should be OK
                                             -- if the precondition is checked.
      -- else don't save.
      end if;
   end Save;

   function Is_Present (Obj : access Child_Type) return Boolean is
   begin
      if Obj in Any_Child_Ptr then
         return Any_Child_Ptr (Obj) = Global_Save; -- Always should be OK
                                                   -- if the membership worked.
      elsif Obj in Any_Root_Ptr then
         return C452003_Root.Is_Present (Any_Root_Ptr(Obj));
      else
         return False;
      end if;
   end Is_Present;

   procedure Force_Save (Obj : access Root_Type'Class;
                         Result : out TC_Result) is
   begin
      if Obj in Any_Child_Ptr then -- (Objective 3)
         if Obj in Non_Null_Any_Root_Ptr then -- (Objective 4)
            Global_Save := Any_Child_Ptr (Obj);
            Result := Done;
         else
            Global_Save := null;
            Result := Is_Null;
         end if;
      else
         Result := Wrong_Tag;
      end if;
   end Force_Save;

end C452003_Root.Child;
