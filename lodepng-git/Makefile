# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	lodepng-0.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lvandeve/lodepng
COMMENT=	PNG encoder and decoder in C and C++
LICENSE=	zlib

GIT_REPOSITORIES=	lodepng
GIT_REPO.lodepng=	https://github.com/lvandeve/lodepng.git
WRKSRC=			${WRKDIR}/lodepng

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include lib

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode compile --tag=CXX ${CXX} \
	    ${CXXFLAGS} -I. -c lodepng.cpp && \
        ${LIBTOOL} --mode link --tag=CXX ${CXX} ${LDFLAGS} \
            -rpath ${PREFIX}/lib -version-info 1:1:0 -release 0.1 \
            -o liblodepng.la lodepng.lo

do-install:
	${INSTALL_DATA} ${WRKSRC}/lodepng.h ${DESTDIR}${PREFIX}/include
	${LIBTOOL} --mode install ${INSTALL_LIB} ${WRKSRC}/liblodepng.la ${DESTDIR}${PREFIX}/lib

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
