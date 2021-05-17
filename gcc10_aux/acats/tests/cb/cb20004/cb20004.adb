

     --=================================================================--


with CB20004_0;                   -- Package Buffer.
with Report;

procedure CB20004 is

   package Buffer renames CB20004_0;

   Data        : Buffer.Data_Item := Buffer.Data_Item'First;
   Data_Buffer : Buffer.Bounded_Buffer;   -- an object of protected type.

   Handled_In_Caller : Boolean := False;  -- same name as boolean declared 
                                          -- in package Buffer.
begin

   Report.Test ("CB20004", "Check that exceptions propagate correctly " &
                           "from objects of protected types" );

   Initial_Data_Block:
   begin                                    -- Data causes Constraint_Error.
      Data_Buffer.Put (CB20004_0.Data_Item(Report.Ident_Int(51)));

   exception                                  
      when Constraint_Error => 
         Buffer.Handled_In_Body := False;     -- Improper exception handling
                                              -- in entry body.
         Report.Failed ("Exception propagated to caller " &
                        " from Initial_Data_Block");
      when others =>
         Report.Failed ("Exception raised in processing and " &
                        "propagated to caller from Initial_Data_Block");
   end Initial_Data_Block;


   Data_Entry_Block:
   begin
                                              -- Valid data. No exception.
      Data_Buffer.Put (CB20004_0.Data_Item(Report.Ident_Int(3)));  

                                              -- Data will cause exception.
      Data_Buffer.Put (7);                    -- Call protected object entry, 
                                              -- exception to be handled/
                                              -- reraised in entry body.
      Report.Failed ("Data_Over_5 Exception not raised in processing");
   exception
      when Buffer.Data_Over_5 =>
         if Buffer.Propagated_To_Caller then   -- Reraised in entry body?
            Buffer.Handled_In_Caller := True;
         else
            Report.Failed ("Exception not reraised in entry body");
         end if;
      when others =>
         Report.Failed ("Exception raised in processing and propagated " &
                        "to caller from Data_Entry_Block");
   end Data_Entry_Block;


   Data_Retrieval_Block:
   begin

      Data_Buffer.Get (Data);  -- Retrieval of buffer data, buffer now empty.
                               -- Exception will be raised in entry body, with
                               -- propagation to caller.
      Report.Failed ("Data_Degradation Exception not raised in processing");
   exception
      when Buffer.Data_Degradation =>
         Handled_In_Caller := True;   -- Local Boolean used here.
      when others =>
         Report.Failed ("Exception raised in processing and propagated " &
                        "to caller from Data_Retrieval_Block");
   end Data_Retrieval_Block;


   if not (Buffer.Handled_In_Body      and    -- Validate proper exception
           Buffer.Propagated_To_Caller and    -- handling in entry bodies.
           Buffer.Handled_In_Caller    and
           Handled_In_Caller)
   then
      Report.Failed ("Improper exception handling by entry bodies");
   end if;


   Report.Result;

end CB20004;
