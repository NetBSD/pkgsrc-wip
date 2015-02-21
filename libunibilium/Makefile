# $NetBSD: Makefile,v 1.1 2015/02/21 16:20:18 jonthn Exp $

DISTNAME=	libunibilium-1.1.1
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/mauke/unibilium/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/mauke/unibilium
COMMENT=	Basic terminfo library
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/unibilium-${PKGVERSION_NOREV}

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	unibilium.pc.in

.include "../../mk/bsd.pkg.mk"
