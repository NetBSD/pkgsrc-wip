# $NetBSD: Makefile,v 1.1 2015/07/10 21:24:03 travis-paul Exp $
# vim: noexpandtab:

GITHUB_PROJECT=	sds
PKGNAME=	${GITHUB_PROJECT}-0.d86a9b8
GITHUB_TAG=	d86a9b85cb4fb96430c7479ae6c956f2b605bbd1
DISTNAME=	master
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	Tr@visPaul.me
HOMEPAGE=	https://github.com/antirez/sds/
COMMENT=	Simple Dynamic Strings library for C
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	lib include

do-install:
	${INSTALL_LIB} ${WRKSRC}/libsds.so ${DESTDIR}${PREFIX}/lib/libsds.so
	${INSTALL_DATA} ${WRKSRC}/sds.h ${DESTDIR}${PREFIX}/include/sds.h

.include "../../mk/bsd.pkg.mk"
