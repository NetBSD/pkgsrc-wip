# $NetBSD: options.mk,v 1.7 2015/12/05 21:25:51 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lhapdf
PKG_SUPPORTED_OPTIONS=	lhaglue python
PKG_SUGGESTED_OPTIONS+=	lhaglue python
PLIST_VARS+=		lhaglue python

.include "../../mk/bsd.options.mk"

###
### Enable lhaglue support
###
.if !empty(PKG_OPTIONS:Mlhaglue)
.else
CONFIGURE_ARGS+=	--disable-lhaglue
.endif

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=		yes
REPLACE_PYTHON+=  lhapdf.in
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37
.  include "../../lang/python/application.mk"
.  include "../../lang/python/extension.mk"
.  include "../../devel/py-cython/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
