

     --==================================================================--


with F460A00;
generic
   type Designated_Type is new F460A00.Tagged_Type with private;
   type Target_Type is access constant Designated_Type;
procedure C460A02_2 (P   : access Designated_Type'Class;
                     Res : out    F460A00.TC_Result_Kind);
