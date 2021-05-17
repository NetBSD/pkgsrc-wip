                               -- Grandchild Package body Message.Text.Encoded
 
     --=================================================================--

with CA110050_0.CA110050_1.CA110050_2; 
with Report;

procedure CA110051 is

   package Message_Package renames CA110050_0.CA110050_1;
   package Code_Package    renames CA110050_0.CA110050_1.CA110050_2; 

   Message_String : constant String := "One if by land, two if by sea";

   Message_Text   : Message_Package.Text_Type (Message_String'Length) := 
     (Max_Length => Message_String'Length,
      Length     => Message_String'Length,
      Text_Field => Message_String);

   Message : Message_Package.Text_Message_Type := 
     (Number => CA110050_0.Next_Available_Message,
      Text   => Message_Text);

   Confirmation_Message : Code_Package.Coded_Message;
   Verification_OK      : Boolean := False;
   Transmission_OK      : Boolean := False;

begin

-- This test simulates the use of child library unit packages to implement
-- a message encoding and transmission scheme.  The full capability of the
-- encoding and transmission mechanisms are not developed here, but the 
-- intent is to demonstrate that a grandchild library unit package with a
-- private part will provide the framework for this type of processing.

   Report.Test ("CA110051", "Check that entities and operations declared "  &
                            "in a package can be used in the private part " & 
                            "of a child of a child of the package");

                            -- The following code demonstrates the use
                            -- of functionality contained in a grandchild
                            -- library unit.  The grandchild unit made use
                            -- of components declared in the ancestor
                            -- packages.
   
   Code_Package.Send                            -- Message object declared
     (Message => Code_Package.Encode (Message), -- above in "encoded" by a
      Confirm => Confirmation_Message,          -- call to grandchild pkg
      Status  => Transmission_OK);              -- function call, reseting
                                                -- fields and returning a
                                                -- coded message to the
                                                -- parameter.  The confirm
                                                -- parameter receives an
                                                -- encoded message value
                                                -- from proc Send, which is 
                                                -- "decoded"/verified below.

   if not Code_Package.Test_Connection then
      Report.Failed ("Bad initialization");
   end if;

   Verification_OK := Code_Package.Decode (Confirmation_Message);

   if not (Transmission_OK and Verification_OK) then
      Report.Failed ("Message transmission failure");
   end if;

   Report.Result;

end CA110051;
