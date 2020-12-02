# $NetBSD$

DISTNAME=       cockroach-v20.2.2.src
PKGNAME=        ${DISTNAME:S/.src//}
CATEGORIES=     databases
MASTER_SITES=   https://binaries.cockroachdb.com/
EXTRACT_SUFX=   .tgz

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       https://www.cockroachlabs.com/product/
COMMENT=        CockroachDB is a cloud-native SQL database for building global, scalable cloud services that survive disasters.
LICENSE=        apache-2.0

USE_LANGUAGES=	c c++

GO_SRCPATH=	github.com/cockroachdb/cockroach
GO_DIST_BASE=	${PKGNAME}

USE_TOOLS+=     gmake bash:run autoconf
CHECK_PORTABILITY_SKIP+= src/github.com/cockroachdb/cockroach/c-deps/protobuf/post_process_dist.sh

MAKE_ENV+=	GO=${GO} GOPATH=${WRKDIR}
BUILD_TARGET=	buildoss

do-build:
	cd ${WRKSRC}/src/${GO_SRCPATH} && ${MAKE_ENV} ${GMAKE} ${BUILD_TARGET}

DEPENDS+=       cmake>=3.17:../../devel/cmake

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
