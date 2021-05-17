

     --===================================================================--


package body B392009 is

   --
   -- Test that actual in call may not be dynamically tagged:
   --

   procedure Dynamically_Tagged_Actuals (P : in out B392009_0.Root'Class) is
      Result  : B392009_0.Root;

      Temp    : B392009_0.Root := Func_Ptr (P);                       -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.
   begin
      Proc_Ptr (P);                                                   -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      Proc_Ptr (B392009_0.Root'Class(Root_Obj));                      -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      Result := Func_Ptr (Root_Class_Obj);                            -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.

      Proc_Ptr (B392009_0.Dyn_Tag_Func (Root_Class_Obj));             -- ERROR:
                   -- Actual parameter in procedure call is dynamically tagged.

      Result := Func_Ptr (Root_Class_Ptr.all);                        -- ERROR:
                    -- Actual parameter in function call is dynamically tagged.

      Result := Acc_Func_Ptr (Root_Class_Ptr);                        -- ERROR:
                -- Designated object of actual parameter is dynamically tagged.

      Acc_Proc_Ptr (Root_Class_Ptr);                                  -- OK.
                   -- Expected type in this case is not a specific tagged type.

   end Dynamically_Tagged_Actuals;



   --
   -- Test that actual in call may not be a descendant of type in designated
   -- profile (other than the type itself):
   --

   procedure Not_Primitive_Operation is
      Result  : B392009_0.Root;
   begin
      Proc_Ptr (Root_Obj);                                            -- OK.


      Proc_Ptr (Child_Obj);                                           -- ERROR:
                                          -- Actual parameter is of wrong type.

      Result := Func_Ptr (Root_Obj);                                  -- OK.


      Result := Func_Ptr (Child_Obj);                                 -- ERROR:
                                          -- Actual parameter is of wrong type.

      Result := Acc_Func_Ptr (Root_Ptr);                              -- OK.


      Result := Acc_Func_Ptr (Child_Ptr);                             -- ERROR:
                                     -- Actual parameter designates wrong type.

      Acc_Proc_Ptr (Root_Ptr);                                        -- OK.


      Acc_Proc_Ptr (Child_Ptr);                                       -- OK.
                                -- Formal parameter in this case is class-wide.


   end Not_Primitive_Operation;


end B392009;
