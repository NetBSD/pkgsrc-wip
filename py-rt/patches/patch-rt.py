$NetBSD$

Permit to also pass possible `format' field to search().

Merged upstream as part of https://github.com/CZ-NIC/python-rt/pull/17

--- rt.py.orig	2017-12-01 12:25:41.000000000 +0000
+++ rt.py
@@ -392,7 +392,7 @@ class Rt:
         """
         return self.search(Queue=queue, order='-LastUpdated', LastUpdatedBy__notexact=self.default_login, LastUpdated__gt=since)
 
-    def search(self, Queue=None, order=None, raw_query=None, **kwargs):
+    def search(self, Queue=None, order=None, raw_query=None, Format='l', **kwargs):
         """ Search arbitrary needles in given fields and queue.
 
         Example::
@@ -413,6 +413,10 @@ class Rt:
                              kwargs, so use these instead of including them in
                              the raw query. You can refer to the RT query builder.
                              If passing raw_query, all other **kwargs will be ignored.
+        :keyword Format:     Format of the query:
+                               - i: only `id' fields are populated
+                               - s: only `id' and `subject' fields are populated
+                               - l: multi-line format
         :keyword kwargs:     Other arguments possible to set if not passing raw_query:
 
                              Requestors, Subject, Cc, AdminCc, Owner, Status,
@@ -471,7 +475,7 @@ class Rt:
         get_params['query'] = ' AND '.join('(' + part + ')' for part in query)
         if order:
             get_params['orderby'] = order
-        get_params['format'] = 'l'
+        get_params['format'] = Format
 
         msg = self.__request(url, get_params=get_params)
         lines = msg.split('\n')
@@ -481,37 +485,52 @@ class Rt:
             if lines[2].startswith('No matching results.'):
                 return []
 
-        msgs = map(lambda x: x.split('\n'), msg.split('\n--\n'))
-        items = []
-        for msg in msgs:
-            pairs = {}
-            req_matching = [i for i, m in enumerate(msg) if self.RE_PATTERNS['requestors_pattern'].match(m)]
-            req_id = req_matching[0] if req_matching else None
-            if not req_id:
-                raise UnexpectedMessageFormat('Missing line starting with `Requestors:`.')
-            for i in range(req_id):
-                if ': ' in msg[i]:
-                    header, content = msg[i].split(': ', 1)
-                    pairs[header.strip()] = content.strip()
-            requestors = [msg[req_id][12:]]
-            req_id += 1
-            while (req_id < len(msg)) and (msg[req_id][:12] == ' ' * 12):
-                requestors.append(msg[req_id][12:])
+        if Format == 'l':
+            msgs = map(lambda x: x.split('\n'), msg.split('\n--\n'))
+            items = []
+            for msg in msgs:
+                pairs = {}
+                req_matching = [i for i, m in enumerate(msg) if self.RE_PATTERNS['requestors_pattern'].match(m)]
+                req_id = req_matching[0] if req_matching else None
+                if not req_id:
+                    raise UnexpectedMessageFormat('Missing line starting with `Requestors:`.')
+                for i in range(req_id):
+                    if ': ' in msg[i]:
+                        header, content = msg[i].split(': ', 1)
+                        pairs[header.strip()] = content.strip()
+                requestors = [msg[req_id][12:]]
                 req_id += 1
-            pairs['Requestors'] = self.__normalize_list(requestors)
-            for i in range(req_id, len(msg)):
-                if ': ' in msg[i]:
-                    header, content = msg[i].split(': ', 1)
-                    pairs[header.strip()] = content.strip()
-            if pairs:
-                items.append(pairs)
+                while (req_id < len(msg)) and (msg[req_id][:12] == ' ' * 12):
+                    requestors.append(msg[req_id][12:])
+                    req_id += 1
+                pairs['Requestors'] = self.__normalize_list(requestors)
+                for i in range(req_id, len(msg)):
+                    if ': ' in msg[i]:
+                        header, content = msg[i].split(': ', 1)
+                        pairs[header.strip()] = content.strip()
+                if pairs:
+                    items.append(pairs)
+
+                if 'Cc' in pairs:
+                    pairs['Cc'] = self.__normalize_list(pairs['Cc'])
+                if 'AdminCc' in pairs:
+                    pairs['AdminCc'] = self.__normalize_list(pairs['AdminCc'])
+            return items
+        elif Format == 's':
+            items = []
+            msgs = msg.splitlines()[2:]
+            for msg in msgs:
+                ticket_id, subject = msg.split(': ', 1)
+                items.append({ 'id': 'ticket/' + ticket_id, 'Subject': subject })    
+            return items
+        elif Format == 'i':
+            items = []
+            msgs = msg.splitlines()[2:]
+            for msg in msgs:
+                _, ticket_id = msg.split('/', 1)
+                items.append({ 'id': 'ticket/' + ticket_id })    
+            return items
 
-            if 'Cc' in pairs:
-                pairs['Cc'] = self.__normalize_list(pairs['Cc'])
-            if 'AdminCc' in pairs:
-                pairs['AdminCc'] = self.__normalize_list(pairs['AdminCc'])
-
-        return items
 
     def get_ticket(self, ticket_id):
         """ Fetch ticket by its ID.
