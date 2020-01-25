$NetBSD$

Use contextlib from the standard library.

--- zipline/gens/tradesimulation.py.orig	2018-03-12 17:33:52.000000000 +0000
+++ zipline/gens/tradesimulation.py
@@ -12,7 +12,7 @@
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
-from contextlib2 import ExitStack
+from contextlib import ExitStack
 from copy import copy
 from logbook import Logger, Processor
 from zipline.finance.order import ORDER_STATUS
