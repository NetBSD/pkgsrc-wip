# $NetBSD: Makefile,v 1.6 2012/10/07 17:41:42 asau Exp $
#

DISTNAME=	virus-0.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.rocklinux.net/people/ripclaw/projects/software/virus/
COMMENT=	VI resembling utility skeleton

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SH} mkvirus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/virus ${DESTDIR}${PREFIX}/bin/virus

.include "../../mk/bsd.pkg.mk"
