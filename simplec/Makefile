# $NetBSD: Makefile,v 1.4 2006/11/11 11:31:06 shattered Exp $
#

DISTNAME=		simplec
PKGNAME=		simplec-0.1.1
CATEGORIES=		lang
MASTER_SITES=		http://retro.tunes.org/simplec/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://retro.tunes.org/simplec/
COMMENT=		Port of SmallC/i386 compiler

ONLY_FOR_PLATFORM=	*-*-i386

do-build:
	cd ${WRKSRC}/ && sh ./build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/scc ${PREFIX}/bin/scc

.include "../../mk/bsd.pkg.mk"
