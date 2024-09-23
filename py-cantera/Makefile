# $NetBSD$

GITHUB_PROJECT=	cantera
GITHUB_TAG=	refs/tags/v3.1.0a4
DISTNAME=	v3.1.0a4
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cantera/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cantera/cantera/
COMMENT=	Chemical kinetics, thermodynamics, and transport tool suite
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/cantera-3.1.0a4
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

SCONS_BUILD_ARGS+=	build

#MAKE_ENV+=	CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}

PKGCONFIG_OVERRIDE+=	platform/posix/cantera.pc.in

DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging

.include "../../devel/scons4/build.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
