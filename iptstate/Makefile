# $NetBSD: Makefile,v 1.1 2004/06/06 18:34:07 rillig Exp $
#

DISTNAME=		iptstate-1.3
CATEGORIES=		net
MASTER_SITES=		http://iptstate.phildev.net/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://iptstate.phildev.net/
COMMENT=		Display Netfilter state tables in a "top"-like interface

ONLY_FOR_PLATFORM=	Linux-2.4*

USE_BUILDLINK3=		yes

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} iptstate ${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_MAN} man/man1/iptstate.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
