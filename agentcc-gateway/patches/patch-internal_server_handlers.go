$NetBSD$

Wire ExecuteWithFirst into the non-stream and streaming failover paths so the
provider resolved for the request is used for the first failover attempt
instead of re-selecting via the router (which consumed the round-robin
counter twice per request and biased traffic toward one target).

--- internal/server/handlers.go.orig
+++ internal/server/handlers.go
@@ -1379,7 +1379,7 @@
 	effectiveFailover := h.effectiveFailover(orgCfg)
 
 	if effectiveFailover != nil && effectiveFailover.IsEnabled() && h.registry.Router() != nil && h.registry.Router().HasTargets(rc.Model) {
-		h.handleNonStreamWithFailover(ctx, w, rc, effectiveFailover, orgCfg)
+		h.handleNonStreamWithFailover(ctx, w, rc, effectiveFailover, provider, orgCfg)
 		return
 	}
 
@@ -1447,7 +1447,7 @@
 	json.NewEncoder(w).Encode(rc.Response)
 }
 
-func (h *Handlers) handleNonStreamWithFailover(ctx context.Context, w http.ResponseWriter, rc *models.RequestContext, fo *routing.Failover, orgCfg *tenant.OrgConfig) {
+func (h *Handlers) handleNonStreamWithFailover(ctx context.Context, w http.ResponseWriter, rc *models.RequestContext, fo *routing.Failover, resolvedProvider providers.Provider, orgCfg *tenant.OrgConfig) {
 	originalModel := rc.Request.Model
 	orgID := rc.Metadata["org_id"]
 	var servingProvider providers.Provider
@@ -1455,7 +1455,16 @@
 	// Wrap the failover loop inside engine.Process so pre-plugins run once,
 	// then the failover retries only the provider call, then post-plugins run once.
 	providerCall := func(ctx context.Context, rc *models.RequestContext) error {
-		foResult, err := fo.Execute(ctx, rc.Model, func(ctx context.Context, providerID string, modelOverride string) error {
+		// Use the provider already resolved for this request as the first
+		// attempt, so the routing strategy is not consumed twice per request.
+		// rc.Request.Model is already the (possibly overridden) model the
+		// resolved provider expects.
+		var firstProvider, firstOverride string
+		if resolvedProvider != nil {
+			firstProvider = resolvedProvider.ID()
+			firstOverride = rc.Request.Model
+		}
+		foResult, err := fo.ExecuteWithFirst(ctx, rc.Model, firstProvider, firstOverride, func(ctx context.Context, providerID string, modelOverride string) error {
 			p, ok := h.registry.GetProvider(providerID)
 			if !ok {
 				return fmt.Errorf("provider %q not found", providerID)
@@ -1642,7 +1651,12 @@
 		}
 
 		if effectiveFailover != nil && effectiveFailover.IsEnabled() && h.registry.Router() != nil && h.registry.Router().HasTargets(rc.Model) {
-			result, err := effectiveFailover.Execute(ctx, rc.Model, func(callCtx context.Context, providerID string, modelOverride string) error {
+			var firstProvider, firstOverride string
+			if provider != nil {
+				firstProvider = provider.ID()
+				firstOverride = rc.Request.Model
+			}
+			result, err := effectiveFailover.ExecuteWithFirst(ctx, rc.Model, firstProvider, firstOverride, func(callCtx context.Context, providerID string, modelOverride string) error {
 				p, ok := h.registry.GetProvider(providerID)
 				if !ok {
 					return models.ErrUpstreamProvider(http.StatusBadGateway, fmt.Sprintf("provider %q not found", providerID))
