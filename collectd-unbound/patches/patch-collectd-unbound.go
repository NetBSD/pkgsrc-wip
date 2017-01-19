$NetBSD$

Change from requiring unbound be configured with

  statistics-cumulative: no

to instead requiring

  statistics-cumulative: yes

...and we want all the stats to be collected, and some
of those are counters and some are gauges.

--- collectd-unbound.go.orig	2015-03-21 07:56:41.000000000 +0000
+++ collectd-unbound.go
@@ -33,7 +33,8 @@ func unboundStats(interval time.Duration
 	scanner := bufio.NewScanner(buf)
 	for scanner.Scan() {
 		line := scanner.Text()
-		if !strings.HasPrefix(line, "total.") {
+		// Skip per-thread statistics:
+		if strings.HasPrefix(line, "thread") {
 			continue
 		}
 
@@ -43,7 +44,6 @@ func unboundStats(interval time.Duration
 		}
 
 		metric := fields[0]
-		metric = strings.TrimPrefix(metric, "total.")
 		metric = strings.Replace(metric, ".", "_", -1)
 
 		value, err := strconv.ParseFloat(fields[1], 64)
@@ -51,19 +51,28 @@ func unboundStats(interval time.Duration
 			log.Printf("error: unable to parse metric value: %v", err)
 			continue
 		}
+		vartype := "counter"
+		if strings.Contains(fields[1], ".") {
+			vartype = "gauge"
+		}
+		if strings.HasPrefix(metric, "total_requestlist") {
+			vartype = "gauge"
+		}
+		if strings.HasPrefix(metric, "total_recursion") {
+			vartype = "gauge"
+		}
 
 		vl := api.ValueList{
 			Identifier: api.Identifier{
 				Host:         exec.Hostname(),
 				Plugin:       "unbound",
-				Type:         "gauge",
+				Type:         vartype,
 				TypeInstance: metric,
 			},
 			Time:     now,
 			Interval: interval,
 			Values:   []api.Value{api.Gauge(value)},
 		}
-
 		exec.Putval.Write(vl)
 	}
 }
