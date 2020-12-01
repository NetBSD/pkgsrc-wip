# $NetBSD$

PKGNAME=	sdl-hercules-hyperion-4.3
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
USE_TOOLS+=	bash
USE_LIBTOOL=	YES
USE_LANGUAGES+=	c
PTHREAD_OPTS+=	require
REPLACE_BASH=	_dynamic_version

CONFIGURE_ARGS+=	--enable-extpkgs=${PREFIX}/lib/sdlhercules

INSTALLATION_DIRS+=	share/examples/hercules

pre-configure:
	${RM} ${WRKSRC}/ltdl.h ${WRKSRC}/ltdl.c
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${DESTDIR}${PREFIX}/share/examples/hercules/

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/sdl-hercules-crypto/buildlink3.mk"
.include "../../wip/sdl-hercules-decnumber/buildlink3.mk"
.include "../../wip/sdl-hercules-softfloat/buildlink3.mk"
.include "../../wip/sdl-hercules-telnet/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
