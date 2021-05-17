
package body C452003_Root is

   pragma Assertion_Policy (Check);

   Global_Save : Any_Root_Ptr := null;
      -- The global data structure. In a real program, this probably would
      -- be a container or have internal pointers, but we don't need that
      -- for this test.

   procedure Save (Obj : access Root_Type) is
   begin
      if Obj.Id /= 0 then
         Global_Save := Any_Root_Ptr (Obj); -- Always should be OK
                                            -- if the precondition is checked.
      -- else don't save.
      end if;
   end Save;

   function Is_Present (Obj : access Root_Type) return Boolean is
   begin
      if Obj in Any_Root_Ptr then -- (Objective 2)
         return Any_Root_Ptr (Obj) = Global_Save; -- Always should be OK
                                                  -- if the membership worked.
      else
         return False;
      end if;
   end Is_Present;

   procedure Force_Op (Obj : access constant Root_Type'Class;
                       Result : out TC_Result) is
   begin
      if Obj in Any_Root_Ptr then -- (Objective 1)
         if Obj in Non_Null_Any_Root_Ptr then -- Should never get here.
            Result := Done;
         else
            Result := Is_Null;
         end if;
      else
         Result := Wrong_Kind;
      end if;
   end Force_Op;

end C452003_Root;
