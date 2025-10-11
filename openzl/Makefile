# $NetBSD$

DISTNAME=	openzl-0.1.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} zstd-1.5.7.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/openzl/
COMMENT=	Novel data compression framework
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

# needs zstd sources
post-extract:
	${MV} ${WRKDIR}/zstd-1.5.7/* ${WRKSRC}/deps/zstd

# but we don't want to install another copy of zstd
# also install zli binary
post-install:
.for file in include/zdict.h include/zstd.h include/zstd_errors.h lib/cmake/zstd/* lib/libzstd* lib/pkgconfig/libzstd.pc
	${RM} ${DESTDIR}${PREFIX}/${file}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/cli/zli ${DESTDIR}${PREFIX}/bin

.include "../../devel/cmake/build.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
