
package BA16001.Pak2 is
    package Nested is
        type Glab is array (Natural range <>) of Gollywog;
    end Nested;
    procedure Inner_Proc;
    package Math is
        PI : constant := 3.14159;
    end Math;
end BA16001.Pak2;
