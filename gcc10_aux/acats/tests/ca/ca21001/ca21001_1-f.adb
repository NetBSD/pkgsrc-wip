
separate(CA21001_1)
function F return Integer is

    package F_Sub is
        -- Empty.
    end F_Sub;

    package body F_Sub is separate;
begin
    return 100;
end F;
