# $NetBSD$

DISTNAME=	docker-compose-cli-1.0.17
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	compose-cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docker/compose-cli
COMMENT=	Run your Compose application to the cloud
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cli

# XXX: Big kludge to patch the files in .gopath too that are the ones that needs
# XXX: to be patched but are populated only as part of the `${GO} install -v'.
do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN} || \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/docker/docker@v20.10.5+incompatible/pkg/system/rm.go && \
	${CP} ${WRKDIR}/github.com/docker/docker@v20.10.5+incompatible/pkg/system/rm.go ${WRKDIR}/.gopath/pkg/mod/github.com/docker/docker@v20.10.5+incompatible/pkg/system/rm.go && \
	${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cli ${DESTDIR}${PREFIX}/bin/docker-compose-cli

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
