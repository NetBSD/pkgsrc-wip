
-- See file B7310013 for the package body B7310016_1.Places.P.Q

----------------------------------------------------------------
-- Check visibility in private packages and their children.

private package B7310016_1.Mother is
    type Root is tagged null record;
    function Op1(X: Root) return String;
private
    function Op2(X: Root) return String;
end B7310016_1.Mother;
