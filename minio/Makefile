# $NetBSD$

DISTNAME=	minio-${GITHUB_TAG}
PKGNAME=	minio-20220813
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=minio/}
GITHUB_PROJECT=	minio
GITHUB_TAG=	RELEASE.2022-08-13T21-54-44Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://minio.io/
COMMENT=	High performance distributed object storage server
LICENSE=	gnu-agpl-v3

CHECK_RELRO_SKIP=	bin/minio
GO_BUILD_PATTERN=	--ldflags '-X github.com/minio/minio/cmd.Version=${GITHUB_TAG} -X github.com/minio/minio/cmd.ReleaseTag=${GITHUB_TAG}' .
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/minio ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
