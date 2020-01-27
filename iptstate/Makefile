# $NetBSD: Makefile,v 1.7 2012/09/30 05:41:12 asau Exp $
#

DISTNAME=		iptstate-2.0
CATEGORIES=		net
MASTER_SITES=		http://www.phildev.net/iptstate/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		https://www.phildev.net/iptstate/
COMMENT=		Display Netfilter state tables in a "top"-like interface

ONLY_FOR_PLATFORM=	Linux-*-*
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} iptstate ${DESTDIR}${PREFIX}/sbin/
	cd ${WRKSRC} && ${INSTALL_MAN} iptstate.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
