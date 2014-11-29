# $NetBSD: Makefile,v 1.1 2014/11/29 16:22:45 nros Exp $

DISTNAME= 	gflags-2.1.1
CATEGORIES= 	devel
MASTER_SITES=	-https://github.com/schuhschuh/gflags/archive/v${PKGVERSION_NOREV}.tar.gz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/gflags/
COMMENT=	Commandline flags processing library
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_STATIC_LIBS:BOOL=ON
PTHREAD_OPTS+=	require

REPLACE_BASH=	src/gflags_completions.sh

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
