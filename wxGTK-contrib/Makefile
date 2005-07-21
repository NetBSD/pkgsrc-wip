# $NetBSD: Makefile,v 1.5 2005/07/21 16:34:08 thomasklausner Exp $
# $Id: Makefile,v 1.5 2005/07/21 16:34:08 thomasklausner Exp $
#

DISTNAME=		wxGTK-2.4.2
PKGNAME=		${DISTNAME:S/wxGTK/wxGTK-contrib/}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wxwindows/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.wxwindows.org/
COMMENT=		wxWindows GUI library 3rd party contributions

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS=		gmake
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-libjpeg=sys
CONFIGURE_ARGS+=	--with-zlib=sys
CONFIGURE_ARGS+=	--with-libpng=sys
CONFIGURE_ARGS+=	--with-libtiff=sys

CPPFLAGS+=		-Dunix=1	# src/common/unzip.c needs this

DOCDIR=			${PREFIX}/share/doc/wx/gtk

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUBST+=		GTKVER=
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gtk2
PLIST_SUBST+=		GTKVER=2
.include "../../x11/gtk2/buildlink3.mk"
.endif

MAKE_ENV+=		INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=		LIBTOOL=${PREFIX}/bin/libtool

do-build:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS}

do-install:
	cd ${WRKSRC}/contrib/src && ${SETENV} ${MAKE_ENV} ${GMAKE} install ${MAKE_FLAGS} 

.include "../../x11/wxGTK/buildlink3.mk"

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
