# $NetBSD: Makefile,v 1.2 2003/04/13 14:39:43 cjep Exp $
#

DISTNAME=	umix-0.9.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=umix/}

MAINTAINER=	cez@compsoc.man.ac.uk
HOMEPAGE=	http://umix.sourceforge.net/
COMMENT=	Replacement for aumix

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES

AUTOMAKE_REQD=          1.4
GNU_CONFIGURE=          yes
USE_GMAKE=              yes
USE_LIBTOOL=            yes
#LIBTOOL_OVERRIDE=      ${WRKSRC}/libtool

PLIST_SUBST+=           DISTNAME=${DISTNAME}

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/automake.mk"

.if defined(USE_GTK2)
.include "../../x11/gtk2/buildlink2.mk"
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
