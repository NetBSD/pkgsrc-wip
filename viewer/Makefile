# $NetBSD: Makefile,v 1.5 2006/04/20 13:36:44 cheusov Exp $

DISTNAME=		viewer-0.7.3
CATEGORIES=		graphics
MASTER_SITES=		http://www-users.cs.umn.edu/~wburdick/ftp/geowall/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-users.cs.umn.edu/~wburdick
COMMENT=		OpenGL based multipurpose image viewer

GNU_CONFIGURE=		yes
CONFIG_STATUS_OVERRIDE= # defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/viewer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/viewer.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
