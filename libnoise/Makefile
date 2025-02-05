# $NetBSD$

DISTNAME=	libnoisesrc-1.0.0
PKGNAME=	${DISTNAME:S,src,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnoise/}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/noise

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.cytopia.net/
COMMENT=	Coherent noise-generating library for C++
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

# libtool silently skips building the .so without
LDFLAGS+=	-rpath ${PREFIX}/lib

INSTALLATION_DIRS=	lib
INSTALLATION_DIRS+=	include/noise
INSTALLATION_DIRS+=	include/noise/model
INSTALLATION_DIRS+=	include/noise/module

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/libnoise.la ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/*.h        ${DESTDIR}${PREFIX}/include/noise
	${INSTALL_DATA} ${WRKSRC}/include/model/*.h  ${DESTDIR}${PREFIX}/include/noise/model/
	${INSTALL_DATA} ${WRKSRC}/include/module/*.h ${DESTDIR}${PREFIX}/include/noise/module/

.include "../../mk/bsd.pkg.mk"
