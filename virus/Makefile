# $NetBSD: Makefile,v 1.2 2004/04/25 08:29:31 blef Exp $
#

DISTNAME=	virus-0.0.6
CATEGORIES=	wip
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
