

     --===================================================================--


package BA21003_0.BA21003_1 is  -- Non-preelaborable child unit.

   Call : My_Int := Func;                                             -- OK.
                                              -- Call to nonstatic function.

   TObj : Tsk;                                                        -- OK.
                                                   -- Object of a task type.

   Cont : My_Controlled;                                              -- OK.
                         -- Default-initialized object of a controlled type.

end BA21003_0.BA21003_1;
