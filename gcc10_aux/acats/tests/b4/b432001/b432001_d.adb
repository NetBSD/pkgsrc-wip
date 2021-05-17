

package body B432001_D is
    function New_One return Der5 is
    begin
        return (A => 1, C => 'A', B => True, E => 'F');
    end New_One;

    function New_One return Der7 is
        On : Der7;
    begin
        return On;
    end New_One;

    function New_One return Der8 is
    begin
        return (A => 1, C => 'A', B => True);
    end New_One;
end B432001_D;
