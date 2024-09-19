# $NetBSD: options.mk,v 1.2 2015/04/13 23:22:01 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghmm
PKG_SUPPORTED_OPTIONS=	gsl atlas  python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgsl)
CONFIGURE_ARGS+=	--enable-gsl
.include "../../math/gsl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Matlas)
CONFIGURE_ARGS+=	--enable-atlas
#DEPENDS+=		atlas>=3.11.11:../../wip/atlas
.else
CONFIGURE_ENV+=		ac_cv_prog_MAGICK_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_ACCEPTED= 27
.include "../../lang/python/extension.mk"
.include "../../devel/swig/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-python
.endif
