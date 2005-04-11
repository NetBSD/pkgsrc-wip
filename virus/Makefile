# $NetBSD: Makefile,v 1.4 2005/04/11 21:16:10 tvierling Exp $
#

DISTNAME=	virus-0.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
COMMENT=	VI resembling utility skeleton


do-build:
	cd ${WRKSRC} && ${SH} mkvirus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/virus ${PREFIX}/bin/virus

.include "../../mk/bsd.pkg.mk"
