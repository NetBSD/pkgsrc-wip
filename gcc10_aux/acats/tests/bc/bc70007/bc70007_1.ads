

     --==================================================================--


with BC70007_0;
use  BC70007_0;
package BC70007_1 is  -- Formal object support declarations.

--
-- Support declarations:
--

   type Rec is record
      Component : Boolean;
   end record;

   type Rec_Ptr is access Rec;

   Ten : constant Integer := Get_Integer_From_User;      -- Nonstatic constant.

   ValidWord : constant String := "Acceptable";


--
-- Templates for generic formal packages:
--

   generic                                       -- Template declaring a formal
      Object : in Integer;                       -- integer object of mode in.
   package Object_Integer_Template is end;

   generic                                       -- Template declaring a formal
      Object : in String;                        -- string object of mode in.
   package Object_String_Template is end;

   generic
      Object : in Rec_Ptr;                       -- Template declaring a formal
   package Object_Access_Template is end;        -- access object of mode in.


--
-- Generics containing formal package declarations:
--

   generic                                          -- Formal package actual is
      with package Formal_Package is new            -- an integer literal
        Object_Integer_Template (10);               -- (value 10).
   package Object_Literal is end;


   generic                                          -- Formal package actual is
      with package Formal_Package is new            -- a string constant
        Object_String_Template (ValidWord);         -- (value "Acceptable").
   package Object_String is end;


   generic                                          -- Formal package actual is
      with package Formal_Package is new            -- a nonstatic integer
        Object_Integer_Template (Ten);              -- constant.
   package Object_Nonstatic_Constant is end;


   generic                                          -- Formal package actual is
      with package Formal_Package is new            -- a literal null.
        Object_Access_Template (null);
   package Object_Null is end;

end BC70007_1;
