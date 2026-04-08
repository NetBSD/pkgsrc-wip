# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.rust
PKG_SUPPORTED_OPTIONS+=	rust-cargo-static rust-docs

.include "../../mk/bsd.fast.prefs.mk"

# The bundled LLVM is the supported choice; the external LLVM option is also
# available.
PKG_SUPPORTED_OPTIONS+=		rust-internal-llvm
.if !empty(HAVE_LLVM)
PKG_SUGGESTED_OPTIONS+=		rust-internal-llvm
.endif

PKG_OPTIONS_LEGACY_OPTS+=	rust-llvm:rust-internal-llvm

.include "../../mk/bsd.options.mk"

# Use the internal copy of LLVM or the external one?
.if empty(PKG_OPTIONS:Mrust-internal-llvm)
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-llvm-link-shared
CONFIGURE_ARGS+=	--llvm-libunwind=system
CONFIGURE_ARGS+=	--llvm-root=${BUILDLINK_PREFIX.llvm}
# Also turn off build of the internal LLD, as the external LLVM
# may be older (e.g., 18) than the internal LLD (now 19.x), ref.
# https://github.com/rust-lang/rust/issues/131291
CONFIGURE_ARGS+=	--set rust.lld=false
.endif

# Link cargo statically against "native" libraries
# (openssl and curl specifically).
.if !empty(PKG_OPTIONS:Mrust-cargo-static)
CONFIGURE_ARGS+=	--enable-cargo-native-static
.else
BUILDLINK_API_DEPENDS.nghttp2+= nghttp2>=1.41.0
BUILDLINK_API_DEPENDS.curl+= 	curl>=7.67.0
.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif

# Install documentation.
.if !empty(PKG_OPTIONS:Mrust-docs)
CONFIGURE_ARGS+=	--enable-docs
.else
CONFIGURE_ARGS+=	--disable-docs
.endif
