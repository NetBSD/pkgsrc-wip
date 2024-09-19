# $NetBSD: Makefile,v 1.9 2012/11/25 23:32:10 othyro Exp $
#

DISTNAME=		dvbsnoop-1.4.00
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
