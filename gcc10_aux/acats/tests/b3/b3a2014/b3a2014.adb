

     --==================================================================--


package body B3A2014 is

--
-- Tagged type subtests:
--

   XNew_Tag_1  : aliased New_Tag_1;
   XNNew_Tag_2 : aliased NNew_Tag_2;
   XTClass     : aliased Tag_Type'Class  := New_Tag_2'(I => 23, B => True); 
   XT2Class    : aliased New_Tag_2'Class := New_Tag_2'(I => 54, B => False); 


   AT1  : AccNew_Tag_2 := XNNew_Tag_2'Access;                         -- ERROR:
                       -- Type of XNNew_Tag_2 is not covered by designated type 
                       -- of AccNew_Tag_2.

   AT2  : AccNew_Tag_2 := XT2Class'Access;                            -- ERROR:
                       -- Type of XT2Class is not covered by designated type of 
                       -- AccNew_Tag_2.


   ATC1 : AccNew_Tag2Class := XNew_Tag_1'Access;                      -- ERROR:
                        -- Type of XNew_Tag_1 is not covered by designated type 
                        -- of AccNew_Tag2Class.

   ATC2 : AccNew_Tag2Class := XTClass'Access;                         -- ERROR:
                        -- Type of XTClass is not covered by designated type of 
                        -- AccNew_Tag2Class.
 
   ATC3 : AccNew_Tag2Class := XNNew_Tag_2'Access;                     -- OK.


   procedure Op1 (P: in out Tag_Type) is
      type AccNew_Tag_2     is access all New_Tag_2;
      type AccNew_Tag2Class is access all New_Tag_2'Class;
      Ptr1 : AccNew_Tag_2;
      Ptr2 : AccNew_Tag2Class;
   begin
      Ptr1 := P'Access;                                               -- ERROR:
                              -- Type of P is not covered by designated type of 
                              -- AccNew_Tag_2.

      Ptr2 := P'Access;                                               -- ERROR:
                              -- Type of P is not covered by designated type of 
                              -- AccNew_Tag_2Class.
   end Op1;

   procedure Op2 (P: in out New_Tag_2) is
      type AccNew_Tag_2     is access all New_Tag_2;
      type AccNew_Tag2Class is access all New_Tag_2'Class;
      Ptr1 : AccNew_Tag_2;
      Ptr2 : AccNew_Tag2Class;
   begin
      Ptr1 := P'Access;                                               -- OK.
      Ptr2 := P'Access;                                               -- OK.
   end Op2;

   procedure Op3 (P: in out NNew_Tag_2'Class) is
      type AccNew_Tag2Class is access all New_Tag_2'Class;
      Ptr : AccNew_Tag2Class;
   begin
      Ptr := P'Access;                                                -- OK.
   end Op3;

   procedure Op4 (P: in out Tag_Type'Class) is
      type AccNew_Tag2Class is access all New_Tag_2'Class;
      Ptr : AccNew_Tag2Class;
   begin
      Ptr := P'Access;                                                -- ERROR:
                              -- Type of P is not covered by designated type of 
                              -- AccNew_Tag2Class.
   end Op4;



--
-- Record type subtests:
--

   ARec_1   : AccRec          := XRec'Access;                         -- OK.

   ARec2_1  : AccRec2_Subtype := XRec'Access;                         -- ERROR:
                   -- Designated subtype of AccRec2_Subtype does not statically
                   -- match nominal subtype of XRec and is not unconstrained.
          
   ARecC2_1 : AccRec2         := XRec'Access;                         -- ERROR:
                     -- Designated subtype of AccRec2 does not statically match
                     -- nominal subtype of XRec and is not unconstrained.
                     
   ASRec_1  : AccRec_Subtype  := XRec'Access;                         -- OK.
                          -- Designated subtype of AccRec_Subtype statically 
                          -- matches nominal subtype of XRec.


   ARec_2   : AccRec          := XRec2_Subtype'Access;                -- OK.
         -- Designated subtype of AccRec is discriminated and unconstrained.

   ARec2_2  : AccRec2_Subtype := XRec2_Subtype'Access;                -- OK.
                         -- Designated subtype of AccRec2_Subtype statically 
                         -- matches nominal subtype of XRec2.

   ARecC2_2 : AccRec2         := XRec2_Subtype'Access;                -- OK.
                         -- Designated subtype of AccRec2 statically matches
                         -- nominal subtype of XRec2.

   ASRec_2  : AccRec_Subtype  := XRec2_Subtype'Access;                -- OK.
                    -- Designated subtype of AccRec_Subtype is discriminated 
                    -- and unconstrained.


--
-- Array type subtests:
--

   AStr_1   : AccStr   := XStr'Access;                                -- OK.

   AStr4_1  : AccStr4  := XStr'Access;                                -- ERROR:
                           -- Designated subtype of AccStr4 does not statically 
                           -- match nominal subtype of XStr (although it does
                           -- match the actual subtype of XStr).

   ASStr    : AccSStr  := XStr'Access;                                -- OK.
                         -- Designated subtype of AccSStr statically matches
                         -- nominal subtype of XStr.

   AMyStr   : AccMyStr := XStr'Access;                                -- ERROR:
                         -- Designated subtype of AccMyStr is of different type
                         -- than subtype of XStr.


   AStr_2   : AccStr   := XStr4'Access;                               -- ERROR:
                            -- Designated subtype of AccStr does not statically
                            -- match nominal subtype of XStr4.

   AStr4_2  : AccStr4  := XStr4'Access;                               -- OK.

end B3A2014;
