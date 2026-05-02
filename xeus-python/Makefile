# $NetBSD$
DISTNAME=	xeus-python-0.19.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-python/
COMMENT=	Jupyter kernel for Python, based on the xeus framework
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++


PYTHON_VERSIONS_ACCEPTED=	312 311 310 # Package says < 3.13

TOOL_DEPENDS+=	${PYPKGPREFIX}-pybind11>=3.0.0:../../devel/py-pybind11

.include "../../lang/python/pyversion.mk"

CMAKE_CONFIGURE_ARGS+=	-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}
MAKE_ENV+=		VERBOSE=1
CONFIGURE_ENV+=		VERBOSE=1

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif


post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} xpython xpython-${PYVERSSUFFIX}


SUBST_CLASSES+=			pyversion
SUBST_MESSAGE.pyversion=	Replace xpython with xpython-${PYVERSSUFFIX}
SUBST_STAGE.pyversion=		pre-install
SUBST_FILES.pyversion+=		share/jupyter/kernels/xpython/kernel.json
SUBST_FILES.pyversion+=		share/jupyter/kernels/xpython-raw/kernel.json
SUBST_SED.pyversion+=		-e "s,xpython,xpython-${PYVERSSUFFIX},"

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../devel/cmake/build.mk"
.include "../../devel/cmake/configure-settings.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../wip/py-pybind11_json/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
