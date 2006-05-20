# $NetBSD: Makefile,v 1.4 2006/05/20 10:47:25 poppnk Exp $
#

DISTNAME=		dvbsnoop-1.4.00
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dvbsnoop.sourceforge.net/
COMMENT=		DVB / MPEG stream analyzer program

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvbsnoop ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
