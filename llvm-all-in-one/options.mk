# $NetBSD: options.mk,v 1.3 2017/05/09 12:23:42 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.llvm
PKG_SUPPORTED_OPTIONS+=	terminfo

# Terminfo is used for colour output, only enable it by default if terminfo
# is builtin to avoid unnecessary dependencies which could cause bootstrap
# issues.
CHECK_BUILTIN.terminfo:=	yes
.include "../../mk/terminfo.builtin.mk"
CHECK_BUILTIN.terminfo:=	no
.if !empty(USE_BUILTIN.terminfo:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=		terminfo
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mterminfo)
.include "../../mk/terminfo.buildlink3.mk"
.else
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
.endif
