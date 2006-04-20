# $NetBSD: Makefile,v 1.4 2006/04/20 13:36:37 cheusov Exp $
#

DISTNAME=		iptstate-1.3
CATEGORIES=		net
MASTER_SITES=		http://iptstate.phildev.net/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://iptstate.phildev.net/
COMMENT=		Display Netfilter state tables in a "top"-like interface

ONLY_FOR_PLATFORM=	Linux-2.4.*-*

do-install:
	cd ${WRKSRC:Q} && ${INSTALL_PROGRAM} iptstate ${PREFIX:Q}/bin/
	cd ${WRKSRC:Q} && ${INSTALL_MAN} man/man1/iptstate.1 ${PREFIX:Q}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
