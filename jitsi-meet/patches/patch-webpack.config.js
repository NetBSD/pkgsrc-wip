$NetBSD$

Attempt to work around default hash of md4 in older webpack, because it
is deprecated in non-ancient node.
    
Not reported upstream because surely they have addressed this.

--- webpack.config.js.orig	2025-03-02 15:59:55.022078818 +0000
+++ webpack.config.js
@@ -7,6 +7,10 @@ const process = require('process');
 const webpack = require('webpack');
 const { BundleAnalyzerPlugin } = require('webpack-bundle-analyzer');
 
+const crypto = require("crypto");
+const crypto_orig_createHash = crypto.createHash;
+crypto.createHash = algorithm => crypto_orig_createHash(algorithm == "md4" ? "sha256" : algorithm);
+
 /**
  * The URL of the Jitsi Meet deployment to be proxy to in the context of
  * development with webpack-dev-server.
