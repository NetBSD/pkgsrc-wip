# $NetBSD: Makefile,v 1.2 2004/04/04 02:30:36 poppnk Exp $
#

DISTNAME=		simplec
PKGNAME=		simplec-0.1.1
CATEGORIES=		wip
MASTER_SITES=		http://retro.tunes.org/simplec/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://retro.tunes.org/simplec/
COMMENT=		Port of SmallC/i386 compiler

ONLY_FOR_PLATFORM=	*-*-i386

do-build:
	cd ${WRKSRC}/ && ${SH} ./build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/scc ${PREFIX}/bin/scc

.include "../../mk/bsd.pkg.mk"
