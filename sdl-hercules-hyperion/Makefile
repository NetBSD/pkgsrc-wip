# $NetBSD$

PKGNAME=	sdl-hercules-hyperion-4.2.1
DISTNAME=	Release_${PKGVERSION_NOREV}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
EXTRACT_USING=	bsdtar

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of Hercules 4.x (Hyperion)
LICENSE=	qpl-v1.0

GITHUB_PROJECT=	hyperion
GITHUB_TAG=	Release_${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake flex gawk grep gm4 gmake perl gsed
USE_LANGUAGES+=	c


CONFIGURE_ARGS+=	--disable-ipv6	# configure can't find header

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
