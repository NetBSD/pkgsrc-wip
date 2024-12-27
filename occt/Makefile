# $NetBSD$

DISTNAME=	opencascade-7.7.0
PKGNAME=	${DISTNAME:S/opencascade/occt/}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	-http://git.dev.opencascade.org/gitweb/?p=occt.git;a=snapshot;h=refs/tags/V${PKGVERSION_NOREV:S/./_/g};sf=tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opencascade.org/
COMMENT=	Boundary Representation modeling toolkit and 3D geometry library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
WRKSRC=		${WRKDIR}/occt-V${PKGVERSION_NOREV:S/./_/g}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DUSE_FREETYPE=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_EIGEN=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_RAPIDJSON=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOC_Overview=OFF

REPLACE_BASH+=	adm/templates/draw.sh

CXXFLAGS+=			-fpermissive
CXXFLAGS.SunOS+=		-DSOLARIS=1
LDFLAGS.SunOS+=			-lnsl
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/share/opencascade/resources/DrawResources/InitEnvironment.tcl.orig

SUBST_CLASSES+=			cmakebinletter
SUBST_STAGE.cmakebinletter=	post-install
SUBST_MESSAGE.cmakebinletter=	Fixing $$OCCT_INSTALL_BIN_LETTER in cmake files
SUBST_FILES.cmakebinletter=	${DESTDIR}${PREFIX}/lib/cmake/opencascade/*.cmake
SUBST_SED.cmakebinletter=	-e 's/\\$${OCCT_INSTALL_BIN_LETTER}//g'

.include "../../mk/compiler.mk"

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
	(defined(ABI) && ${ABI} == "64")
.  if !empty(PKGSRC_COMPILER:Mclang)
OCCT_CUSTOM_COMPILER_DRIVER=	custom_clang_64.sh
.  else
OCCT_CUSTOM_COMPILER_DRIVER=	custom_gcc_64.sh
.  endif
.else
.  if !empty(PKGSRC_COMPILER:Mclang)
OCCT_CUSTOM_COMPILER_DRIVER=	custom_clang_32.sh
.  else
OCCT_CUSTOM_COMPILER_DRIVER=	custom_gcc_32.sh
.  endif
.endif

PLIST_SUBST=	OCCT_CUSTOM_COMPILER_DRIVER=${OCCT_CUSTOM_COMPILER_DRIVER:Q}

.include "../../devel/cmake/build.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
