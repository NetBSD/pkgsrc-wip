# $NetBSD$

# N.B. Not sure if we need to override "python" in the Makefiles.

DISTNAME=	bedtools2-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=arq5x/}
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/arq5x/bedtools2
COMMENT=	Swiss army knife for genome arithmetic
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
REPLACE_BASH=	scripts/*.sh
REPLACE_PYTHON=	scripts/*.py

PORTVERSION=	2.27.1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == i386
MAKE_ENV+=	POPCNT_CAPABILITY=0
.endif

pre-configure:
	${SED} -i -e 's|@\$$(CXX)|$(CXX)|g' \
	        ${WRKSRC}/*/Makefile \
	        ${WRKSRC}/*/*/Makefile \
	        ${WRKSRC}/*/*/*/Makefile \
	        ${WRKSRC}/*/*/*/*/Makefile

post-install:
	${STRIP_CMD} ${DESTDIR}${PREFIX}/bin/bedtools

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
