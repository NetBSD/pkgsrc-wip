# $NetBSD: Makefile,v 1.6 2006/03/14 01:28:13 jlamwww Exp $
#

DISTNAME=		shaper_2.2.12-0.7.3.orig
PKGNAME=		shaper-2.2.12
CATEGORIES=		net linux
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/s/shaper/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://freshmeat.net/projects/cbq.init
COMMENT=		Bandwidth limiter for Linux

WRKSRC=			${WRKDIR}/shaper-2.2.12-0.7.3/shaper/

ONLY_FOR_PLATFORM=	Linux-*-*

RCD_SCRIPTS=		shaper
EGDIR=			${PREFIX}/share/examples/shaper
CONF_FILES=		${EGDIR}/shaper.conf ${PKG_SYSCONFDIR}/shaper.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shapecfg ${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shaper/
	${INSTALL_DATA} ${WRKSRC}/../README.shaper ${PREFIX}/share/doc/shaper/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/shaper/
	${INSTALL_DATA} ${FILESDIR}/shaper.conf ${PREFIX}/share/examples/shaper/

.include "../../mk/bsd.pkg.mk"
