# $NetBSD$

DISTNAME=	helm-3.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=helm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://helm.sh/
COMMENT=	The Kubernetes Package Manager
LICENSE=	apache-2.0

# XXX: via: `cd ${WRKSRC} && go list -f '{{.Version}}' -m k8s.io/client-go`
K8S_MODULES_VERSION=		0.20.2
K8S_MODULES_VERSION_MAJOR=	1 # 0 (from 0.20.x) + 1
K8S_MODULES_VERSION_MINOR=	20
GO_BUILD_PATTERN+=	-ldflags ' \
			-X helm.sh/helm/v3/internal/version.version=${PKGVERSION_NOREV} \
			-X helm.sh/helm/v3/internal/version.metadata="" \
			-X helm.sh/helm/v3/internal/version.gitCommit="" \
			-X helm.sh/helm/v3/internal/version.gitTreeState="" \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/lint/rules.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMajor=${K8S_MODULES_VERSION_MAJOR} \
			-X helm.sh/helm/v3/pkg/chartutil.k8sVersionMinor=${K8S_MODULES_VERSION_MINOR}'
GO_BUILD_PATTERN+=	./cmd/helm

# XXX: Big kludge to patch the files in .gopath too that are the ones that needs
# XXX: to be patched but are populated only as part of the `${GO} install -v'.
do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN} || \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/containerd/containerd@v1.4.3/content/local/store_unix.go && \
	${CHMOD} +w ${WRKDIR}/.gopath/pkg/mod/github.com/containerd/containerd@v1.4.3/sys/stat_bsd.go && \
	${CP} ${WRKDIR}/github.com/containerd/containerd@v1.4.3/content/local/store_unix.go ${WRKDIR}/.gopath/pkg/mod/github.com/containerd/containerd@v1.4.3/content/local/store_unix.go && \
	${CP} ${WRKDIR}/github.com/containerd/containerd@v1.4.3/sys/stat_bsd.go ${WRKDIR}/.gopath/pkg/mod/github.com/containerd/containerd@v1.4.3/sys/stat_bsd.go && \
	${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
