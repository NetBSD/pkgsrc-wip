$NetBSD$

https://github.com/rust-lang/rust/issues/108426

It reverts:
https://github.com/rust-lang/rust/commit/97d8a9bdd3b364406577d7368f5c5203a0f9740a
https://github.com/rust-lang/rust/commit/53e4b9dd74c29cc9308b8d0f10facac70bb101a7

diff --git a/compiler/rustc_abi/src/layout.rs b/compiler/rustc_abi/src/layout.rs
index 9c2cf58efed..ff8ee7fe259 100644
--- compiler/rustc_codegen_ssa/src/mir/place.rs.orig
+++ compiler/rustc_codegen_ssa/src/mir/place.rs
@@ -309,14 +309,14 @@
                 // In the algorithm above, we can change
                 // cast(relative_tag) + niche_variants.start()
                 // into
-                // cast(tag + (niche_variants.start() - niche_start))
+                // cast(tag) + (niche_variants.start() - niche_start)
                 // if either the casted type is no larger than the original
                 // type, or if the niche values are contiguous (in either the
                 // signed or unsigned sense).
-                let can_incr = cast_smaller || niches_ule || niches_sle;
+                let can_incr_after_cast = cast_smaller || niches_ule || niches_sle;
 
                 let data_for_boundary_niche = || -> Option<(IntPredicate, u128)> {
-                    if !can_incr {
+                    if !can_incr_after_cast {
                         None
                     } else if niche_start == low_unsigned {
                         Some((IntPredicate::IntULE, niche_end))
@@ -353,33 +353,24 @@
                     // The algorithm is now this:
                     // is_niche = tag <= niche_end
                     // discr = if is_niche {
-                    //     cast(tag + (niche_variants.start() - niche_start))
+                    //     cast(tag) + (niche_variants.start() - niche_start)
                     // } else {
                     //     untagged_variant
                     // }
                     // (the first line may instead be tag >= niche_start,
                     // and may be a signed or unsigned comparison)
-                    // The arithmetic must be done before the cast, so we can
-                    // have the correct wrapping behavior. See issue #104519 for
-                    // the consequences of getting this wrong.
                     let is_niche =
                         bx.icmp(predicate, tag, bx.cx().const_uint_big(tag_llty, constant));
-                    let delta = (niche_variants.start().as_u32() as u128).wrapping_sub(niche_start);
-                    let incr_tag = if delta == 0 {
-                        tag
-                    } else {
-                        bx.add(tag, bx.cx().const_uint_big(tag_llty, delta))
-                    };
-
                     let cast_tag = if cast_smaller {
-                        bx.intcast(incr_tag, cast_to, false)
+                        bx.intcast(tag, cast_to, false)
                     } else if niches_ule {
-                        bx.zext(incr_tag, cast_to)
+                        bx.zext(tag, cast_to)
                     } else {
-                        bx.sext(incr_tag, cast_to)
+                        bx.sext(tag, cast_to)
                     };
 
-                    (is_niche, cast_tag, 0)
+                    let delta = (niche_variants.start().as_u32() as u128).wrapping_sub(niche_start);
+                    (is_niche, cast_tag, delta)
                 } else {
                     // The special cases don't apply, so we'll have to go with
                     // the general algorithm.
