# $NetBSD: Makefile,v 1.1.1.1 2004/10/18 13:01:08 poppnk Exp $
#

DISTNAME=		shaper_2.2.12-0.7.3.orig
PKGNAME=	shaper-2.2.12
CATEGORIES=		wip net linux
MASTER_SITES=		http://ftp.debian.org/debian/pool/main/s/shaper/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ftp.debian.org/debian/pool/main/s/shaper/
COMMENT=		Bandwidth limiter for Linux

WRKSRC=		${WRKDIR}/shaper-2.2.12-0.7.3/shaper/
USE_BUILDLINK3=		yes

ONLY_FOR_PLATFORM=Linux-*-*

USE_PKGINSTALL=YES
RCD_SCRIPTS=shaper
EGDIR=${PREFIX}/share/examples/shaper
CONF_FILES=${EGDIR}/shaper.conf ${PKG_SYSCONFDIR}/shaper.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shapecfg ${PREFIX}/sbin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/shaper/
	${INSTALL_DATA} ${WRKSRC}/../README.shaper ${PREFIX}/share/doc/shaper/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/shaper/
	${INSTALL_DATA} ${FILESDIR}/shaper.conf ${PREFIX}/share/examples/shaper/

.include "../../mk/bsd.pkg.mk"
