# $NetBSD: Makefile,v 1.1.1.1 2004/03/03 23:37:08 poppnk Exp $
#

DISTNAME=		xjump_2.7.5.orig
PKGNAME=		xjump-2.7.5
CATEGORIES=		wip games
MASTER_SITES=		ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/\
			http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gtlib.cc.gatech.edu/pub/debian/pool/main/x/xjump/
COMMENT=		A jumping game for X

WRKSRC=			${WRKDIR}/xjump-2.7.5.orig
USE_BUILDLINK3=		yes
ALL_TARGET=		xjump

USE_X11=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjump ${PREFIX}/bin/xjump

.include "../../mk/bsd.pkg.mk"
