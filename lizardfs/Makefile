# $NetBSD$

DISTNAME=	lizardfs-0.0
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=dressupgeekout/}
GITHUB_TAG=	d3355b690aa4e216aa5b0656c5cd4eb80c6dafd4

MAINTANER=	charlotte@NetBSD.org
HOMEPAGE=	https://lizardfs.com/
COMMENT=	Open source, distributed file system
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		..

pre-configure:
.for dir in ${CONFIGURE_DIRS}
	mkdir -p ${WRKSRC}/${dir}
.endfor

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
