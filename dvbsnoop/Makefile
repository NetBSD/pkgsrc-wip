# $NetBSD: Makefile,v 1.8 2012/09/28 21:24:39 asau Exp $
#

DISTNAME=		dvbsnoop-1.4.00
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dvbsnoop.sourceforge.net/
COMMENT=		DVB / MPEG stream analyzer program
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvbsnoop ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
