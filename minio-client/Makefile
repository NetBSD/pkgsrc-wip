# $NetBSD$

DISTNAME=	minio-client-20220416
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=minio/}
GITHUB_PROJECT=	mc
GITHUB_TAG=	RELEASE.2022-04-16T21-11-21Z

COMMENT=	Tool implementing ls/cp/mkdir/diff/rsync for S3-like object storage
HOMEPAGE=	https://min.io/
MAINTAINER=	pkgsrc-users@NetBSD.org
LICENSE=	apache-2.0

CHECK_RELRO_SKIP=	bin/minio-client
#GO_SRCPATH=		github.com/minio/mc
GO_BUILD_PATTERN=	--ldflags '-X github.com/minio/mc/cmd.Version=${PKGVERSION} -X github.com/minio/mc/cmd.ReleaseTag=${GITHUB_TAG}' .
INSTALLATION_DIRS=	bin

# The name "mc" is a bit annoying because it conflicts with sysutils/mc.
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mc \
		${DESTDIR}${PREFIX}/bin/minio-client

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
