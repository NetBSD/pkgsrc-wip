$NetBSD$

Fix round-robin/weighted routing bias when failover is enabled. The router
was being asked to select a provider twice per request (once during provider
resolution, once inside the failover loop), so the strategy counter advanced
twice and traffic was skewed (with 2 targets, always the second). Add
ExecuteWithFirst to reuse the already-resolved provider for the first failover
attempt and only re-select from the router on subsequent attempts.

--- internal/routing/failover.go.orig	2026-08-25 14:26:25.000000000 +0100
+++ internal/routing/failover.go	2026-08-28 19:55:56.351603083 +0100
@@ -89,13 +89,60 @@
 	return false
 }
 
-// Execute runs the failover loop, trying providers until one succeeds or all fail.
-func (f *Failover) Execute(ctx context.Context, model string, call FailoverCallFunc) (*FailoverResult, error) {
+// ExecuteWithFirst runs the failover loop but starts with a pre-resolved
+// provider instead of re-selecting via the router. This avoids consuming the
+// routing strategy's selection twice per request (once in resolveProvider,
+// once in Execute), which would bias round-robin and weighted strategies
+// toward a fixed target. Subsequent attempts re-select from the router,
+// excluding providers already tried.
+func (f *Failover) ExecuteWithFirst(ctx context.Context, model string, firstProvider string, firstOverride string, call FailoverCallFunc) (*FailoverResult, error) {
 	excluded := make(map[string]bool)
 	var lastErr error
-	var originalProvider string
+	originalProvider := firstProvider
 
 	for attempt := 1; attempt <= f.cfg.MaxAttempts; attempt++ {
+		if attempt == 1 && firstProvider != "" {
+			// Use the pre-resolved provider without touching the router.
+			result := &RoutingResult{
+				Target: RoutingTarget{
+					ProviderID:    firstProvider,
+					ModelOverride: firstOverride,
+					Healthy:       true,
+				},
+				StrategyName: f.router.Strategy(),
+			}
+
+			// Check circuit breaker before calling.
+			if f.cbReg.IsEnabled() {
+				cb := f.cbReg.Get(firstProvider)
+				if !cb.Allow() {
+					excluded[firstProvider] = true
+					continue
+				}
+			}
+
+			callErr := f.doCalls(ctx, call, result, attempt)
+			if callErr != nil {
+				lastErr = callErr
+				excluded[firstProvider] = true
+				if !f.ShouldFailover(callErr) {
+					return nil, callErr
+				}
+				if ctx.Err() != nil {
+					return nil, lastErr
+				}
+				continue
+			}
+			return &FailoverResult{
+				ProviderID:       firstProvider,
+				ModelOverride:    firstOverride,
+				Attempts:         attempt,
+				OriginalProvider: originalProvider,
+				FallbackUsed:     false,
+				StrategyName:     result.StrategyName,
+			}, nil
+		}
+
 		// Select a target, excluding already-tried providers.
 		var result *RoutingResult
 		var err error
@@ -124,37 +171,108 @@
 			}
 		}
 
-		// Create per-attempt timeout if configured so later attempts get full time.
-		attemptCtx := ctx
-		var attemptCancel context.CancelFunc
-		if f.cfg.PerAttemptTimeout > 0 {
-			attemptCtx, attemptCancel = context.WithTimeout(ctx, f.cfg.PerAttemptTimeout)
+		callErr := f.doCalls(ctx, call, result, attempt)
+		if callErr == nil {
+			return &FailoverResult{
+				ProviderID:       result.Target.ProviderID,
+				ModelOverride:    result.Target.ModelOverride,
+				Attempts:         attempt,
+				OriginalProvider: originalProvider,
+				FallbackUsed:     attempt > 1,
+				StrategyName:     result.StrategyName,
+			}, nil
 		}
 
-		// Call the provider (with retry if configured).
-		var callErr error
-		if f.retryer.IsEnabled() {
-			_, callErr = f.retryer.Execute(attemptCtx, func() error {
-				return call(attemptCtx, result.Target.ProviderID, result.Target.ModelOverride)
-			})
+		lastErr = callErr
+		excluded[result.Target.ProviderID] = true
+
+		// Check if we should failover.
+		if !f.ShouldFailover(callErr) {
+			return nil, callErr
+		}
+
+		// Check context cancellation.
+		if ctx.Err() != nil {
+			return nil, lastErr
+		}
+	}
+
+	return nil, lastErr
+}
+
+// doCalls invokes the provider call for a failover attempt, with retry if configured.
+// Returns the call error, or nil on success.
+func (f *Failover) doCalls(ctx context.Context, call FailoverCallFunc, result *RoutingResult, attempt int) error {
+	// Create per-attempt timeout if configured so later attempts get full time.
+	attemptCtx := ctx
+	var attemptCancel context.CancelFunc
+	if f.cfg.PerAttemptTimeout > 0 {
+		attemptCtx, attemptCancel = context.WithTimeout(ctx, f.cfg.PerAttemptTimeout)
+	}
+
+	// Call the provider (with retry if configured).
+	var callErr error
+	if f.retryer.IsEnabled() {
+		_, callErr = f.retryer.Execute(attemptCtx, func() error {
+			return call(attemptCtx, result.Target.ProviderID, result.Target.ModelOverride)
+		})
+	} else {
+		callErr = call(attemptCtx, result.Target.ProviderID, result.Target.ModelOverride)
+	}
+
+	if attemptCancel != nil {
+		attemptCancel()
+	}
+
+	// Record result in circuit breaker.
+	if f.cbReg.IsEnabled() {
+		cb := f.cbReg.Get(result.Target.ProviderID)
+		if callErr == nil {
+			cb.RecordSuccess()
 		} else {
-			callErr = call(attemptCtx, result.Target.ProviderID, result.Target.ModelOverride)
+			cb.RecordFailure(callErr)
 		}
+	}
 
-		if attemptCancel != nil {
-			attemptCancel()
+	return callErr
+}
+
+// Execute runs the failover loop, trying providers until one succeeds or all fail.
+func (f *Failover) Execute(ctx context.Context, model string, call FailoverCallFunc) (*FailoverResult, error) {
+	excluded := make(map[string]bool)
+	var lastErr error
+	var originalProvider string
+
+	for attempt := 1; attempt <= f.cfg.MaxAttempts; attempt++ {
+		// Select a target, excluding already-tried providers.
+		var result *RoutingResult
+		var err error
+		if len(excluded) == 0 {
+			result, err = f.router.Select(model)
+		} else {
+			result, err = f.router.SelectExcluding(model, excluded)
 		}
+		if err != nil {
+			if lastErr != nil {
+				return nil, lastErr // Return the actual provider error, not "no targets"
+			}
+			return nil, err
+		}
 
-		// Record result in circuit breaker.
+		if originalProvider == "" {
+			originalProvider = result.Target.ProviderID
+		}
+
+		// Check circuit breaker before calling.
 		if f.cbReg.IsEnabled() {
 			cb := f.cbReg.Get(result.Target.ProviderID)
-			if callErr == nil {
-				cb.RecordSuccess()
-			} else {
-				cb.RecordFailure(callErr)
+			if !cb.Allow() {
+				excluded[result.Target.ProviderID] = true
+				continue
 			}
 		}
 
+		callErr := f.doCalls(ctx, call, result, attempt)
 		if callErr == nil {
 			return &FailoverResult{
 				ProviderID:       result.Target.ProviderID,
