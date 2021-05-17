

     --==================================================================--


package B730003_0.B730003 is            -- Public child unit.

   -- Check that if the full view of a private untagged type is tagged,
   -- no derivatives of the private type are allowed within the immediate
   -- scope of the private type:

   type Der_Type2 is new Untag_Partial_02;                            -- ERROR:
               -- Derivation in the immediate scope of an untagged partial view 
               -- whose full view is tagged.

   type Tag_Priv1 is tagged private;
   type Tag_Priv2 is tagged private;
   type Tag_Priv3 is tagged private;
   type Tag_Priv4 is tagged private;

   type Tagged_Rec is tagged record
      C : Integer;
   end record;

   type Untag_Partial_03 is private;
   type Untag_Partial_04 is private;
 
private

   type Der_Type3 is new Untag_Partial_02 with null record;           -- OK.
                                    -- Legal because derived from full view.

   -- Check that if the partial view is tagged, the full view must be:
   
   type Tag_Priv1 is tagged null record;                              -- OK.
   type Tag_Priv2 is new Der_Type3 with null record;                  -- OK.
   type Tag_Priv3 is null record;                                     -- ERROR:
                                                        -- Type must be tagged.

   type Tag_Priv4 is new Untag_Partial_01;                            -- ERROR:
                                                        -- Type must be tagged.

   type Untag_Partial_03 is tagged record
      C : Boolean;
   end record;

   type Untag_Partial_04 is new Tagged_Rec with null record;

   type Tag_PrivA is new Untag_Partial_03 with null record;           -- OK.

   type Tag_PrivB is new Untag_Partial_04 with null record;           -- OK.

end B730003_0.B730003;
