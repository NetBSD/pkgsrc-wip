# $NetBSD$

DISTNAME=	OpenCL-Headers
PKGNAME=	opencl-headers-2.2.0.20200123
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	${DISTNAME}
GITHUB_TAG=	4ba6f9bee89ffc7eb1598d95527484524fb7c461

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/OpenCL-Headers
COMMENT=	OpenCL API Headers
LICENSE=	mit # mostly, XXX: double-check

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/CL
	${RUN} cd ${WRKSRC} && \
	    ${INSTALL_DATA} CL/* ${DESTDIR}${PREFIX}/include/CL

.include "../../mk/bsd.pkg.mk"
