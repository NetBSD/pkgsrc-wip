$NetBSD: patch-src_packages_templates_conf_zookeeper-env.sh,v 1.2 2014/05/14 09:51:07 fhajny Exp $

Default paths.
--- src/packages/templates/conf/zookeeper-env.sh.orig	2014-02-20 10:14:10.000000000 +0000
+++ src/packages/templates/conf/zookeeper-env.sh
@@ -12,5 +12,5 @@
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
-export JAVA_HOME=${JAVA_HOME}
-export ZOO_LOG_DIR=${LOG_DIR}
+export JAVA_HOME=@PKG_JAVA_HOME@
+export ZOO_LOG_DIR=@ZK_LOG@
