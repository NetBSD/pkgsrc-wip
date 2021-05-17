

with B470001_0; use B470001_0;
procedure B470001 is
   PI : Paragraph_Info := Paragraph(1);
   type Acc_Nat is access all Natural;
   type Acc_CNat is access constant Natural;
begin
   -- A variable is required as the actual for an "out" parameter:
   Change_Paragraph_Indent (1, +1, PI.Indent);                -- OK. {4;1}

   Change_Paragraph_Indent (1, -1, Natural'(PI.Indent));      -- ERROR: {4;1}

   Change_Paragraph_Indent (1, -1, Natural(PI.Indent));       -- OK. {4;1}

   -- A variable is required as the target of an assignment:
   PI.Indent := 8;                                            -- OK. {4;1}

   Natural'(PI.Indent) := 8;                                  -- ERROR: {4;1}

   Natural(PI.Indent) := 8;                                   -- ERROR: {4;1}

   -- A variable is required as the prefix of 'Access for
   -- an access-to-variable type:
   declare
      Bare_Indent : Natural renames PI.Indent;                -- OK. {7;1}

      QE_Indent   : Natural renames Natural'(PI.Indent);      -- OK. {7;1}

      Ptr  : Acc_Nat;
      CPtr : Acc_CNat;
   begin
      Change_Paragraph_Indent (1, +1, Bare_Indent);           -- OK. {7;1}

      Change_Paragraph_Indent (1, -1, QE_Indent);             -- ERROR: {7;1}

      Ptr := PI.Indent'Access;                                -- OK. {14;1}

      Ptr := Paragraph_Info'(PI).Indent'Access;               -- ERROR: {14;1}

      CPtr := PI.Indent'Access;                               -- OK. {14;1}

      CPtr := Paragraph_Info'(PI).Indent'Access;              -- OK. {14;1}

   end;

   -- A variable is required as the actual of a formal "in out" parameter:
   declare
      generic
         Tst : in out Natural;
      procedure Try;

      procedure Try is
      begin
         null;
      end Try;

      procedure Inst1 is new Try (PI.Indent);                 -- OK. {7;1}

      procedure Inst2 is new Try (Natural'(PI.Indent));       -- ERROR: {7;1}

      procedure Inst3 is new Try (Natural(PI.Indent));        -- ERROR: {7;1}

   begin
      null;
   end;

   -- A variable is required as the prefix of a prefixed view if the
   -- corresponding parameter is "in out":

   PI.Calc_Width;                                             -- OK. {4;1}

   Paragraph_Info'(PI).Calc_Width;                            -- ERROR: {4;1}

   if PI.Total_Width > 10 then                                -- OK. {7;5}
      null;
   elsif Paragraph_Info'(PI).Total_Width > 10 then            -- OK. {7;5}
      null;
   end if;

end B470001;
