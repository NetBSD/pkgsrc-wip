

with B431004_C;
package B431004_D is
    type Der4 (Which : Boolean) is new B431004_C.Der3 with record
        case Which is
            when True =>
               T : Character := 'T';
            when False =>
               F : Character := 'F';
        end case;
    end record;
end B431004_D;
