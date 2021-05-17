
with C452001_4;
package C452001_5 is

   -- Types to check whether primitive or predefined equality is incorporated
   -- in predefined equality of composite types with components of a private
   -- type.

   type TPTF_Rec is record
       Comp : C452001_4.Tagged_Partial_Tagged_Full;
       Ch   : Character := '0';
   end record;

   type UPTF_Rec is record
       Comp : C452001_4.Untagged_Partial_Tagged_Full;
       Ch   : Character := '0';
   end record;

   type UPURF_Rec is record
       Comp : C452001_4.Untagged_Partial_Untagged_Record_Full;
       Ch   : Character := '0';
   end record;

   type UPUAF_Rec is record
       Comp : C452001_4.Untagged_Partial_Untagged_Array_Full;
       Ch   : Character := '0';
   end record;

end C452001_5;
