# $NetBSD$

DISTNAME=	minio-${GITHUB_TAG}
PKGNAME=	minio-${GITHUB_TAG:S/^RELEASE.//:C/T.*//:S/-//g}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=minio/}
GITHUB_TAG=	RELEASE.2024-08-03T04-33-23Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://minio.io/
COMMENT=	High performance distributed object storage server
LICENSE=	gnu-agpl-v3

CHECK_RELRO_SKIP=	bin/minio
INSTALLATION_DIRS+=	bin

# Use buildscripts/gen-ldflags.go to keep in sync.
GO_LDFLAGS+=	-X github.com/minio/minio/cmd.Version=${GITHUB_TAG:S/RELEASE.//}
GO_LDFLAGS+=	-X github.com/minio/minio/cmd.CopyrightYear=2024
GO_LDFLAGS+=	-X github.com/minio/minio/cmd.ReleaseTag=DEVELOPMENT.${GITHUB_TAG:S/RELEASE.//}

GO_BUILD_PATTERN=	--ldflags "${GO_LDFLAGS}"

do-test:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} CC=${CC:Q} CGO_ENABLED=1 \
	    ${GO} test -v ./...

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/minio ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
