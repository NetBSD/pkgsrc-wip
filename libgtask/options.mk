# $NetBSD: options.mk,v 1.2 2009/09/09 11:18:58 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtask

PKG_SUPPORTED_OPTIONS=	python
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

###
### Enable python support
###
.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/extension.mk"
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
.  include "../../devel/py-gobject/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
