

     --===================================================================--


with BC54001_0;
package BC54001 is

   type Msg_Ptr_Constant is access constant String;
   type Msg_Ptr_All      is access all      String;
   type Msg_Ptr_Pool     is access          String;
   type Msg_Ptr_Subprog  is access function return String;


   --
   -- Generic formal is an access-to-constant type:
   --

   package Instance_1 is new
     BC54001_0.General_Access_Constant (Msg_Ptr_Constant);            -- OK.

   package Instance_2 is new
     BC54001_0.General_Access_Constant (Msg_Ptr_All);                 -- ERROR:
                                   -- Actual is not an access-to-constant type.

   package Instance_3 is new
     BC54001_0.General_Access_Constant (Msg_Ptr_Pool);                -- ERROR:
                                   -- Actual is not an access-to-constant type.

   package Instance_4 is new
     BC54001_0.General_Access_Constant (Msg_Ptr_Subprog);             -- ERROR:
                                   -- Actual is not an access-to-constant type.


   --
   -- Generic formal is an access-to-variable type:
   --

   package Instance_5 is new
     BC54001_0.General_Access_All (Msg_Ptr_Constant);                 -- ERROR:
                            -- Actual is not a general access-to-variable type.

   package Instance_6 is new
     BC54001_0.General_Access_All (Msg_Ptr_All);                      -- OK.

   package Instance_7 is new
     BC54001_0.General_Access_All (Msg_Ptr_Pool);                     -- ERROR:
                            -- Actual is not a general access-to-variable type.

   package Instance_8 is new
     BC54001_0.General_Access_All (Msg_Ptr_Subprog);                  -- ERROR:
                            -- Actual is not a general access-to-variable type.


   --
   -- Generic formal is a pool-specific access type:
   --

   package Instance_9 is new
     BC54001_0.Pool_Specific_Access (Msg_Ptr_Constant);               -- ERROR:
                                   -- Actual is not an access-to-variable type.

   package Instance10 is new
     BC54001_0.Pool_Specific_Access (Msg_Ptr_All);                    -- OK.

   package Instance11 is new
     BC54001_0.Pool_Specific_Access (Msg_Ptr_Pool);                   -- OK.

   package Instance12 is new
     BC54001_0.Pool_Specific_Access (Msg_Ptr_Subprog);                -- ERROR:
                                   -- Actual is not an access-to-variable type.


   --
   -- Generic formal is an access-to-subprogram type:
   --

   package Instance13 is new
     BC54001_0.Subprogram_Access (Msg_Ptr_Constant);                  -- ERROR:
                                 -- Actual is not an access-to-subprogram type.

   package Instance14 is new
     BC54001_0.Subprogram_Access (Msg_Ptr_All);                       -- ERROR:
                                 -- Actual is not an access-to-subprogram type.

   package Instance15 is new
     BC54001_0.Subprogram_Access (Msg_Ptr_Pool);                      -- ERROR:
                                 -- Actual is not an access-to-subprogram type.

   package Instance16 is new
     BC54001_0.Subprogram_Access (Msg_Ptr_Subprog);                   -- OK.


end BC54001;
