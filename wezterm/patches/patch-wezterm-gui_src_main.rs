$NetBSD$

Remove update checker.

--- wezterm-gui/src/main.rs.orig
+++ wezterm-gui/src/main.rs
@@ -41,7 +41,6 @@ mod shapecache;
 mod stats;
 mod tabbar;
 mod termwindow;
-mod update;
 mod utilsprites;
 
 pub use selection::SelectionMode;
@@ -206,7 +205,6 @@ async fn async_run_with_domain_as_default(
     cmd: Option<CommandBuilder>,
 ) -> anyhow::Result<()> {
     let mux = Mux::get().unwrap();
-    crate::update::load_last_release_info_and_set_banner();
 
     // Allow spawning local commands into new tabs/panes
     let local_domain: Arc<dyn Domain> = Arc::new(LocalDomain::new("local")?);
@@ -539,7 +537,6 @@ fn setup_mux(
                 .unwrap_or(mux::DEFAULT_WORKSPACE),
         ),
     );
-    crate::update::load_last_release_info_and_set_banner();
     update_mux_domains(config)?;
 
     let default_name =