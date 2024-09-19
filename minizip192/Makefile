# $NetBSD: Makefile,v 0.3 2019/02/27 15:15:10 andyb Exp $

GITHUB_PROJECT=	qtxqfsts
DISTNAME=	minizip20190228
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsfd80/}
GITHUB_RELEASE=	20190228
DIST_SUBDIR=	${GITHUB_PROJECT}
PKGNAME=	minizip-19.2

MAINTAINER=	pkgls@gmx.net
HOMEPAGE=	https://github.com/bsfd80/qtxqfsts/
COMMENT=	Zip manipulation library written in C
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake gmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
