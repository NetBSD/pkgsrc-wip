

-- No body for CA11014_3;

     --==================================================================--

-- Declare instances of the generic list packages for the discrete type.
-- The instance of the child must itself be declared as a child of the 
-- instance of the parent.

with CA11014_0;               -- Generic list abstraction.
with CA11014_3;               -- Package containing discrete type declaration.
pragma Elaborate (CA11014_0);
package CA11014_4 is new CA11014_0 (CA11014_3.Points);  -- Points list.
