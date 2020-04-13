# $NetBSD$

DISTNAME=		oneko-1.2.1
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_GITHUB:=teknokatze/}
GITHUB_RELEASE=		1.2.1
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://n0.is/s/oneko/
COMMENT=		Neko (cat) or other animals follow your pointer
LICENSE=		2-clause-bsd # and public-domain

USE_CMAKE=		yes
USE_LANGUAGES=		c

RESTRICTED=		Includes deriviatives from CARDCAPTOR SAKURA. See http://www.clamp-net.com/ -> INFORMATION
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CMAKE_ARGS+=		-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}


.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
