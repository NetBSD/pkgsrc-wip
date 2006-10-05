# $NetBSD: Makefile,v 1.6 2006/10/05 08:15:51 rillig Exp $
#

DISTNAME=		iptstate-2.0
CATEGORIES=		net
MASTER_SITES=		http://www.phildev.net/iptstate/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.phildev.net/iptstate/
COMMENT=		Display Netfilter state tables in a "top"-like interface

ONLY_FOR_PLATFORM=	Linux-*-*
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} iptstate ${PREFIX}/sbin/
	cd ${WRKSRC} && ${INSTALL_MAN} iptstate.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
