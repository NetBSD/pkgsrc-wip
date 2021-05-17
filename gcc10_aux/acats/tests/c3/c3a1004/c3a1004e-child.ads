
-- ----------------------------------------------------------------------------

-- Note: No with of C3A1004D (departments); inherits a limited with
-- from the parent.
package C3A1004E.Child is -- Employee operations

    procedure Recruit (D : access C3A1004D.Department'Class;
                       E : in out C3A1004E.Employee'Class);
       -- Recruit E for D.

    procedure Join (D : in out C3A1004D.Department'Class;
                    E : in out C3A1004E.Employee'Class);
       -- E joins D.

    function Image (D : in C3A1004D.Department'Class;
                    E : in C3A1004E.Employee'Class) return String;

end C3A1004E.Child;
