# $NetBSD$

PHAROVM_VER=	10.3.4
PHAROVM_AHEAD=	0
PHAROVM_HASH=	62881b7

DISTNAME=	PharoVM-v${PHAROVM_VER}+${PHAROVM_AHEAD}.${PHAROVM_HASH}-Linux-x86_64-c-src
PKGNAME=	pharo-vm10-${PHAROVM_VER}
CATEGORIES=	lang
MASTER_SITES=	http://files.pharo.org/vm/pharo-spur64-headless/Linux-x86_64/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pharo.org/
COMMENT=	VM used by Pharo
LICENSE=	mit

ONLY_FOR_PLATFORM=	NetBSD-[0-9]*-x86_64

WRKSRC=		${WRKDIR}/pharo-vm
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DFLAVOUR=CoInterpreter
CMAKE_CONFIGURE_ARGS+=	-DALWAYS_INTERACTIVE=1
CMAKE_CONFIGURE_ARGS+=	-DGENERATE_SOURCES=OFF
CMAKE_CONFIGURE_ARGS+=	-DPHARO_BIN_LOCATION=${PREFIX}/lib/pharo10

TOOL_DEPENDS+=          graphviz-[0-9]*:../../graphics/graphviz

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		packaging/linux/bin/launch.sh.in
SUBST_SED.fix-paths=		-e "s,@pkglibdir@,${PREFIX}/lib,g"

NOT_PAX_MPROTECT_SAFE+=	lib/pharo10/pharo

INSTALLATION_DIRS=	bin lib/pharo10

pre-configure:
	${CP} ${WRKSRC}/cmake/OpenBSD.cmake ${WRKSRC}/cmake/NetBSD.cmake

do-install:
	cd ${WRKSRC}/build/packaging/linux/bin && \
		${INSTALL_SCRIPT} pharo ${DESTDIR}${PREFIX}/bin/pharo10
	cd ${WRKSRC}/build/vm/ && \
		${INSTALL_PROGRAM} pharo ${DESTDIR}${PREFIX}/lib/pharo10
	cd ${WRKSRC}/build/vm/ && find . -type f -name "*.so" | while read file; do \
		${INSTALL_LIB} $$file ${DESTDIR}${PREFIX}/lib/pharo10; \
	done

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
