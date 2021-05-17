

     --=================================================================--


with Report;
with CB20003_0;                               -- package Push_Buttons

procedure CB20003 is
      
   package Push_Buttons renames CB20003_0;

   Console_Button : Push_Buttons.Button;

begin

   Report.Test ("CB20003", "Check that exceptions can be raised, "  &
                           "reraised, and handled in a subprogram " &
                           "referenced by an access to subprogram value");


   Default_Response_Processing:                 -- The exception
                                                -- Handled_With_Others is to 
                                                -- be caught with an others
                                                -- handler in Default_Resp.,
                                                -- reraised, and handled with
                                                -- a specific handler here.
   begin
   
      Push_Buttons.Push (Console_Button,        -- Raise exception that will
                         Report.Ident_Int(2));  -- be handled in procedure.
   exception
      when Push_Buttons.Non_Default_Priority =>
         if not Push_Buttons.Handled_With_Others then   -- Not reraised in 
                                                        -- procedure.
            Report.Failed 
              ("Exception not handled/reraised in procedure");
         end if;
      when others =>
         Report.Failed ("Exception handled in " &
                        " Default_Response_Processing block");
   end Default_Response_Processing;



   Alert_Response_Processing:
   begin
   
      Push_Buttons.Set_Response (Console_Button,
                                 Push_Buttons.Alert_Response'access);

      Push_Buttons.Push (Console_Button,        -- Raise exception that will
                         Report.Ident_Int(4));  -- be handled in procedure, 
                                                -- reraised, and propagated
                                                -- to caller.
      Report.Failed ("Exception not propagated to caller " &
                     "in Alert_Response_Processing block");

   exception                                    
      when Push_Buttons.Non_Alert_Priority =>
         if not Push_Buttons.Reraised_In_Subprogram then  -- Not reraised in 
                                                          -- procedure.
            Report.Failed ("Exception not reraised in procedure");
         end if;
      when others =>
         Report.Failed ("Exception handled in " &
                        " Alert_Response_Processing block");
   end Alert_Response_Processing;



   Emergency_Response_Processing:
   begin
   
      Push_Buttons.Set_Response (Console_Button,
                                 Push_Buttons.Emergency_Response'access);

      Push_Buttons.Push (Console_Button,        -- Raise exception that will
                         Report.Ident_Int(6));  -- be propagated directly to
                                                -- caller.
      Report.Failed ("Exception not propagated to caller " &
                     "in Emergency_Response_Processing block");

   exception                                   
      when Push_Buttons.Non_Emergency_Priority =>
         Push_Buttons.Handled_In_Caller := True;
      when others =>
         Report.Failed ("Exception handled in " &
                        " Emergency_Response_Processing block");
   end Emergency_Response_Processing;



   if not (Push_Buttons.Handled_With_Others and
           Push_Buttons.Reraised_In_Subprogram and
           Push_Buttons.Handled_In_Caller ) 
   then
      Report.Failed ("Incorrect exception handling in referenced subprograms");
   end if;


   Report.Result;

end CB20003;
