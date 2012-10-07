# $NetBSD: Makefile,v 1.5 2012/10/07 15:17:22 asau Exp $
#

DISTNAME=		simplec
PKGNAME=		simplec-0.1.1
CATEGORIES=		lang
MASTER_SITES=		http://retro.tunes.org/simplec/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://retro.tunes.org/simplec/
COMMENT=		Port of SmallC/i386 compiler

ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/ && sh ./build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/scc ${DESTDIR}${PREFIX}/bin/scc

.include "../../mk/bsd.pkg.mk"
