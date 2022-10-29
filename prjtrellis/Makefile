# $NetBSD$

DISTNAME=	prjtrellis-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_PROJECT=	prjtrellis
GITHUB_TAG=	35f5affe10a2995bdace49e23fcbafb5723c5347
GITHUB_SUBMODULES=	\
	YosysHQ prjtrellis-db 35d900a94ff0db152679a67bf6e4fbf40ebc34aa ../database

MAINTAINER=	lloyd@must-have-coffee.gen.nz
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT=	Documenting the Lattice ECP5 bit-stream format
LICENSE=	mit

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/libtrellis

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		git
SUBST_MESSAGE.git=	Patch for missing git functionality in the releases
SUBST_STAGE.git=	pre-configure
SUBST_SED.git=		-e 's,git describe --tags,echo pkgsrc-${PKGVERSION},g'
SUBST_FILES.git+=	CMakeLists.txt

.include "../../lang/python/application.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
