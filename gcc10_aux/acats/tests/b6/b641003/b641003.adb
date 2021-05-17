

with B641003_0; use B641003_0;
procedure B641003 is

   type Default_Word is new Also_Word
      with Default_Value => 16#DEAD#;

   type New_Word is new Word_16;

   ON1 : Natural := 1;
   ON2 : Also_Word := 1;
   ON3 : Also_Float := 1.0;
   ON4 : Also_Fixed := 1.0;
   
   OD1 : Small_Integer;
   OD2 : Word_16;
   OD3 : Small_Float;
   OD4 : Small_Fixed;
   OD5 : Default_Word;
   OD6 : New_Word;
   
   procedure P1 (Param : out Word_16) is
   begin
      null;
   end P1;
   
   procedure P2 (Param : out Small_Float) is
   begin
      null;
   end P2;
   
   procedure P3 (Param : out Small_Fixed) is
   begin
      null;
   end P3;
   
   procedure P4 (Param : out Also_Word) is
   begin
      null;
   end P4;
   
   procedure P5 (Param : out Also_Fixed) is
   begin
      null;
   end P5;
   
   procedure P6 (Param : out Also_Float) is
   begin
      null;
   end P6;

   procedure P7 (Param : in out Word_16) is
   begin
      null;
   end P7;
     
begin

   P1 (Word_16(ON1));                                      -- ERROR: [A] {4;1}
   
   P1 (Word_16(ON3));                                      -- ERROR: [A] {4;1}
   
   P1 (Word_16(OD1));                                      -- ERROR: [B] {4;1}

   P1 (Word_16(OD5));                                      -- ERROR: [B] {4;1}

   P1 (Word_16(OD6));                                      -- OK. {4;1}

   P7 (Word_16(ON2)); -- Not out, rule does't apply.       -- OK. {4;1}

   P7 (Word_16(ON4)); -- Not out, rule does't apply.       -- OK. {4;1}
   
   P7 (Word_16(OD5)); -- Not out, rule does't apply.       -- OK. {4;1}

   P2 (Small_Float(ON3));                                  -- ERROR: [A] {4;1}
   
   P2 (Small_Float(ON4));                                  -- ERROR: [A] {4;1}
   
   P2 (Small_Float(OD2));                                  -- ERROR: [B] {4;1}
   
   P2 (Small_Float(OD4));                                  -- ERROR: [B] {4;1}

   P3 (Small_Fixed(ON4));                                  -- ERROR: [A] {4;1}

   P3 (Small_Fixed(ON1));                                  -- ERROR: [A] {4;1}
   
   P3 (Small_Fixed(OD3));                                  -- ERROR: [B] {4;1}

   P3 (Small_Fixed(OD5));                                  -- ERROR: [B] {4;1}
   
   P3 (Small_Fixed(OD4));                                  -- OK. {4;1}

   P4 (Also_Word(ON1));                                    -- OK. {4;1}

   P4 (Also_Word(ON3));                                    -- OK. {4;1}

   P4 (Also_Word(ON4));                                    -- OK. {4;1}

   -- Note: Commented out cases are OK for Ada 2012 rules, illegal for Ada
   -- 202x. We recommend following the newer rules, but do not require it.
   --P4 (Also_Word(OD2));                                  -- ERROR: [C] {4;1}

   --P4 (Also_Word(OD5));                                  -- ERROR: [C] {4;1}

   --P4 (Also_Word(OD6));                                  -- ERROR: [C] {4;1}

   P5 (Also_Fixed(ON2));                                   -- OK. {4;1}

   P5 (Also_Fixed(ON3));                                   -- OK. {4;1}

   --P5 (Also_Fixed(OD1));                                 -- ERROR: [C] {4;1}

   --P5 (Also_Fixed(OD4));                                 -- ERROR: [C] {4;1}

   --P5 (Also_Fixed(OD6));                                 -- ERROR: [C] {4;1}

   P6 (Also_Float(ON1));                                   -- OK. {4;1}

   P6 (Also_Float(ON4));                                   -- OK. {4;1}

   --P6 (Also_Float(OD2));                                 -- ERROR: [C] {4;1}

   --P6 (Also_Float(OD3));                                 -- ERROR: [C] {4;1}

   --P6 (Also_Float(OD5));                                 -- ERROR: [C] {4;1}

end B641003;
