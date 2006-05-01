# $NetBSD: Makefile,v 1.5 2006/05/01 14:20:08 shattered Exp $
#

DISTNAME=		iptstate-1.3
CATEGORIES=		net
MASTER_SITES=		http://www.phildev.net/iptstate/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.phildev.net/iptstate/
COMMENT=		Display Netfilter state tables in a "top"-like interface

ONLY_FOR_PLATFORM=	Linux-2.4.*-*

do-install:
	cd ${WRKSRC:Q} && ${INSTALL_PROGRAM} iptstate ${PREFIX:Q}/bin/
	cd ${WRKSRC:Q} && ${INSTALL_MAN} man/man1/iptstate.1 ${PREFIX:Q}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
