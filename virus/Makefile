# $NetBSD: Makefile,v 1.1.1.1 2004/04/04 22:01:58 poppnk Exp $
#

DISTNAME=	virus-0.0.6
CATEGORIES=	wip
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
COMMENT=	VI resembling utility skeleton

do-build:
	cd ${WRKSRC} && ${SH} mkvirus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/virus ${PREFIX}/bin/virus

USE_BUILDLINK2=		yes

.include "../../mk/bsd.pkg.mk"
