# $NetBSD$

DISTNAME=	OpenCL-CLHPP
PKGNAME=	opencl-clhpp-2.2.0.20200123
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	${DISTNAME}
GITHUB_TAG=	3a4d175f89d8ff3f806bf88fc2af4be582c198d2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/OpenCL-CLHPP
COMMENT=	OpenCL API C++ bindings (cl.hpp and cl2.hpp)
LICENSE=	mit # mostly, XXX: double-check

PYTHON_FOR_BUILD_ONLY=	tool

do-build:
	${RUN} cd ${WRKSRC} && ${PYTHONBIN} gen_cl_hpp.py

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/CL
	${RUN} cd ${WRKSRC} && \
	    ${INSTALL_DATA} include/CL/* ${DESTDIR}${PREFIX}/include/CL

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
