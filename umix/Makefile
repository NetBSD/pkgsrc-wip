# $NetBSD: Makefile,v 1.7 2004/05/04 02:37:44 blef Exp $

DISTNAME=	umix-1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=umix/}

MAINTAINER=	cez@compsoc.man.ac.uk
HOMEPAGE=	http://umix.sourceforge.net/
COMMENT=	Replacement for aumix

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

GNU_CONFIGURE=          yes
USE_GNU_TOOLS+=		make

PLIST_SUBST+=           DISTNAME=${DISTNAME}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/automake.mk"

.if defined(USE_GTK2)
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS += --disable-gtk
PLIST_SUBST+=           GTK="@comment "
.endif

LIBS+=		${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/bsd.pkg.mk"
