# $NetBSD: Makefile,v 1.14 2005/08/11 10:08:23 absd Exp $

DISTNAME=	umix-1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=umix/}

MAINTAINER=	cez@compsoc.man.ac.uk
HOMEPAGE=	http://umix.sourceforge.net/
COMMENT=	Replacement for aumix

USE_LIBTOOL=	YES

GNU_CONFIGURE=          yes
USE_TOOLS+=		gmake automake pkg-config

PLIST_SUBST+=           DISTNAME=${DISTNAME}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.if defined(USE_GTK2)
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS += --disable-gtk
PLIST_SUBST+=           GTK="@comment "
.endif

LIBS+=		${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && automake --add-missing
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
