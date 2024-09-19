# $NetBSD: options.mk,v 1.1 2013/02/24 13:41:22 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libopensync-dev
PKG_SUPPORTED_OPTIONS=	python tests
PKG_SUGGESTED_OPTIONS+=	tests # XXX python doesn't work yet

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
.include "../../devel/swig/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	SWIG_DIR:PATH=${BUILDLINK_PREFIX.swig}/share/swig/1.3
CMAKE_CONFIGURE_ARGS+=	SWIG_EXECUTABLE=${BUILDLINK_PREFIX.swig}/bin/swig
.endif

.if !empty(PKG_OPTIONS:Mtests)
.include "../../devel/check/buildlink3.mk"
.endif
