

     --==================================================================--


with BC51007_0;  -- Type definitions.
with BC51007_1;  -- Record formal type.
with BC51007_2;  -- Tagged formal type.
package BC51007 is

--
-- Record types:
--

   package Record_Ancestor_Type is new
     BC51007_1 (BC51007_0.Msg_Type);                                  -- OK.


   package Record_Derived_No_New_Discriminants is new
     BC51007_1 (BC51007_0.My_Msg);                                    -- OK.


   package Record_Corresponding_Discriminants is new
     BC51007_1 (BC51007_0.Msg_Max10);                                 -- OK.


--
-- Tagged types:
--

   package Tagged_Ancestor_Type is new
     BC51007_2 (BC51007_0.Ext_Msg);                                   -- OK.


   package Tagged_Derived_No_New_Discriminants is new
     BC51007_2 (BC51007_0.My_Ext_Msg);                                -- OK.


   package Tagged_NonCorresponding_Discriminants is new
     BC51007_2 (BC51007_0.Attrib_Msg_Type);                           -- ERROR:
                                            -- Discriminants do not correspond.

   package Tagged_Different_Number_Of_Discriminants is new
     BC51007_2 (BC51007_0.Append_Msg_Type);                           -- ERROR:
                                          -- Actual has too many discriminants.

   package Tagged_Unknown_Discriminants is new
     BC51007_2 (BC51007_0.Priv_Msg_Type);                             -- ERROR:
                                           -- Actual has unknown discriminants.

   package Tagged_Class_Wide is new
     BC51007_2 (BC51007_0.Ext_Msg'Class);                             -- ERROR:
                              -- Actual has unknown discriminants (class-wide).

end BC51007;
