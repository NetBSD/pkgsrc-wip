# $NetBSD$

DISTNAME=		oneko-1.2.1
CATEGORIES=		x11 games
MASTER_SITES=		https://d.n0.is/pub/oneko/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ng0@n0.is
COMMENT=		Neko (cat) or other animals follow your pointer
LICENSE=		2-clause-bsd # and public-domain

USE_CMAKE=		yes
USE_LANGUAGES=		c

CMAKE_ARGS+=		-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}


.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
