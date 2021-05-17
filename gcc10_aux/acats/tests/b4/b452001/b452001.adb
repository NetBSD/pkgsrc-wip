
with B452001_0; use B452001_0;
procedure B452001 is
begin
   declare
      ONE_1 : constant Lim_Never_Equal := Create (1);
      Var_1 : Lim_Never_Equal := Create (12);
   begin
      if ONE_1 in TWO_1 then                              -- ERROR: {10;5}
         null;
      elsif TWO_1 in ZERO_1 | TWO_1 then                  -- ERROR: {10;5}
         null;
      elsif Var_1 in ONE_1 | TWO_1 then                   -- ERROR: {10;5}
         null;
      elsif Var_1 in ONE_1 then                           -- ERROR: {10;5}
         null;
      elsif Var_1 in Lim_Never_Equal | TWO_1 then         -- ERROR: {10;5}
         null;
      end if;
   end;

   declare
      ONE_2 : constant Lim_Hidden_Predef_Equal := Create (1);
      Var_2 : Lim_Hidden_Predef_Equal := Create (12);
   begin
      if ONE_2 in TWO_2 then                              -- ERROR: {10;5}
         null;
      elsif TWO_2 in ZERO_2 | TWO_2 then                  -- ERROR: {10;5}
         null;
      elsif Var_2 in ONE_2 | TWO_2 then                   -- ERROR: {10;5}
         null;
      elsif Var_2 in ONE_2 then                           -- ERROR: {10;5}
         null;
      elsif Var_2 in Lim_Hidden_Predef_Equal | TWO_2 then -- ERROR: {10;5}
         null;
      end if;
   end;

   declare
      ONE_3 : constant Lim_Hidden_UDef_Equal := Create (1);
      Var_3 : Lim_Hidden_UDef_Equal := Create (12);
   begin
      if ONE_3 in TWO_3 then                              -- ERROR: {10;5}
         null;
      elsif TWO_3 in ZERO_3 | TWO_3 then                  -- ERROR: {10;5}
         null;
      elsif Var_3 in ONE_3 | TWO_3 then                   -- ERROR: {10;5}
         null;
      elsif Var_3 in ONE_3 then                           -- ERROR: {10;5}
         null;
      elsif Var_3 in Lim_Hidden_UDef_Equal | TWO_3 then   -- ERROR: {10;5}
         null;
      end if;
   end;

   declare
      ONE_4 : constant Lim_w_Equal := Create (1);
      Var_4 : Lim_w_Equal := Create (12);
   begin
      if ONE_4 in TWO_4 then                              -- OK. {10;5}
         null;
      elsif TWO_4 in ZERO_4 | TWO_4 then                  -- OK. {10;5}
         null;
      elsif Var_4 in ONE_4 | TWO_4 then                   -- OK. {10;5}
         null;
      elsif Var_4 in ONE_4 then                           -- OK. {10;5}
         null;
      elsif Var_4 in Lim_w_Equal | TWO_4 then             -- OK. {10;5}
         null;
      end if;
   end;

   declare
      ONE_5 : constant Lim_Tagged_wo_Equal := Create (1);
      Var_5 : Lim_Tagged_wo_Equal := Create (12);
   begin
      if ONE_5 in TWO_5 then                              -- ERROR: {10;5}
         null;
      elsif TWO_5 in ZERO_5 | TWO_5 then                  -- ERROR: {10;5}
         null;
      elsif Var_5 in ONE_5 | TWO_5 then                   -- ERROR: {10;5}
         null;
      elsif Var_5 in ONE_5 then                           -- ERROR: {10;5}
         null;
      elsif Var_5 in Lim_Tagged_wo_Equal | TWO_5 then     -- ERROR: {10;5}
         null;
      end if;
   end;

   declare
      ONE_6 : constant Lim_Tagged_w_Equal := Create (1);
      Var_6 : Lim_Tagged_w_Equal := Create (12);
   begin
      if ONE_6 in TWO_6 then                              -- OK. {10;5}
         null;
      elsif TWO_6 in ZERO_6 | TWO_6 then                  -- OK. {10;5}
         null;
      elsif Var_6 in ONE_6 | TWO_6 then                   -- OK. {10;5}
         null;
      elsif Var_6 in ONE_6 then                           -- OK. {10;5}
         null;
      elsif Var_6 in Lim_Tagged_w_Equal | TWO_6 then      -- OK. {10;5}
         null;
      end if;
   end;

end B452001;
