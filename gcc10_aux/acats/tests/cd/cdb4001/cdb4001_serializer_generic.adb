

package body CDB4001_Serializer_Generic is
    protected body Protected_State is
        function Read (Op : access procedure (Current_State : State))
           return Null_Record is
        begin
            Op.all (Current_State);
            return (null record);
        end Read;

        procedure Update (Op : access procedure
                                        (Current_State : in out State)) is
        begin
            Op.all (Current_State);
        end Update;
    end Protected_State;
end CDB4001_Serializer_Generic;
