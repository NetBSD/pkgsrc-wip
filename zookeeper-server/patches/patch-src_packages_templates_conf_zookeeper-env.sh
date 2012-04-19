$NetBSD: patch-src_packages_templates_conf_zookeeper-env.sh,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $

Default paths.
--- src/packages/templates/conf/zookeeper-env.sh.orig	2012-02-06 10:48:40.000000000 +0000
+++ src/packages/templates/conf/zookeeper-env.sh
@@ -12,5 +12,5 @@
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
-export JAVA_HOME=${JAVA_HOME}
-export ZOO_LOG_DIR=${LOG_DIR}
+export JAVA_HOME=@PKG_JAVA_HOME@
+export ZOO_LOG_DIR=@ZK_LOG@
