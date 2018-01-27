# $NetBSD: Makefile,v 1.10 2012/10/07 17:35:47 asau Exp $

DISTNAME=		viewer-0.7.3
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://www-users.cs.umn.edu/~wburdick/ftp/geowall/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-users.cs.umn.edu/~wburdick/
COMMENT=		OpenGL based multipurpose image viewer

GNU_CONFIGURE=		yes
CONFIG_STATUS_OVERRIDE=	# defined

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/viewer ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/viewer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/glut/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
