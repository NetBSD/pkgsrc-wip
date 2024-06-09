# $NetBSD: $

DISTNAME=	snapraid-12.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=amadvance/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	https://www.snapraid.it/
COMMENT=	Backup program designed for disk arrays
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c
USE_TOOLS=	autoconf autoreconf automake gmake
GNU_CONFIGURE=	yes

ONLY_FOR_PLATFORM=	NetBSD-*

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
