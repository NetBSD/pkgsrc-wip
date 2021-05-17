
package BA16002.Pak2 is
    package Nested is
        type Glab is array (Natural range <>) of Gollywog;
    end Nested;
    procedure Inner_Proc;
    function Inner_Func return Boolean;
    package Math is
        PI : constant := 3.14159;
    end Math;
end BA16002.Pak2;
