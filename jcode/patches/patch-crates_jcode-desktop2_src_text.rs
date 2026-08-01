$NetBSD$

Record why desktop text layout finds no fonts outside Linux and FreeBSD.

Parley resolves system fonts through fontique, whose fontconfig backend is
gated on Linux and FreeBSD. Every other unix silently gets a stub returning
None, so no font loads and text neither shapes nor wraps. Fontconfig itself
works here, so this is a gap in the dependency rather than a missing-fonts
problem on the host, and the fix belongs upstream in fontique.

--- crates/jcode-desktop2/src/text.rs.orig
+++ crates/jcode-desktop2/src/text.rs
@@ -1,4 +1,18 @@
 //! Text layout via Parley, rendered as Vello glyph runs.
+//!
+//! # Platform note
+//!
+//! Parley resolves system fonts through `fontique`, whose fontconfig backend is
+//! gated on `target_os = "linux"` or `"freebsd"` (see `fontique/src/backend/
+//! mod.rs`). Every other unix, NetBSD and OpenBSD included, silently falls back
+//! to a stub `SystemFonts` whose `family()` and `fallback()` always return
+//! `None`. Fontconfig itself works fine there, so this is a gap in the
+//! dependency rather than a missing-fonts problem on the host.
+//!
+//! The visible symptom is that no font ever loads, so text neither shapes nor
+//! wraps and the layout tests in `input.rs` fail with "test text did not wrap".
+//! Fixing it means teaching `fontique` about those targets upstream; until
+//! then, expect these tests to fail on non-Linux/FreeBSD unixes.
 
 use parley::{
     Alignment, FontContext, GlyphRun, Layout, LayoutContext, PositionedLayoutItem, StyleProperty,
