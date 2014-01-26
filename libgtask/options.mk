# $NetBSD: options.mk,v 1.4 2014/01/26 15:49:52 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtask

PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2, py-gobject
.  include "../../lang/python/extension.mk"
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
.  include "../../devel/py-gobject/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
