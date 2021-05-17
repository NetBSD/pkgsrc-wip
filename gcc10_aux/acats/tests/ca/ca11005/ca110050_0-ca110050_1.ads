
     --=================================================================--

package CA110050_0.CA110050_1 is        -- Child package Messages.Text

   subtype Default_Length is Natural range 0 .. 80;

   type Text_Type (Max_Length : Default_Length := 0) is
      record
         Length      : Default_Length := Max_Length;
         Text_Field  : String (1 .. Max_Length);
      end record;

   type Text_Message_Type is new Message_Type with
      record
         Text : Text_Type;
      end record;

   Null_Text    : Text_Type (0);                     -- Null range for 
                                                     -- Text_Field component.

end CA110050_0.CA110050_1;              -- Child package Messages.Text
--
-- No package body needed for this specification.
