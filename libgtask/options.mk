# $NetBSD: options.mk,v 1.1.1.1 2009/05/31 16:40:46 jihbed Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtask

PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/extension.mk"
PYTHON_VERSIONS_ACCEPTED=	26 25 24 23 22
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
.  include "../../devel/py-gobject/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
