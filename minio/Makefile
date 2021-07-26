# $NetBSD$

DISTNAME=	minio-${GITHUB_TAG}
PKGNAME=	minio-20210722
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=minio/}
GITHUB_PROJECT=	minio
GITHUB_TAG=	RELEASE.2021-07-22T05-23-32Z

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://minio.io/
COMMENT=	High performance distributed object storage server
LICENSE=	apache-2.0

CHECK_RELRO_SKIP=	bin/minio
GO_BUILD_PATTERN=	--ldflags '-X github.com/minio/minio/cmd.Version=${GITHUB_TAG} -X github.com/minio/minio/cmd.ReleaseTag=${GITHUB_TAG}' .
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/minio ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
