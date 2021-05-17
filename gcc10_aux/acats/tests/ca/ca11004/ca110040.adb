
     --=================================================================--

package body CA110040 is                     -- Package body Computer_System.

   function Next_Available_ID return ID_Type is
   begin
      Total_Accounts := Total_Accounts + 1;
      return (ID_Type(Total_Accounts));
   end Next_Available_ID;

end CA110040;                                -- Package body Computer_System.
