# $NetBSD: Makefile,v 1.3 2007/01/22 17:50:51 minskim Exp $
#

DISTNAME=		YouGrabber-0.20
CATEGORIES=		net multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yougrabber/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://yougrabber.sourceforge.net/
COMMENT=		YouTube downloader

BUILD_TARGET=		yg
USE_NCURSES=		yes # color

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yg ${PREFIX}/bin

.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
