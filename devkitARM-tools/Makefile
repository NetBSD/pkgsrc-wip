# $NetBSD$

DISTNAME=	devkitARM-tools-45
CATEGORIES=	cross

MASTER_SITES=	${MASTER_SITE_GITHUB:=devkitPro/}
GITHUB_PROJECT=	general-tools
GITHUB_TAG=	36c900196bbc3cf58375c8ae5f6ee46b3324b0a1

MAINTAINER=	js@heap.zone
HOMEPAGE=	http://devkitpro.org/
COMMENT=	General tools for devkitARM
# They currently don't have a license:
# https://github.com/devkitPro/general-tools/issues/1
LICENSE=	devkitpro-license
WRKSRC=		${WRKDIR}/general-tools-${GITHUB_TAG}
USE_LANGUAGES=	c c++

AUTO_MKDIRS=	yes

do-build:
.for i in bin2s padbin raw2c
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${i} ${i}.c
.endfor
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o bmp2bin bmp2bin.cpp

do-install:
.for i in bin2s bmp2bin padbin raw2c
	${INSTALL} -m 755 ${WRKSRC}/${i} \
		${DESTDIR}${PREFIX}/devkitpro/devkitARM/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
