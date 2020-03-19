# $NetBSD$

DISTNAME=	libtheorafile-2eab88940091765c27bdeaad87d25d2fd181f456
GITHUB_PROJECT=	Theorafile
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/FNA-XNA/Theorafile
COMMENT=	Ogg Theora video decoder library 
LICENSE=	zlib

EXTRACT_USING=	gtar
USE_TOOLS+=	gmake

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libtheorafile.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
