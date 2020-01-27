# $NetBSD$

DISTNAME=	motion-4.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Motion-Project/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lavrsen.dk/foswiki/bin/view/Motion/WebHome
COMMENT=	Motion detecting video camera package
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake bash gmake pkg-config
CONFIG_SHELL=	bash

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
