

package body B432001_C is
    function New_One return Der3 is
    begin
        return (A => 1, C => 'A', B => False, D => True);
    end New_One;

    function New_One return Der4 is
    begin
        return (A => 1, C => 'A', B => True);
    end New_One;

    function New_One return Der6 is
    begin
        return (A => 1, C => 'A', B => True, D => False);
    end New_One;
end B432001_C;
