# $NetBSD: options.mk,v 1.1 2014/06/21 04:01:01 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35
.include "../../lang/python/application.mk"
.endif
