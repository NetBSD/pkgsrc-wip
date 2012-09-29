# $NetBSD: Makefile,v 1.3 2012/09/29 00:44:37 asau Exp $

DISTNAME=		gtuxnes-0.75
CATEGORIES=		emulators
MASTER_SITES=		http://www12.tucows.com/linux/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scottweber.com/projects/gtk/gtuxnes/
COMMENT=		Graphical launcher for TuxNES

DEPENDS+=		tuxnes>=0.75:../../emulators/tuxnes

ONLY_FOR_PLATFORM=	*-*-i386

BUILD_TARGET=		${EMPTY}

USE_LIBTOOL=		yes
CPPFLAGS+=		-I${BUILDLINK_PREFIX.glib}/include/glib/glib-1.2 \
			-I${BUILDLINK_PREFIX.glib}/lib/glib/include \
			-I${BUILDLINK_PREFIX.gtk}/include/gtk-1.2
INSTALLATION_DIRS=	bin share share/doc/gtuxnes

do-build:
	cd ${WRKSRC} && && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtuxnes ${DESTDIR}${PREFIX}/bin/gtuxnes
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gtuxnes
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gtuxnes

.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
