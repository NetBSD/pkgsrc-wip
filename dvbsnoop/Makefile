# $NetBSD: Makefile,v 1.5 2007/01/03 14:38:15 shattered Exp $
#

DISTNAME=		dvbsnoop-1.4.00
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dvbsnoop.sourceforge.net/
COMMENT=		DVB / MPEG stream analyzer program

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvbsnoop ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
