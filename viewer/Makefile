# $NetBSD: Makefile,v 1.3 2005/04/11 21:16:10 tvierling Exp $

DISTNAME=		viewer-0.7.3
CATEGORIES=		graphics
MASTER_SITES=		http://www-users.cs.umn.edu/~wburdick/ftp/geowall/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-users.cs.umn.edu/~wburdick
COMMENT=		OpenGL based multipurpose image viewer

GNU_CONFIGURE=		yes
CONFIG_STATUS_OVERRIDE= # defined

USE_X11=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/viewer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/viewer.1 ${PREFIX}/man/man1

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
