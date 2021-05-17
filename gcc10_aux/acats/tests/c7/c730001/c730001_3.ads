

     --==================================================================--


with C730001_0; use C730001_0;
with C730001_1; use C730001_1;
with C730001_2; use C730001_2;

package C730001_3 is

   -- Types extended from the ancestor (Phone) type in the specification.

   type Secure_Phone_Type     is new Phone with private;
   type Auditorium_Phone_Type is new Phone with private;
   -- Inherit versions of Answer from ancestor (Phone).

   function TC_Get_Phone_Status (P : Phone'Class) return Capability_Type;
   function TC_Get_Indicator    (P : Phone'Class) return Indicator_Type;

private

   -- Types extended from descendents of Phone_Type in the private part.

   type Secure_Phone_Type is new Office_Phone with record
      Scrambled_Communication : Boolean := True;
   end record;

   type Auditorium_Phone_Type is new Conference_Room_Phone with record
      Volume_Control : Boolean := True;
   end record;

end C730001_3;
