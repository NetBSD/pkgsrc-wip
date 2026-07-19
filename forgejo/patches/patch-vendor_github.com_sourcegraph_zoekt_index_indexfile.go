$NetBSD$

Fix build on NetBSD.
https://github.com/sourcegraph/zoekt/commit/3c8b39b1ef4f8194cb912d7e6581cff9db224aa7

--- vendor/github.com/sourcegraph/zoekt/index/indexfile.go.orig	2026-07-19 08:34:31.770186830 +0000
+++ vendor/github.com/sourcegraph/zoekt/index/indexfile.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build linux || darwin || freebsd
+//go:build linux || darwin || freebsd || netbsd
 
 package index
 
