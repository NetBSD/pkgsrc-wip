https://github.com/rust-lang/rust/issues/108426

It reverts:
https://github.com/rust-lang/rust/commit/97d8a9bdd3b364406577d7368f5c5203a0f9740a
https://github.com/rust-lang/rust/commit/53e4b9dd74c29cc9308b8d0f10facac70bb101a7

diff --git a/compiler/rustc_abi/src/layout.rs b/compiler/rustc_abi/src/layout.rs
index 9c2cf58efed..ff8ee7fe259 100644
--- compiler/rustc_abi/src/layout.rs.orig
+++ compiler/rustc_abi/src/layout.rs
@@ -112,21 +112,14 @@ fn univariant<'a, V: Idx, F: Deref<Target = &'a LayoutS<V>> + Debug>(
                             // especially with only one or two non-ZST fields.
                             // Then place largest alignments first, largest niches within an alignment group last
                             let f = &fields[x as usize];
-                            let niche_size = f.largest_niche.map_or(0, |n| n.available(dl));
-                            (!f.is_zst(), cmp::Reverse(effective_field_align(f)), niche_size)
+                            (!f.is_zst(), cmp::Reverse(effective_field_align(f)))
                         });
                     }
 
                     StructKind::Prefixed(..) => {
                         // Sort in ascending alignment so that the layout stays optimal
                         // regardless of the prefix.
-                        // And put the largest niche in an alignment group at the end
-                        // so it can be used as discriminant in jagged enums
-                        optimizing.sort_by_key(|&x| {
-                            let f = &fields[x as usize];
-                            let niche_size = f.largest_niche.map_or(0, |n| n.available(dl));
-                            (effective_field_align(f), niche_size)
-                        });
+                        optimizing.sort_by_key(|&x| effective_field_align(&fields[x as usize]));
                     }
                 }
 
