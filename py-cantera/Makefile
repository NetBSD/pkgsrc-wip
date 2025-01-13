# $NetBSD$

GITHUB_PROJECT=	cantera
GITHUB_TAG=	refs/tags/v3.1.0a4
DISTNAME=	v3.1.0a4
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cantera/}
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES+=	cantera cantera-example-data dbc4212 data/example_data

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cantera/cantera/
COMMENT=	Chemical kinetics, thermodynamics, and transport tool suite
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/cantera-3.1.0a4
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

SCONS_BUILD_ARGS+=	build
SCONS_BUILD_ARGS+=	prefix=${DESTDIR}${PREFIX}
SCONS_BUILD_ARGS+=	sundials_include=${PREFIX}/include
SCONS_BUILD_ARGS+=	sundials_libdir=${PREFIX}/lib
SCONS_BUILD_ARGS+=	run_examples=no

# pkgsrc assumes PREFIX to be a standard argument and adds it implicitly
# This package uses prefix instead. So have to do the following
.include "../../devel/scons4/build.mk"
_SCONS_BUILD_ARGS:=	${_SCONS_BUILD_ARGS:NPREFIX=${PREFIX}}


PKGCONFIG_OVERRIDE+=	platform/posix/cantera.pc.in

DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging
DEPENDS+=	googletest>=1.15.2:../../devel/googletest
DEPENDS+=	eigen3>=3.4.0:../../math/eigen3
DEPENDS+=	boost-libs>=1.85.0:../../devel/boost-libs
DEPENDS+=	sundials>=7.1.1:../../wip/sundials

TOOL_DEPENDS+=	${PYPKGPREFIX}-pip>=0:../../devel/py-pip
TOOL_DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.18.6:../../devel/py-ruamel-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

CHECK_RELRO=	no

.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../wip/sundials/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
