# $NetBSD: Makefile,v 1.1.1.1 2004/03/25 17:12:27 marc Exp $
#

DISTNAME=	wxGTK-2.5.1
CATEGORIES=	x11
MASTER_SITES=	http://biolpc22.york.ac.uk/pub/2.5.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.wxwidgets.org/
COMMENT=	GTK-based implementation of the wxWidgets GUI library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_LANGUAGES=		c c++
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-sdl
CONFIGURE_ARGS+=	--with-expat=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-libtiff=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ENV+= 	CC=cc
CONFIGURE_ENV+= 	CXX=c++

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
