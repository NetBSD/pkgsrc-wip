# $NetBSD: options.mk,v 1.5 2018/07/03 05:03:09 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdb
PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=		--with-python=${PYTHONBIN}
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../lang/python/application.mk"
.endif
