# $NetBSD: Makefile,v 1.2 2004/03/26 14:32:19 marc Exp $

.include "Makefile.common"

COMMENT=	GTK-based implementation of the wxWidgets GUI library

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUBST+=		GTKVER=
PLIST_SUBST+=		UNICODE=
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gtk2 --enable-unicode
PLIST_SUBST+=		GTKVER=2
PLIST_SUBST+=		UNICODE=u
.include "../../x11/gtk2/buildlink3.mk"
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
