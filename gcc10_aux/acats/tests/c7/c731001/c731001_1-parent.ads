
private package C731001_1.Parent is

    procedure Call_Main;

    type Root is tagged null record;
    subtype Renames_Root is Root;
    subtype Root_Class is Renames_Root'Class;
    function Make return Root;
    function Op1(X: Root) return String;
    function Call_Op2(X: Root'Class) return String;
private
    function Op2(X: Root) return String;
end C731001_1.Parent;
