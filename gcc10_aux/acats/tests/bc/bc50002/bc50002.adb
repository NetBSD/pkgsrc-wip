

     --==================================================================--


with BC50002_0;  -- Type definitions.
with BC50002_1;  -- Record formal derived type.
with BC50002_2;  -- Tagged formal derived type.
procedure BC50002 is

  -- NOTE: A specific type is a descendant of itself.

--
-- Record types :
--

   package Record_Ancestor is new BC50002_1
     (BC50002_0.Local_Peripheral);                                    -- OK.


   package Record_Child is new BC50002_1
      (BC50002_0.Local_Storage);                                      -- OK.


   package Record_Grandchild is new BC50002_1
     (BC50002_0.Local_Disk);                                          -- OK.


   package Record_Root is new BC50002_1
     (BC50002_0.Peripheral);                                          -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Record_Sibling is new BC50002_1
     (BC50002_0.Remote_Peripheral);                                   -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Record_Nephew is new BC50002_1
     (BC50002_0.Remote_Output);                                       -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

--
-- Tagged types :
--

   package Tagged_Ancestor is new BC50002_2
     (BC50002_0.Operation);                                           -- OK.


   package Ancestor_Class_Wide is new BC50002_2
     (BC50002_0.Operation'Class);                                     -- OK.


   package Tagged_Child is new BC50002_2
     (BC50002_0.Binary_Operation);                                    -- OK.


   package Child_Class_Wide is new BC50002_2
     (BC50002_0.Binary_Operation'Class);                              -- OK.


   package Tagged_Grandchild is new BC50002_2
     (BC50002_0.Addition);                                            -- OK.


   package Tagged_Root is new BC50002_2
     (BC50002_0.Expression);                                          -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Root_Class_Wide is new BC50002_2
     (BC50002_0.Expression'Class);                                    -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Tagged_Sibling is new BC50002_2
     (BC50002_0.Literal);                                             -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Sibling_Class_Wide is new BC50002_2
     (BC50002_0.Literal'Class);                                       -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

   package Tagged_Nephew is new BC50002_2
     (BC50002_0.Numeric_Literal);                                     -- ERROR:
                                 -- Actual is not a descendant of the ancestor.

begin
   null;
end BC50002;
