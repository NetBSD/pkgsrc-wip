# $NetBSD: Makefile,v 1.1.1.1 2006/09/26 08:14:43 thomaspfaff Exp $
#

DISTNAME=		libpac-0.6.2
PKGNAME=		xmms-pac-0.6.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libpac/}

MAINTAINER=		thomaspfaff@users.sourceforge.net
HOMEPAGE=		http://libpac.sourceforge.net/
COMMENT=		PAC input plugin for XMMS

WRKSRC=			${WRKDIR}/${DISTNAME}/src/xmms
BUILD_TARGET=		libxmmspac.so
USE_TOOLS+=		gmake

do-install:
			${INSTALL_LIB} ${WRKSRC}/libxmmspac.so \
			${PREFIX}/lib/xmms/Input

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
