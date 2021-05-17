
with Report;
use Report;
with CA20003_0;
with CA20003_TC;
procedure CA200031 is
    My_Data : CA20003_0.Data;
begin
    Test ("CA20003","Check that a package that is needed only because it is " &
                    "referenced in a limited with clause in included in " &
                    "a partition");

    CA20003_0.Do_It (My_Data);

    if CA20003_TC.TC_Debug_Subsystem = CA20003_TC.INITIAL then
        Failed ("Subsystem referenced by limited with not included");
    elsif CA20003_TC.TC_Debug_Subsystem = CA20003_TC.FIRST_VERSION then
        null; --Comment ("Subsystem referenced by limited with included");
    else
        Failed ("Unusual result from subsystem referenced by limited with");
    end if;

    if CA20003_TC.TC_Test_Subsystem = CA20003_TC.INITIAL then
        Failed ("Test subsystem not executed");
    elsif CA20003_TC.TC_Test_Subsystem = CA20003_TC.FIRST_VERSION then
        null; --Comment ("Test subsystem executed");
    else
        Failed ("Unusual result from test subsystem");
    end if;

    Result;
end CA200031;
