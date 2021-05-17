
with Report;
package body C431001_0 is

   function Summary (R       : in Recording;
                     TC_Type : in TC_Type_ID) return String is
   begin

      if TC_Type /= TC_Recording then
         Report.Failed ("Did not dispatch on tag for tagged parent " &
                        "type Recording");
      end if;

      return R.Artist (1..10)
             & ' ' & Genre'Image (R.Category) (1..2)
             & ' ' & Duration'Image (R.Length)
             & ' ' & Integer'Image (R.Selections);

   end Summary;

   function Summary (Disc    : in CD;
                     TC_Type : in TC_Type_ID) return String is
   begin

      if TC_Type /= TC_CD then
         Report.Failed ("Did not dispatch on tag for type extension " &
                        "CD");
      end if;

      return Summary (Recording (Disc), TC_Type => TC_Recording)
         & ' ' & Recording_Method'Image(Disc.Recorded)(1)
         & Recording_Method'Image(Disc.Mastered)(1);

   end Summary;

   function Summary (Album   : in Vinyl;
                     TC_Type : in TC_Type_ID)  return String is
   begin
      if TC_Type /= TC_Vinyl then
         Report.Failed ("Did not dispatch on tag for type extension " &
                        "Vinyl");
      end if;

      case Album.Speed is
      when LP_33 =>
         return Summary (Recording (Album), TC_Type => TC_Recording)
            & " 33";
      when Single_45 =>
         return Summary (Recording (Album), TC_Type => TC_Recording)      
            & " 45";
      when Old_78 =>
         return Summary (Recording (Album), TC_Type => TC_Recording)      
            & " 78";
      end case;

   end Summary;

   function Summary (Disk    : in CD_ROM;
                     TC_Type : in TC_Type_ID)  return String is
   begin
      if TC_Type /= TC_CD_ROM then
         Report.Failed ("Did not dispatch on tag for type extension " &
                        "CD_ROM. This is an extension of the type " &
                        "extension CD");
      end if;

      return Summary (Recording(Disk), TC_Type => TC_Recording)
         & ' ' & Integer'Image (Disk.Storage) & 'K';

   end Summary;

   function Catalog_Entry (R       : in Recording'Class;
                           TC_Type : in TC_Type_ID) return String is
   begin
      return Summary (R, TC_Type); -- dispatched call
   end Catalog_Entry;

   procedure Print (S : in String) is
      T : String (1..S'Length) := Report.Ident_Str (S);
   begin
      -- Ada.Text_IO.Put_Line (S);
      null;
   end Print;
   
   -- Bodies for null type checks
   procedure TC_Check (N       : in Null_Tagged;
                       TC_Type : in TC_N_Type_ID) is
   begin
      if TC_Type /= TC_Null_Tagged then
         Report.Failed ("Did not dispatch on tag for null tagged " &
                        "type Null_Tagged");
      end if;
   end TC_Check;

   procedure TC_Check (N       : in Null_Extension;
                       TC_Type : in TC_N_Type_ID) is
   begin
      if TC_Type /= TC_Null_Extension then
         Report.Failed ("Did not dispatch on tag for null tagged " &
                        "type extension Null_Extension");
      end if;
   end TC_Check;
   
   procedure TC_Check (N       : in Extension_Of_Null;
                       TC_Type : in TC_N_Type_ID) is
   begin
      if TC_Type /= TC_Extension_Of_Null then
         Report.Failed
            ("Did not dispatch on tag for extension of null parent" &
             "type");
      end if;
   end TC_Check;

   procedure TC_Check (N       : in Null_Extension_Of_Nonnull;
                       TC_Type : in TC_N_Type_ID) is
   begin
      if TC_Type /= TC_Null_Extension_Of_Nonnull then
         Report.Failed
            ("Did not dispatch on tag for null extension of nonnull " &
             "parent type");
      end if;
   end TC_Check;

   procedure TC_Dispatch (N       : in Null_Tagged'Class;
                          TC_Type : in TC_N_Type_ID) is
   begin
      TC_Check (N, TC_Type); -- dispatched call
   end TC_Dispatch;

end C431001_0;
