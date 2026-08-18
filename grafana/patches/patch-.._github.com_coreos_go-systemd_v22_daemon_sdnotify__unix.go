$NetBSD$

--- ../github.com/coreos/go-systemd/v22/daemon/sdnotify_unix.go.orig	2026-08-18 21:53:24.536759376 +0000
+++ ../github.com/coreos/go-systemd/v22/daemon/sdnotify_unix.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build unix
+//go:build unix && !netbsd
 
 package daemon
 
