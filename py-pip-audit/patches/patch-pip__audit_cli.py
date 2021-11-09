$NetBSD$

https://github.com/trailofbits/pip-audit/issues/115

--- pip_audit/cli.py.orig	2021-11-09 16:11:51.000000000 +0000
+++ pip_audit/cli.py
@@ -13,7 +13,12 @@ from typing import List, Optional
 
 from pip_audit import __version__
 from pip_audit.audit import AuditOptions, Auditor
-from pip_audit.dependency_source import PipSource, RequirementSource, ResolveLibResolver
+from pip_audit.dependency_source import (
+    DependencySource,
+    PipSource,
+    RequirementSource,
+    ResolveLibResolver,
+)
 from pip_audit.format import ColumnsFormat, JsonFormat, VulnerabilityFormat
 from pip_audit.service import OsvService, PyPIService, VulnerabilityService
 from pip_audit.state import AuditSpinner
@@ -105,7 +110,7 @@ class ProgressSpinnerChoice(str, enum.En
         return self.value
 
 
-def audit():
+def audit() -> None:
     """
     The primary entrypoint for `pip-audit`.
     """
@@ -182,6 +187,7 @@ def audit():
     with ExitStack() as stack:
         state = stack.enter_context(AuditSpinner()) if args.progress_spinner else None
 
+        source: DependencySource
         if args.requirements is not None:
             req_files: List[Path] = [Path(req.name) for req in args.requirements]
             source = RequirementSource(req_files, ResolveLibResolver(state), state)
@@ -195,7 +201,7 @@ def audit():
         vuln_count = 0
         for (spec, vulns) in auditor.audit(source):
             if state is not None:
-                state.update_state(f"Auditing {spec.package} ({spec.version})")
+                state.update_state(f"Auditing {spec.name} ({spec.version})")
             result[spec] = vulns
             if len(vulns) > 0:
                 pkg_count += 1
