

     --=================================================================--


with Report;

package body CB20003_0 is                     -- package Push_Buttons 


   procedure Push (B : in out Button;
                   P : in     Priority_Type) is
   begin                                  -- Invoking subprogram designated 
      B.Response (P, B);                  -- by access value.
   end Push;


   procedure Set_Response (B : in out Button;
                           R : in     Button_Response_Ptr) is
   begin
      B.Response := R;      -- Set procedure value in record
   end Set_Response;


   procedure Default_Response (P : in     Priority_Type;
                               B : in out Button) is
   begin
      if (P > Default_Priority) then
         raise Non_Default_Priority;
         Report.Failed ("Exception not raised in procedure body");
      else
         B.Priority := P;
      end if;
   exception
      when others =>                    -- Catch exception with others handler
         Handled_With_Others := True;   -- Successfully caught with "others"
         raise;
         Report.Failed ("Exception not reraised in handler");
   end Default_Response;



   procedure Alert_Response (P : in     Priority_Type;
                             B : in out Button) is
   begin
      if (P > Alert_Priority) then
         raise Non_Alert_Priority;
         Report.Failed ("Exception not raised in procedure body");
      else
         B.Priority := P;
      end if;
   exception
      when Non_Alert_Priority =>
         Reraised_In_Subprogram := True;
         raise;                                  -- Propagate to caller.
         Report.Failed ("Exception not reraised in procedure excpt handler");
      when others =>
         Report.Failed ("Incorrect exception raised/handled");
   end Alert_Response;



   procedure Emergency_Response (P : in     Priority_type;
                                 B : in out Button) is
   begin
      if (P > Emergency_Priority) then
         raise Non_Emergency_Priority;
         Report.Failed ("Exception not raised in procedure body");
      else
         B.Priority := P;
      end if;
      -- No exception handler here, exception will be propagated to caller.
   end Emergency_Response;


end CB20003_0;                                -- package Push_Buttons
