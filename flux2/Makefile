# $NetBSD$

DISTNAME=	flux2-0.31.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fluxcd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fluxcd.io/
COMMENT=	Continuous delivery solution for Kubernetes
LICENSE=	apache-2.0

USE_TOOLS+=	bash gmake

TOOL_DEPENDS+=	kustomize-[0-9]*:../../wip/kustomize

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.VERSION=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/flux

REPLACE_BASH+=	manifests/scripts/bundle.sh

# Build the embedded manifests
pre-build:
	${RUN} cd ${WRKSRC} && ${GMAKE} cmd/flux/.manifests.done

# XXX: Big kludge to patch the files in .gopath too that are the ones that needs
# XXX: to be patched but are populated only as part of the `${GO} install -v'.
do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN} || \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0 && \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0/process_unix.go && \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0/process_unix_test.go && \
	${CP} ${WRKDIR}/github.com/mitchellh/go-ps@v1.0.0/process_netbsd.go ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0/process_netbsd.go && \
	${CP} ${WRKDIR}/github.com/mitchellh/go-ps@v1.0.0/process_unix.go ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0/process_unix.go && \
	${CP} ${WRKDIR}/github.com/mitchellh/go-ps@v1.0.0/process_unix_test.go ${WRKDIR}/.gopath/pkg/mod/github.com/mitchellh/go-ps@v1.0.0/process_unix_test.go && \
	${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
