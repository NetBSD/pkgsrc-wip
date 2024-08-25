# $NetBSD$

DISTNAME=	timg-1.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hzeller/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://timg.sh/
COMMENT=	Terminal image and video viewer
LICENSE=	gnu-gpl-v2

.include "options.mk"

WRKSRC=		${WRKDIR}/timg-1.4.2

USE_TOOLS=	cmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c++
CMAKE_CONFIGURE_ARGS+=	-DTIMG_VERSION_FROM_GIT=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENSLIDE_SUPPORT=OFF

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/timg ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/timg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
