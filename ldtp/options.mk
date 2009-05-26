# $NetBSD: options.mk,v 1.2 2009/05/26 09:40:20 jihbed Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR =	PKG_OPTIONS.ldtp
PKG_SUPPORTED_OPTIONS=	pythonmodules localization
PKG_SUGGESTED_OPTIONS=	pythonmodules

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpythonmodules)
CONFIGURE_ARGS+=	--with-pythonmodules
. include "../../lang/python/extension.mk"
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}
.  include "../../devel/libglade/buildlink3.mk"
.  include "../../devel/py-at-spi/buildlink3.mk"
.  include "../../devel/py-gobject/buildlink3.mk"
.  include "../../net/py-ORBit/buildlink3.mk"
.  include "../../x11/py-gnome2/buildlink3.mk"
.  include "../../x11/py-gnome2-desktop/buildlink3.mk"
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pythonmodules
.endif

.if !empty(PKG_OPTIONS:Mlocalization)
CONFIGURE_ARGS+=	--enable-localization
DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
.else
CONFIGURE_ARGS+=	--enable-localization=no
.endif
