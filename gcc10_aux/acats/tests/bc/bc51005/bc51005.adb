
-- No body for BC51005_3.


     --==================================================================--


with BC51005_0;  -- Type definitions.
with BC51005_1;  -- Defaulted record formal types.
with BC51005_2;  -- Undefaulted record formal types.
with BC51005_3;  -- Access formal types.
procedure BC51005 is

--
-- Record Types :
--

   package Record_Dflt_Unconstrained_Subtype is new
     BC51005_1 (BC51005_0.My_Messages);                               -- OK.
 

   package Record_Dflt_Ancestor is new
     BC51005_1 (BC51005_0.Msg_Type);                                  -- OK.

 
   package Record_Dflt_Constrained_Subtype is new
     BC51005_1 (BC51005_0.Msg_Len6);                                  -- ERROR:
                                                         -- Actual constrained.

   package Record_Dflt_Constrained_Derived is new
     BC51005_1 (BC51005_0.Msg_Len50);                                 -- ERROR:
                                                         -- Actual constrained.



   package Record_NoDflt_Unconstrained_Derived is new
     BC51005_2 (BC51005_0.My_List);                                   -- OK.


   package Record_NoDflt_Ancestor is new
     BC51005_2 (BC51005_0.List_Type);                                 -- OK.


   package Record_NoDflt_Constrained_Subtype is new
     BC51005_2 (BC51005_0.Ten_Num);                                   -- ERROR:
                                                         -- Actual constrained.

   package Record_NoDflt_Constrained_Derived is new
     BC51005_2 (BC51005_0.My_Ten_Num);                                -- ERROR:
                                                         -- Actual constrained.


--
-- Access Types :
--

   package Access_Unconstrained_Derived is new
     BC51005_3 (BC51005_0.New_Msg_Ptr);                               -- OK.


   package Access_Ancestor is new
     BC51005_3 (BC51005_0.Msg_Ptr);                                   -- OK.


   package Access_Constrained_Subtype is new
     BC51005_3 (BC51005_0.Msg_Len6_Ptr);                              -- ERROR:
                                                         -- Actual constrained.

   package Access_Constrained_Derived is new
     BC51005_3 (BC51005_0.Msg_Len8_Ptr);                              -- ERROR:
                                                         -- Actual constrained.

begin
   null;
end BC51005;
