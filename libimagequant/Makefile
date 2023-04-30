# $NetBSD: Makefile,v 1.27 2023/04/27 06:06:19 wiz Exp $

DISTNAME=	libimagequant-4.1.1
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

#INSTALLATION_DIRS=	include lib

#do-install:
#	${INSTALL_DATA} ${WRKSRC}/libimagequant.h \
#		${DESTDIR}${PREFIX}/include/libimagequant.h
#	${LIBTOOL} --mode=install ${INSTALL_LIB} \
#		${WRKSRC}/libimagequant.la ${DESTDIR}${PREFIX}/lib

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
