# $NetBSD: Makefile,v 1.3 2004/07/18 15:05:50 ppostma Exp $
#

DISTNAME=	virus-0.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
COMMENT=	VI resembling utility skeleton

USE_BUILDLINK3=		yes

do-build:
	cd ${WRKSRC} && ${SH} mkvirus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/virus ${PREFIX}/bin/virus

.include "../../mk/bsd.pkg.mk"
