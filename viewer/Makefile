# $NetBSD: Makefile,v 1.1.1.1 2004/02/21 23:21:04 bjan2 Exp $

DISTNAME=		viewer-0.7.3
CATEGORIES=		graphics
MASTER_SITES=		http://www-users.cs.umn.edu/~wburdick/ftp/geowall/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www-users.cs.umn.edu/~wburdick
COMMENT=		OpenGL based multipurpose image viewer

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIG_STATUS_OVERRIDE= # defined

USE_X11=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/viewer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/viewer.1 ${PREFIX}/man/man1

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
