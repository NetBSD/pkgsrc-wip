

     --==================================================================--


generic
   type Item_Type is tagged private;     -- Formal (tagged) private type.
package BC51B01_1 is

   subtype My_Item is Item_Type;         -- Does not require definite formal.

end BC51B01_1;
