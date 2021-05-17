

with CXA4026_0;
with Ada.Strings.Fixed;
with Ada.Strings.Maps;
with Ada.Characters.Handling;
with Ada.Characters.Latin_1;
with Report;

procedure CXA4026 is

begin

   Report.Test ("CXA4026", "Check that procedures Trim, Head, and Tail, " &
                           "as well as the versions of subprograms "      &
                           "Translate, Index, and Count, which use the "  &
                           "Character_Mapping_Function input parameter,"  &
                           "produce correct results");

   Test_Block:
   declare

      use Ada.Strings, CXA4026_0;

      -- The following strings are used in examination of the Translation
      -- subprograms.

      New_Character_String : String(1..10) :=
                               Ada.Characters.Latin_1.LC_A_Grave          &
                               Ada.Characters.Latin_1.LC_A_Ring           &
                               Ada.Characters.Latin_1.LC_AE_Diphthong     &
                               Ada.Characters.Latin_1.LC_C_Cedilla        &
                               Ada.Characters.Latin_1.LC_E_Acute          &
                               Ada.Characters.Latin_1.LC_I_Circumflex     &
                               Ada.Characters.Latin_1.LC_Icelandic_Eth    &
                               Ada.Characters.Latin_1.LC_N_Tilde          &
                               Ada.Characters.Latin_1.LC_O_Oblique_Stroke &
                               Ada.Characters.Latin_1.LC_Icelandic_Thorn;  
 

      TC_New_Character_String : String(1..10) :=
                               Ada.Characters.Latin_1.UC_A_Grave          &
                               Ada.Characters.Latin_1.UC_A_Ring           &
                               Ada.Characters.Latin_1.UC_AE_Diphthong     &
                               Ada.Characters.Latin_1.UC_C_Cedilla        &
                               Ada.Characters.Latin_1.UC_E_Acute          &
                               Ada.Characters.Latin_1.UC_I_Circumflex     &
                               Ada.Characters.Latin_1.UC_Icelandic_Eth    &
                               Ada.Characters.Latin_1.UC_N_Tilde          &
                               Ada.Characters.Latin_1.UC_O_Oblique_Stroke &
                               Ada.Characters.Latin_1.UC_Icelandic_Thorn;  


      -- Functions used to supply mapping capability.


      -- Access objects that will be provided as parameters to the 
      -- subprograms.

      Map_To_Lower_Case_Ptr : Maps.Character_Mapping_Function :=
                                Map_To_Lower_Case'Access;

      Map_To_Upper_Case_Ptr : Maps.Character_Mapping_Function :=
                                Map_To_Upper_Case'Access;


   begin

      -- Function Index, Forward direction search.
      -- Note: Several of the following cases use the default value
      --       Forward for the Going parameter.

      if Fixed.Index(Source => "The library package Strings.Fixed",
                     Pattern => "fix",
                     Going   => Ada.Strings.Forward,
                     Mapping => Map_To_Lower_Case_Ptr)    /= 29   or
         Fixed.Index("THE RAIN IN SPAIN FALLS MAINLY ON THE PLAIN",
                     "ain",
                     Mapping => Map_To_Lower_Case_Ptr)    /= 6    or
         Fixed.Index("maximum number",
                     "um",
                     Ada.Strings.Forward,
                     Map_To_Lower_Case_Ptr)               /= 6    or
         Fixed.Index("CoMpLeTeLy MiXeD CaSe StRiNg",
                     "MIXED CASE STRING",
                     Ada.Strings.Forward,
                     Map_To_Upper_Case_Ptr)               /= 12   or
         Fixed.Index("STRING WITH NO MATCHING PATTERNS",
                     "WITH",
                     Ada.Strings.Forward,
                     Map_To_Lower_Case_Ptr)               /= 0    or
         Fixed.Index("THIS STRING IS IN UPPER CASE",
                     "IS",
                     Ada.Strings.Forward,
                     Map_To_Upper_Case_Ptr)               /= 3    or
         Fixed.Index("",  -- Null string.
                     "is",
                     Mapping => Map_To_Lower_Case_Ptr)    /= 0    or
         Fixed.Index("AAABBBaaabbb",
                     "aabb",
                     Mapping => Map_To_Lower_Case_Ptr)    /= 2
      then
         Report.Failed("Incorrect results from Function Index, going "    &
                       "in Forward direction, using a Character Mapping " &
                       "Function parameter");
      end if;



      -- Function Index, Backward direction search.

      if Fixed.Index("Case of a Mixed Case String", 
                     "case", 
                     Ada.Strings.Backward,
                     Map_To_Lower_Case_Ptr)               /= 17   or
         Fixed.Index("Case of a Mixed Case String", 
                     "CASE", 
                     Ada.Strings.Backward,
                     Map_To_Upper_Case_Ptr)               /= 17   or
         Fixed.Index("rain, Rain, and more RAIN",
                     "rain",
                     Ada.Strings.Backward,
                     Map_To_Lower_Case_Ptr)               /= 22   or
         Fixed.Index("RIGHT place, right time",
                     "RIGHT",
                     Ada.Strings.Backward,
                     Map_To_Upper_Case_Ptr)               /= 14   or
         Fixed.Index("WOULD MATCH BUT FOR THE CASE",
                     "WOULD MATCH BUT FOR THE CASE",
                     Ada.Strings.Backward,
                     Map_To_Lower_Case_Ptr)               /= 0
      then
         Report.Failed("Incorrect results from Function Index, going "     &
                       "in Backward direction, using a Character Mapping " &
                       "Function parameter");
      end if;



      -- Function Index, Pattern_Error if Pattern = Null_String

      declare
         use Ada.Strings.Fixed;
         Null_Pattern_String : constant String := "";
         TC_Natural          : Natural         := 1000;
      begin
         TC_Natural := Index("A Valid String", 
                             Null_Pattern_String,
                             Ada.Strings.Forward,
                             Map_To_Lower_Case_Ptr);
         Report.Failed("Pattern_Error not raised by Function Index when " &
                       "given a null pattern string");
      exception
         when Pattern_Error => null;   -- OK, expected exception.
         when others        =>
            Report.Failed("Incorrect exception raised by Function Index " &
                          "using a Character Mapping Function parameter " &
                          "when given a null pattern string");
      end;



      -- Function Count.

      if Fixed.Count(Source  => "ABABABA",        
                     Pattern => "aba",
                     Mapping => Map_To_Lower_Case_Ptr)        /=  2   or
         Fixed.Count("ABABABA", "ABA", Map_To_Lower_Case_Ptr) /=  0   or
         Fixed.Count("This IS a MISmatched issue",
                     "is",
                     Map_To_Lower_Case_Ptr)                   /=  4   or
         Fixed.Count("ABABABA", "ABA", Map_To_Upper_Case_Ptr) /=  2   or
         Fixed.Count("This IS a MISmatched issue",
                     "is",
                     Map_To_Upper_Case_Ptr)                   /=  0   or
         Fixed.Count("She sells sea shells by the sea shore",
                     "s",
                     Map_To_Lower_Case_Ptr)                   /=  8   or
         Fixed.Count("",                       -- Null string.
                     "match",
                     Map_To_Upper_Case_Ptr)                   /=  0
      then
         Report.Failed("Incorrect results from Function Count, using " &
                       "a Character Mapping Function parameter");
      end if;



      -- Function Count, Pattern_Error if Pattern = Null_String

      declare
         use Ada.Strings.Fixed;
         Null_Pattern_String : constant String := "";
         TC_Natural          : Natural         := 1000;
      begin
         TC_Natural := Count("A Valid String", 
                             Null_Pattern_String,
                             Map_To_Lower_Case_Ptr);
         Report.Failed("Pattern_Error not raised by Function Count using " &
                       "a Character Mapping Function parameter when "      &
                       "given a null pattern string");
      exception
         when Pattern_Error => null;   -- OK, expected exception.
         when others        =>
            Report.Failed("Incorrect exception raised by Function Count " &
                          "using a Character Mapping Function parameter " &
                          "when given a null pattern string");
      end;



      -- Function Translate.

      if Fixed.Translate(Source  => "A Sample Mixed Case String",
                         Mapping => Map_To_Lower_Case_Ptr) /= 
         "a sample mixed case string"                         or

         Fixed.Translate("ALL LOWER CASE",
                         Map_To_Lower_Case_Ptr)            /= 
         "all lower case"                                     or

         Fixed.Translate("end with lower case",
                         Map_To_Lower_Case_Ptr)            /= 
         "end with lower case"                                or

         Fixed.Translate("", Map_To_Lower_Case_Ptr)        /=
         ""                                                   or

         Fixed.Translate("start with lower case",
                         Map_To_Upper_Case_Ptr)            /= 
         "START WITH LOWER CASE"                              or

         Fixed.Translate("ALL UPPER CASE STRING",
                         Map_To_Upper_Case_Ptr)            /=
         "ALL UPPER CASE STRING"                              or

         Fixed.Translate("LoTs Of MiXeD CaSe ChArAcTeRs",
                         Map_To_Upper_Case_Ptr)            /=
         "LOTS OF MIXED CASE CHARACTERS"                      or

         Fixed.Translate("", Map_To_Upper_Case_Ptr)        /=
         ""                                                   or

         Fixed.Translate(New_Character_String,
                         Map_To_Upper_Case_Ptr)            /=
         TC_New_Character_String
      then
         Report.Failed("Incorrect results from Function Translate, using " &
                       "a Character Mapping Function parameter");
      end if;



      -- Procedure Translate.

      declare

         use Ada.Strings.Fixed;

         Str_1    : String(1..24)   := "AN ALL UPPER CASE STRING";
         Str_2    : String(1..19)   := "A Mixed Case String";
         Str_3    : String(1..32)   := "a string with lower case letters";
         TC_Str_1 : constant String := Str_1;
         TC_Str_3 : constant String := Str_3;

      begin

         Translate(Source => Str_1, Mapping => Map_To_Lower_Case_Ptr);

         if Str_1 /= "an all upper case string" then
            Report.Failed("Incorrect result from Procedure Translate - 1");
         end if;

         Translate(Source => Str_1, Mapping => Map_To_Upper_Case_Ptr);

         if Str_1 /= TC_Str_1 then
            Report.Failed("Incorrect result from Procedure Translate - 2");
         end if;

         Translate(Source => Str_2, Mapping => Map_To_Lower_Case_Ptr);

         if Str_2 /= "a mixed case string" then
            Report.Failed("Incorrect result from Procedure Translate - 3");
         end if;

         Translate(Source => Str_2, Mapping => Map_To_Upper_Case_Ptr);

         if Str_2 /= "A MIXED CASE STRING" then
            Report.Failed("Incorrect result from Procedure Translate - 4");
         end if;

         Translate(Source => Str_3, Mapping => Map_To_Lower_Case_Ptr);

         if Str_3 /= TC_Str_3 then
            Report.Failed("Incorrect result from Procedure Translate - 5");
         end if;

         Translate(Source => Str_3, Mapping => Map_To_Upper_Case_Ptr);

         if Str_3 /= "A STRING WITH LOWER CASE LETTERS" then
            Report.Failed("Incorrect result from Procedure Translate - 6");
         end if;

         Translate(New_Character_String, Map_To_Upper_Case_Ptr);

         if New_Character_String /= TC_New_Character_String then
            Report.Failed("Incorrect result from Procedure Translate - 6");
         end if;

      end;


      -- Procedure Trim.

      declare
         Use Ada.Strings.Fixed;
         Trim_String : String(1..30) := "    A string of characters    ";
      begin

         Trim(Source  => Trim_String,
              Side    => Ada.Strings.Left,
              Justify => Ada.Strings.Right,
              Pad     => 'x');
         
         if Trim_String /= "xxxxA string of characters    " then
            Report.Failed("Incorrect result from Procedure Trim, trim " &
                          "side = left, justify = right, pad = x");
         end if;

         Trim(Trim_String, Ada.Strings.Right, Ada.Strings.Center);

         if Trim_String /= "  xxxxA string of characters  " then
            Report.Failed("Incorrect result from Procedure Trim, trim " &
                          "side = right, justify = center, default pad");
         end if;

         Trim(Trim_String, Ada.Strings.Both, Pad => '*');

         if Trim_String /= "xxxxA string of characters****" then
            Report.Failed("Incorrect result from Procedure Trim, trim " &
                          "side = both, default justify, pad = *");
         end if;

      end;


      -- Procedure Head.

      declare
         Fixed_String : String(1..20) := "A sample test string";
      begin

         Fixed.Head(Source  => Fixed_String,
                    Count   => 14,
                    Justify => Ada.Strings.Center,
                    Pad     => '$');

         if Fixed_String /= "$$$A sample test $$$" then
            Report.Failed("Incorrect result from Procedure Head, " &
                          "justify = center, pad = $");
         end if;

         Fixed.Head(Fixed_String, 11, Ada.Strings.Right);

         if Fixed_String /= "         $$$A sample" then
            Report.Failed("Incorrect result from Procedure Head, " &
                          "justify = right, default pad");
         end if;

         Fixed.Head(Fixed_String, 9, Pad => '*');
 
         if Fixed_String /= "         ***********" then
            Report.Failed("Incorrect result from Procedure Head, " &
                          "default justify, pad = *");
         end if;

      end;


      -- Procedure Tail.

      declare
         Use Ada.Strings.Fixed;
         Tail_String : String(1..20) := "ABCDEFGHIJKLMNOPQRST";
      begin

         Tail(Source => Tail_String, Count => 10, Pad => '-');

         if Tail_String /= "KLMNOPQRST----------" then
            Report.Failed("Incorrect result from Procedure Tail, " &
                          "default justify, pad = -");
         end if;

         Tail(Tail_String, 6, Justify => Ada.Strings.Center, Pad => 'a');

         if Tail_String /= "aaaaaaa------aaaaaaa" then
            Report.Failed("Incorrect result from Procedure Tail, " &
                          "justify = center, pad = a");
         end if;

         Tail(Tail_String, 1, Ada.Strings.Right);

         if Tail_String /= "                   a" then
            Report.Failed("Incorrect result from Procedure Tail, " &
                          "justify = right, default pad");
         end if;

         Tail(Tail_String, 19, Ada.Strings.Right, 'A');

         if Tail_String /= "A                  a" then
            Report.Failed("Incorrect result from Procedure Tail, " &
                          "justify = right, pad = A");
         end if;

      end;

   exception
      when others => Report.Failed ("Exception raised in Test_Block");
   end Test_Block;


   Report.Result;

end CXA4026;
