# $NetBSD: Makefile,v 1.6 2012/07/05 14:54:34 othyro Exp $
#

DISTNAME=		dvbsnoop-1.4.00
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvbsnoop/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://dvbsnoop.sourceforge.net/
COMMENT=		DVB / MPEG stream analyzer program
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvbsnoop ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
