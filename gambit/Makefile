# $NetBSD: Makefile,v 1.1 2013/09/06 23:12:05 jihbed Exp $

DISTNAME=	gambit-13.1.0
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/gambit/gambit13/13.1.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.gambit-project.org/gambit13/index.html#
COMMENT=	Software Tools for Game Theory
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP=	configure
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	share/applications

post-install:
	${INSTALL_DATA} ${WRKSRC}/gambit.desktop \
                ${DESTDIR}${PREFIX}/share/applications/gambit.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
