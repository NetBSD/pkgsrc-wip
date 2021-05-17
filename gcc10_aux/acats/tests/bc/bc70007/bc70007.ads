

     --==================================================================--


with BC70007_0;
with BC70007_1;

package BC70007 is

--
-- Support declarations:
--

   Null_Ptr : BC70007_1.Rec_Ptr := null;

   subtype A_Range is Integer range 1 .. 10;
   type Static_Array is array (A_Range) of Boolean;

   My_Ten : constant Integer  := BC70007_0.Get_Integer_From_User; -- Nonstatic.
   Min    : constant Integer  := A_Range'First;                   -- Static.
   Max    : constant          := 10;                              -- Static.

   Word   : constant String   := "Acceptable";                    -- Static.

   type New_Integer is new Integer;

   Value  : constant New_Integer := 10;                           -- Static.


--
-- Instances to be passed as actuals to formal packages:
--

   package Object_Instance_Same_Nonstatic_Constant       -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- nonstatic constant.
       (Object => BC70007_1.Ten);

   package Object_Instance_Different_Nonstatic_Constant  -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- nonstatic constant.
       (Object => My_Ten);

   package Object_Instance_Named_Number                  -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- a static named
       (Object => Max);                                  -- number (value 10).

   package Object_Instance_Constant                      -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- a static constant
       (Object => Min);                                  -- (value 1).

   package Object_Instance_Attribute                     -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- a static attribute
       (Object => A_Range'Last);                         -- ref. (value 10).

   package Object_Instance_Array_Bound                   -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- a static attribute
       (Object => Static_Array'Length);                  -- ref. (value 10).

   package Object_Instance_Operations                    -- Instance actual
     is new BC70007_1.Object_Integer_Template            -- calls static func-
       (Object => Max*2-4);                              -- tions (value 16).

   package Object_Instance_Conversion                    -- Instance actual is
     is new BC70007_1.Object_Integer_Template            -- a type conversion
       (Object => Integer(Value));                       -- (value 10).

   package Object_Instance_Good_String                   -- Instance actual is
     is new BC70007_1.Object_String_Template             -- a static constant.
       (Object => Word);                                 -- ("Acceptable").

   package Object_Instance_Bad_String                    -- Instance actual is
     is new BC70007_1.Object_String_Template             -- a string literal.
       (Object => "ACCEPTABLE");

   package Object_Instance_Literal_Null                  -- Instance actual is
     is new BC70007_1.Object_Access_Template             -- a literal null.
       (Object => null);

   package Object_Instance_Nonliteral_Null               -- Instance actual is
     is new BC70007_1.Object_Access_Template             -- nonstatic (access)
       (Object => Null_Ptr);       -- Null.              -- obj. (value null).


--
-- Instances of generics declaring formal packages:
--

   -- Package BC70007_1.Object_Literal:
   --
   -- The formal package is declared as follows:
   --    with package Formal_Package is new Object_Integer_Template (10);
   --
   -- The formal package actual is the literal 10.


   package Object_Static_Same_Value_1 is new
     BC70007_1.Object_Literal (Object_Instance_Named_Number);         -- OK.

   package Object_Static_Same_Value_2 is new
     BC70007_1.Object_Literal (Object_Instance_Attribute);            -- OK.

   package Object_Static_Same_Value_3 is new
     BC70007_1.Object_Literal (Object_Instance_Array_Bound);          -- OK.

   package Object_Static_Same_Value_4 is new
     BC70007_1.Object_Literal (Object_Instance_Conversion);           -- OK.

   package Object_Static_Different_Values_1 is new
     BC70007_1.Object_Literal (Object_Instance_Constant);             -- ERROR:
                                -- Corresponding actuals have different values.

   package Object_Static_Different_Values_2 is new
     BC70007_1.Object_Literal (Object_Instance_Operations);           -- ERROR:
                                -- Corresponding actuals have different values.

   package Object_Not_Both_Static_Expressions_1 is new
     BC70007_1.Object_Literal
       (Object_Instance_Different_Nonstatic_Constant);                -- ERROR:
                                 -- Instance actual is not a static expression,
                                 -- but formal package actual is.



   -- Package BC70007_1.Object_Nonstatic_Constant:
   --
   -- The formal package is declared as follows:
   --    with package Formal_Package is new Object_Integer_Template (Ten);
   --
   -- The formal package actual is the nonstatic constant BC70007_1.Ten.


   package Object_Not_Both_Static_Expressions_2 is new
     BC70007_1.Object_Nonstatic_Constant
       (Object_Instance_Attribute);                                   -- ERROR:
                                       -- Formal package actual is not a static
                                       -- expression, but instance actual is.

   package Object_Statically_Denote_Same_Constant is new
     BC70007_1.Object_Nonstatic_Constant
       (Object_Instance_Same_Nonstatic_Constant);                     -- OK.

   package Object_Statically_Denote_Different_Constant is new
     BC70007_1.Object_Nonstatic_Constant
       (Object_Instance_Different_Nonstatic_Constant);                -- ERROR:
                             -- Actuals do not statically denote same constant.



   -- Package BC70007_1.Object_String:
   --
   -- The formal package is declared as follows:
   --    with package Formal_Package is new Object_String_Template (ValidWord);
   --
   -- The formal package actual is the static constant Word ("Acceptable").

   package Object_Static_String_Same_Value is new
     BC70007_1.Object_String (Object_Instance_Good_String);           -- OK.

   package Object_Static_String_Different_Value is new
     BC70007_1.Object_String (Object_Instance_Bad_String);            -- ERROR:
                                -- Corresponding actuals have different values.



   -- Package BC70007_1.Object_Null:
   --
   -- The formal package is declared as follows:
   --    with package Formal_Package is new Object_Access_Template (null);
   --
   -- The formal package actual is the literal null.


   package Object_Both_Literal_Null is new
     BC70007_1.Object_Null (Object_Instance_Literal_Null);            -- OK.

   package Object_Not_Both_Literal_Null is new
     BC70007_1.Object_Null (Object_Instance_Nonliteral_Null);         -- ERROR:
                                    -- Instance actual is not the literal null.

end BC70007;
