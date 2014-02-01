# $NetBSD: Makefile,v 1.3 2014/02/01 10:08:54 lokivit Exp $

PKGNAME=	cursor-dmz-theme-0.4
VERSION=	0.4
CATEGORIES=	x11
MASTER_SITES=	http://ponce.cc/slackware/sources/repo/
DISTNAME=	vanilla-dmz-${VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	loki.vt@gmail.com
COMMENT=	The DMZ style neutral scalable cursor theme

USE_BZIP2=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && pax -rw -pp [A-Za-z]* ${DESTDIR}${PREFIX}/share/icons
	
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
