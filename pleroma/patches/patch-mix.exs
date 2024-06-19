$NetBSD$

# Don't include erts in the final release
# as this package would depend on lang/erlang explicitly

--- mix.exs.orig	2024-06-19 17:58:00.439960976 +0000
+++ mix.exs
@@ -35,6 +35,7 @@ defmodule Pleroma.Mixfile do
       releases: [
         pleroma: [
           include_executables_for: [:unix],
+          include_erts: false,
           applications: [ex_syslogger: :load, syslog: :load, eldap: :transient],
           steps: [:assemble, &put_otp_version/1, &copy_files/1, &copy_nginx_config/1],
           config_providers: [{Pleroma.Config.ReleaseRuntimeProvider, []}]
