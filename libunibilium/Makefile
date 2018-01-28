# $NetBSD: Makefile,v 1.4 2015/05/20 06:48:02 jonthn Exp $

DISTNAME=	libunibilium-1.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mauke/}
GITHUB_PROJECT=	unibilium
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/mauke/unibilium
COMMENT=	Basic terminfo library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	unibilium.pc.in

.include "../../mk/bsd.pkg.mk"
