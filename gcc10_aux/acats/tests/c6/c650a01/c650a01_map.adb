
package body C650A01_Map is
    -- Package defining a map of alerts.

    The_Map : array (Key_Type) of access F650A00.Alert'Class;

    procedure Clear_Map is
    begin
        The_Map := (others => null);
    end Clear_Map;

    procedure Set_Item (Key : in Key_Type; Item : access F650A00.Alert'Class) is
    begin
        The_Map(Key) := Item;
    end Set_Item;

    function Get_Item (Key : in Key_Type) return access F650A00.Alert'Class is
        -- Returns null if no object has been set for Key.
    begin
        return The_Map(Key);
    end Get_Item;

    type PA is access all F650A00.P.Practice_Alert;

    function Get_Practice_Item (Key : in Key_Type)
        return access F650A00.P.Practice_Alert is
        -- Returns null if no object has been set for Key.
        -- This is a bad idea; no objects derived from Practice_Alert can be
        -- returned. We use it to test the objective in question.
    begin
        return PA(The_Map(Key));
    end Get_Practice_Item;

end C650A01_Map;
