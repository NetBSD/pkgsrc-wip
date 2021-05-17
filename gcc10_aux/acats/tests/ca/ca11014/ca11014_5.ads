
with CA11014_4;               -- Points list.
with CA11014_1;               -- Generic list operation.
pragma Elaborate (CA11014_1);
package CA11014_5 is new CA11014_1 (CA11014_4);         -- Scores list.
