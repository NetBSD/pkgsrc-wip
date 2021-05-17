

with CXA40230;
with Report;
with Ada.Characters.Handling;
with Ada.Strings.Wide_Maps;
with Ada.Strings.Wide_Unbounded;

procedure CXA4023 is
begin

   Report.Test ("CXA4023", "Check that the subprograms defined in "    &
                           "package Ada.Strings.Wide_Unbounded are "   &
                           "available, and that they produce correct " &
                           "results");

   Test_Block:
   declare

      use CXA40230;

      package ASW renames Ada.Strings.Wide_Unbounded;
      use Ada.Strings;
      use type Wide_Maps.Wide_Character_Set;
      use type ASW.Unbounded_Wide_String;

      Test_String   : ASW.Unbounded_Wide_String;
      AtoE_Str      : ASW.Unbounded_Wide_String :=
                        ASW.To_Unbounded_Wide_String(Equiv("abcde"));

      Cad_String    : ASW.Unbounded_Wide_String := 
                        ASW.To_Unbounded_Wide_String(Equiv("cad"));

      Magic_String  : ASW.Unbounded_Wide_String := 
                        ASW.To_Unbounded_Wide_String(Equiv("abracadabra"));

      Incantation   : ASW.Unbounded_Wide_String := Magic_String;


      A_Small_G : Wide_Character := Equiv('g');
      
      ABCD_Set  : Wide_Maps.Wide_Character_Set := 
                    Wide_Maps.To_Set(Equiv("abcd"));
      B_Set     : Wide_Maps.Wide_Character_Set := 
                    Wide_Maps.To_Set(Equiv('b'));
      AB_Set    : Wide_Maps.Wide_Character_Set := 
                    Wide_Maps."OR"(Wide_Maps.To_Set(Equiv('a')), B_Set);


      AB_to_YZ_Map     : Wide_Maps.Wide_Character_Mapping := 
                           Wide_Maps.To_Mapping(From => Equiv("ab"), 
                                                To   => Equiv("yz"));
      Code_Map         : Wide_Maps.Wide_Character_Mapping := 
                           Wide_Maps.To_Mapping(Equiv("abcd"), Equiv("wxyz"));
      Reverse_Code_Map : Wide_Maps.Wide_Character_Mapping :=
                           Wide_Maps.To_Mapping(Equiv("wxyz"), Equiv("abcd"));
      Non_Existent_Map : Wide_Maps.Wide_Character_Mapping :=
                           Wide_Maps.To_Mapping(Equiv("jkl"), Equiv("mno"));


      Token_Start      : Positive;
      Token_End        : Natural := 0;

      Map_Ptr  : Wide_Maps.Wide_Character_Mapping_Function :=
                   AB_to_US_Mapping_Function'Access;


   begin

      -- Find_Token

      ASW.Find_Token(Magic_String,      -- Find location of first "ab" equiv.
                     AB_Set,            -- Should be (1..2).
                     Ada.Strings.Inside,
                     Token_Start,
                     Token_End);

      if Natural(Token_Start) /= ASW.To_Wide_String(Magic_String)'First  or
         Token_End            /= ASW.Index(Magic_String, B_Set)          or
         Token_End            /= 2
      then 
         Report.Failed("Incorrect result from Procedure Find_Token - 1");
      end if;


      ASW.Find_Token(Source => Magic_String, -- Find location of char 'r'equiv
                     Set    => ABCD_Set,     -- in wide str, should be (3..3)
                     Test   => Ada.Strings.Outside,
                     First  => Token_Start,
                     Last   => Token_End);

      if Natural(Token_Start) /= 3  or  Token_End /= 3 then
         Report.Failed("Incorrect result from Procedure Find_Token - 2");
      end if;


      ASW.Find_Token(Magic_String,                -- No 'g' "equivalent in 
                     Wide_Maps.To_Set(A_Small_G), -- the wide str, so the
                     Ada.Strings.Inside,          -- result params should be 
                     First => Token_Start,        -- First = Source'First and
                     Last  => Token_End);         -- Last = 0.


      if Token_Start /= ASW.To_Wide_String(Magic_String)'First  or
         Token_End   /= 0
      then
         Report.Failed("Incorrect result from Procedure Find_Token - 3");
      end if;
 

      ASW.Find_Token(ASW.To_Unbounded_Wide_String(Equiv("abpqpqrttrcpqr")),
                     Wide_Maps.To_Set(Equiv("trpq")),
                     Ada.Strings.Inside,
                     Token_Start,
                     Token_End);

      if Token_Start /= 3 or
         Token_End   /= 10
      then
         Report.Failed("Incorrect result from Procedure Find_Token - 4");
      end if;

      ASW.Find_Token(ASW.To_Unbounded_Wide_String(Equiv("abpqpqrttrcpqr")),
                     Wide_Maps.To_Set(Equiv("abpq")),
                     Ada.Strings.Outside,
                     Token_Start,
                     Token_End);

      if Token_Start /= 7 or
         Token_End   /= 11
      then
         Report.Failed("Incorrect result from Procedure Find_Token - 5");
      end if;



      -- Translate

      -- Use a mapping ("abcd" -> "wxyz") to transform the contents of 
      -- the unbounded wide string.
      -- Magic_String = "abracadabra"

      Incantation := ASW.Translate(Magic_String, Code_Map); 

      if Incantation /= 
         ASW.To_Unbounded_Wide_String(Equiv("wxrwywzwxrw")) 
      then
         Report.Failed("Incorrect result from Function Translate - 1");
      end if;

      -- (Note: See below for additional testing of Function Translate)

      -- Use the inverse mapping of the one above to return the "translated"
      -- unbounded wide string to its original form.

      ASW.Translate(Incantation, Reverse_Code_Map);

      -- The map contained in the following call to Translate contains three
      -- elements, and these elements are not found in the unbounded wide
      -- string, so this call to Translate should have no effect on it.

      if Incantation /= ASW.Translate(Magic_String, Non_Existent_Map) then
         Report.Failed("Incorrect result from Procedure Translate - 1");
      end if;

      -- Partial mapping of source.

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("abcdeabcab"));

      ASW.Translate(Source => Test_String, Mapping => AB_to_YZ_Map);

      if Test_String /= ASW.To_Unbounded_Wide_String(Equiv("yzcdeyzcyz")) then
         Report.Failed("Incorrect result from Procedure Translate - 2");
      end if;

      -- Total mapping of source.

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("abbaaababb"));

      ASW.Translate(Source => Test_String, Mapping => AB_to_YZ_Map);

      if Test_String /= ASW.To_Unbounded_Wide_String(Equiv("yzzyyyzyzz")) then
         Report.Failed("Incorrect result from Procedure Translate - 3");
      end if;

      -- No mapping of source.

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("xyzsypcc"));

      ASW.Translate(Source => Test_String, Mapping => AB_to_YZ_Map);

      if Test_String /= ASW.To_Unbounded_Wide_String(Equiv("xyzsypcc")) then
         Report.Failed("Incorrect result from Procedure Translate - 4");
      end if;

      -- Map > 2 characters, partial mapping.

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("opabcdelmn"));

      ASW.Translate(Test_String, 
                    Wide_Maps.To_Mapping(Equiv("abcde"), Equiv("lmnop")));

      if Test_String /= ASW.To_Unbounded_Wide_String(Equiv("oplmnoplmn")) then
         Report.Failed("Incorrect result from Procedure Translate - 5");
      end if;



      -- Various degrees of mapping of source (full, partial, none) used 
      -- with Function Translate.

      if ASW.Translate(
               ASW.To_Unbounded_Wide_String(Equiv("abcdeabcabbbaaacaa")), 
                       AB_to_YZ_Map)                               /= 
         ASW.To_Unbounded_Wide_String(Equiv("yzcdeyzcyzzzyyycyy"))   or

         ASW.Translate(
               ASW.To_Unbounded_Wide_String(Equiv("abbaaababbaaaaba")), 
                       AB_to_YZ_Map)                               /= 
         ASW.To_Unbounded_Wide_String(Equiv("yzzyyyzyzzyyyyzy"))     or

         ASW.Translate(ASW.To_Unbounded_Wide_String(Equiv("cABcABBAc")),
                       Mapping => AB_to_YZ_Map)                    /= 
         ASW.To_Unbounded_Wide_String(Equiv("cABcABBAc"))            or

         ASW.Translate(ASW.To_Unbounded_Wide_String("opabcdelmnddeaccabec"),
                       Wide_Maps.To_Mapping("abcde", "lmnop"))     /=
         ASW.To_Unbounded_Wide_String("oplmnoplmnooplnnlmpn") 
      then
         Report.Failed("Incorrect result from Function Translate - 2");
      end if;



      -- Procedure Translate using access-to-subprogram mapping.
      -- Partial mapping of source.

      Map_Ptr := AB_to_Blank_Mapping_Function'Access;

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("abABaABbaBAbba"));

      ASW.Translate(Source  => Test_String, -- change equivalent of 'a' and
                    Mapping => Map_Ptr);    -- 'b' to ' '

      if Test_String /= 
         ASW.To_Unbounded_Wide_String(Equiv("  AB AB  BA   ")) 
      then
         Report.Failed
           ("Incorrect result from Proc Translate, w/ access value map - 1");
      end if;

      -- Total mapping of source to blanks.

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("abbbab"));

      ASW.Translate(Source  => Test_String, 
                    Mapping => Map_Ptr);

      if Test_String /= 
         ASW.To_Unbounded_Wide_String(Equiv("      ")) 
      then
         Report.Failed
           ("Incorrect result from Proc Translate, w/ access value map - 2");
      end if;

      -- No mapping of source.

      Map_Ptr := AB_to_US_Mapping_Function'Access;

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("xyzsypcc"));

      ASW.Translate(Source  => Test_String, 
                    Mapping => Map_Ptr);

      if Test_String /= 
         ASW.To_Unbounded_Wide_String(Equiv("xyzsypcc"))   -- no change
      then
         Report.Failed
           ("Incorrect result from Proc Translate, w/ access value map - 3");
      end if;


      -- Function Translate using access-to-subprogram mapping value.

      Map_Ptr  := AB_to_Blank_Mapping_Function'Access;

      Test_String := ASW.To_Unbounded_Wide_String(Equiv("abAbBBAabbacD"));

      if ASW.Translate(ASW.Translate(Test_String, Map_Ptr), Map_Ptr)  /=
         ASW.To_Unbounded_Wide_String(Equiv("  A BBA    cD")) 
      then
         Report.Failed
           ("Incorrect result from Function Translate, access value map - 1");
      end if;

      if ASW.Translate(Source  => ASW.To_Unbounded_Wide_String(Equiv("a")), 
                       Mapping => Map_Ptr)                            /= 
         ASW.To_Unbounded_Wide_String(Equiv(" "))                       or
         ASW.Translate(ASW.To_Unbounded_Wide_String
                         (Equiv(" aa Aa A AAaaa a   aA")),
                       Map_Ptr)                                       /=
         ASW.To_Unbounded_Wide_String(Equiv("    A  A AA         A"))   or
         ASW.Translate(Source  => ASW.To_Unbounded_Wide_String(Equiv("a ")), 
                       Mapping => Map_Ptr)                            /= 
         ASW.To_Unbounded_Wide_String(Equiv("  "))                      or
         ASW.Translate(Source  => ASW.To_Unbounded_Wide_String(Equiv("xyz")),
                       Mapping => Map_Ptr)                            /= 
         ASW.To_Unbounded_Wide_String(Equiv("xyz"))
      then
         Report.Failed
           ("Incorrect result from Function Translate, access value map - 2");
      end if;



      -- Trim

      Trim_Block:
      declare

         XYZ_Set     : Wide_Maps.Wide_Character_Set :=
                         Wide_Maps.To_Set(Equiv("xyz"));
         PQR_Set     : Wide_Maps.Wide_Character_Set := 
                         Wide_Maps.To_Set(Equiv("pqr"));

         Pad         : constant ASW.Unbounded_Wide_String := 
                                 ASW.To_Unbounded_Wide_String(Equiv("Pad"));

         The_New_Ada : constant ASW.Unbounded_Wide_String :=
                                 ASW.To_Unbounded_Wide_String(Equiv("Ada9X"));

         Space_Array : array (1..4) of ASW.Unbounded_Wide_String :=
                         (ASW.To_Unbounded_Wide_String(Equiv("  Pad    ")),
                          ASW.To_Unbounded_Wide_String(Equiv("Pad   ")),
                          ASW.To_Unbounded_Wide_String(Equiv("     Pad")),
                          Pad);

         String_Array : array (1..5) of ASW.Unbounded_Wide_String := 
                        (ASW.To_Unbounded_Wide_String(Equiv("xyzxAda9Xpqr")),
                         ASW.To_Unbounded_Wide_String(Equiv("Ada9Xqqrp")),
                         ASW.To_Unbounded_Wide_String(Equiv("zxyxAda9Xqpqr")),
                         ASW.To_Unbounded_Wide_String(Equiv("xxxyAda9X")),
                         The_New_Ada);
           
      begin

         -- Examine the version of Trim that removes blanks from
         -- the left and/or right of a wide string.

         for i in 1..4 loop
            if ASW.Trim(Space_Array(i), Ada.Strings.Both) /= Pad then
               Report.Failed("Incorrect result from Trim for spaces - " &
                             Integer'Image(i));
            end if;
         end loop;   

         -- Examine the version of Trim that removes set characters from
         -- the left and right of a wide string.

         for i in 1..5 loop
            if ASW.Trim(String_Array(i),
                        Left   => XYZ_Set,
                        Right  => PQR_Set) /= The_New_Ada then
               Report.Failed
                 ("Incorrect result from Trim for set characters - " &
                  Integer'Image(i));
            end if;
         end loop;   

         -- No trimming.

         if ASW.Trim(
              ASW.To_Unbounded_Wide_String(Equiv("prqqprAda9Xyzzxyzzyz")),
                     XYZ_Set,
                     PQR_Set)  /=
            ASW.To_Unbounded_Wide_String(Equiv("prqqprAda9Xyzzxyzzyz"))
         then
            Report.Failed
              ("Incorrect result from Trim for set, no trimming");
         end if;

      end Trim_Block;



      -- Delete

      -- Use the Delete function to remove the first four and last four
      -- characters from the wide string.

      if ASW.Delete(Source  => ASW.Delete(Magic_String,
                                          8,
                                          ASW.Length(Magic_String)),
                    From    => ASW.To_Wide_String(Magic_String)'First,
                    Through => 4)   /= 
         Cad_String
      then
         Report.Failed("Incorrect results from Function Delete");
      end if;



      -- Constructors ("*")

      Constructor_Block:
      declare
      
         SOS      : ASW.Unbounded_Wide_String;

         Dot      : constant ASW.Unbounded_Wide_String := 
                               ASW.To_Unbounded_Wide_String(Equiv("Dot_"));
         Dash     : constant Wide_String := Equiv("Dash_");

         Distress : ASW.Unbounded_Wide_String := 
                      ASW."&"(ASW.To_Unbounded_Wide_String
                                (Equiv("Dot_Dot_Dot_")),
                              ASW."&"(ASW.To_Unbounded_Wide_String
                                        (Equiv("Dash_Dash_Dash_")), 
                                      ASW.To_Unbounded_Wide_String
                                        (Equiv("Dot_Dot_Dot"))));
                      
         Repeat        : constant Natural        := 3;
         Separator     : constant Wide_Character := Equiv('_');

         Separator_Set : Wide_Maps.Wide_Character_Set := 
                           Wide_Maps.To_Set(Separator);

      begin

         -- Use the following constructor forms to construct the wide string
         -- "Dot_Dot_Dot_Dash_Dash_Dash_Dot_Dot_Dot".  Note that the 
         -- trailing underscore in the wide string is removed in the call to 
         -- Trim in the If statement condition.

         SOS := ASW."*"(Repeat, Dot);                   -- "*"(#, W Unb Str)

         SOS := ASW."&"(SOS,
                        ASW."&"(ASW."*"(Repeat, Dash),  -- "*"(#, W Str)
                                ASW."*"(Repeat, Dot))); -- "*"(#, W Unb Str)

         if ASW.Trim(SOS, Wide_Maps.Null_Set, Separator_Set) /= Distress then
            Report.Failed("Incorrect results from Function ""*""");
         end if;

      end Constructor_Block;
      

   exception
      when others => Report.Failed ("Exception raised in Test_Block");
   end Test_Block;


   Report.Result;

end CXA4023;
