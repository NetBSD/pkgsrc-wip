# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 17:27:06 poppnk Exp $
#

DISTNAME=		dvbsnoop-1.3.77
CATEGORIES=		wip net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dvbsnoop.sourceforge.net/
COMMENT=		DVB / MPEG stream analyzer program

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvbsnoop ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
