# $NetBSD$

VERSION=	0.5
PKGNAME=	tracy-${VERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/wolfpld/tracy/get/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://bitbucket.org/wolfpld/tracy
COMMENT=	Real time, nanosecond resolution frame profiler
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/wolfpld-tracy-9b6328f96258
USE_LANGUAGES=	c c++

USE_TOOLS+=		gmake pkg-config
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/profiler/build/unix && ${GMAKE} release


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/profiler/build/unix/Tracy-release ${DESTDIR}${PREFIX}/bin/tracy

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
