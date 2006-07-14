# $NetBSD: Makefile,v 1.6 2006/07/14 20:58:29 plunky Exp $

DISTNAME=		hcidump-1.5.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.geocities.com/m_evmenkin/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Bluetooth traffic dumper, similar to tcpdump

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*	\
			NetBSD-3.99.[2-9][0-9]-*

WRKSRC=			${WRKDIR}/hcidump

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
