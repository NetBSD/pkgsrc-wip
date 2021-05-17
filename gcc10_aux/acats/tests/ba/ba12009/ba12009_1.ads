
limited with BA12009_0;          -- OK.
package BA12009_1 is
    type Another_Item is tagged record
        Ptr : access BA12009_0.My_Item;
    end record;
    procedure Process (P : access BA12009_0.My_Item);
end BA12009_1;
