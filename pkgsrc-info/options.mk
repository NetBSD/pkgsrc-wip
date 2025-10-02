# $NetBSD: $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pkgsrc-info
PKG_SUPPORTED_OPTIONS+=		java rust
PKG_SUGGESTED_OPTIONS+=		java rust

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=	build
.include "../../mk/java-vm.mk"
.endif

.if !empty(PKG_OPTIONS:Mrust)
.include "../../lang/rust/rust.mk"
.endif
