# $NetBSD: options.mk,v 1.1.1.1 2010/08/08 09:25:16 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.input-pad
PKG_SUPPORTED_OPTIONS=	eek python xtest
PKG_SUGGESTED_OPTIONS=	eek python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	eek python xtest

#
# Draw keyboard using libeek
#
.if !empty(PKG_OPTIONS:Meek)
.include "../../wip/eekboard/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-eek
PLIST.eek=		yes
.endif

#
# Enable Python wrapper
#
.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python=yes
PLIST.python=		yes
.else
CONFIGURE_ARGS+=	--enable-python=no
.endif

#
# Send keyboard event with xtest
#
.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xtest=yes
PLIST.xtest=		yes
.endif
