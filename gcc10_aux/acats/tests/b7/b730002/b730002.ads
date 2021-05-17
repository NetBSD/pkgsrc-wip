

     --==================================================================--


with B730002_0;
use  B730002_0;
package B730002 is

--
-- Nonlimited cases:
--
   -- Untagged private types:

   type NL_Untag_Priv1 is private;
   type NL_Untag_Priv2 is private;


   -- Tagged private types:

   type NL_Tag_Priv1 is tagged private;
   type NL_Tag_Priv2 is tagged private;


--
-- Limited cases:
--
   -- Untagged private types:

   type L_Untag_Priv1 is limited private;
   type L_Untag_Priv2 is limited private;


   -- Tagged private types:

   type L_Tag_Priv1 is tagged limited private;
   type L_Tag_Priv2 is tagged limited private;


--
-- Private extensions:
--

   type Pri_Ext1 is new Lim_Ancestor with private;
   type Pri_Ext2 is new Lim_Ancestor with private;
   type Pri_Ext3 is new Lim_Ancestor with private;
   type Pri_Ext4 is new Lim_Ancestor with private;
   type Pri_Ext5 is new Lim_Ancestor with private;
   type Pri_Ext6 is new Lim_Ancestor'Class with null record;          -- ERROR:
                                 -- Ancestor type must be specific tagged type.

   -- Check that private extension is limited if its ancestor is:

   Obj1 : Lim_Pri_Ext;                                                
   Obj2 : Lim_Pri_Ext;                                                
   Obj3 : Lim_Pri_Ext := Obj1;                                        -- ERROR:
                        -- Type of object is limited; assignment not available.

   Obj4 : Boolean := (Obj1 = Obj2);                                   -- ERROR:
             -- Type of operands is limited; predefined equality not available.


private

--
-- Nonlimited cases (full view must be nonlimited):
--
   -- Untagged private types:

   -- Even though partial view is untagged, full view may be tagged.

   type NL_Untag_Priv1 is new NonLim_Root with null record;           -- OK.
   type NL_Untag_Priv2 is new Lim_Root    with null record;           -- ERROR:
                                               -- Full view must be nonlimited.

   -- Tagged private types:

   type NL_Tag_Priv1 is new NonLim_Derived with null record;          -- OK.
   type NL_Tag_Priv2 is new Lim_Ancestor   with null record;          -- ERROR:
                                               -- Full view must be nonlimited.


--
-- Limited cases:
--
   -- Untagged private types (full view may be limited or nonlimited):

   -- Even though partial view is untagged, full view may be tagged.

   type L_Untag_Priv1 is new Lim_Ancestor   with null record;         -- OK.
   type L_Untag_Priv2 is new NonLim_Derived with null record;         -- OK.


   -- Tagged private types (full view must be limited):

   type L_Tag_Priv1 is new Lim_Root    with null record;              -- OK.
   type L_Tag_Priv2 is new NonLim_Root with null record;              -- ERROR:
                                                 -- Parent type is not limited.


--
-- Private extensions:
--

   -- Check that parent must be derived (directly or indirectly) from ancestor:

   type Pri_Ext1 is new Lim_Ancestor with null record;                -- OK.
   type Pri_Ext2 is new Lim_Child    with null record;                -- OK.
   type Pri_Ext3 is new Lim_GrnChild with null record;                -- OK.
   type Pri_Ext4 is new Lim_Root     with null record;                -- ERROR:
                                           -- Parent not derived from ancestor.

   type Pri_Ext5 is new Lim_Sibling  with null record;                -- ERROR:
                                           -- Parent not derived from ancestor.

   -- Partial view is limited, full view is nonlimited.

   Obj5 : L_Untag_Priv2;                                                
   Obj6 : L_Untag_Priv2;                                                
   Obj7 : L_Untag_Priv2 := Obj5;                                      -- OK.
   Obj8 : Boolean := (Obj5 = Obj6);                                   -- OK.

end B730002;
