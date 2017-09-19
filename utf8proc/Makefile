# $NetBSD$

DISTNAME=	utf8proc-2.1.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=JuliaLang/}
GITHUB_PROJECT=	utf8proc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://julialang.org/utf8proc/
COMMENT=	Clean C library for processing UTF-8 Unicode data
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/build
USE_CMAKE=	yes

CMAKE_ARG_PATH=	..

INSTALLATION_DIRS+=	include lib

post-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/utf8proc.h \
		${DESTDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libutf8proc.a ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
