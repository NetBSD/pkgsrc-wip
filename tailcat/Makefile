# $NetBSD$

DISTNAME=	tailcat-0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=tailscale/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tailscale/tailcat/
COMMENT=	Netcat over Tailscale's data plane, without its control plane
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	github.com/tailscale/tailcat/cmd/tailcat

# Upstream stamps the version this way at release time; without it the
# binary reports the module version, which is "(devel)" for a tarball build.
GOFLAGS=	-ldflags "-X main.version=v${PKGVERSION_NOREV}"

# The build pulls in runtime/cgo.
USE_LANGUAGES=	c

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The tailscale/wireguard-go module has no NetBSD support: its ipc package
# matches no file (device/uapi.go imports it unconditionally) and its tun
# package has no tun_netbsd.go.  Patch it in the module cache, which
# patches/ cannot reach; go list -e populates that cache without building,
# and the build cache is dropped so the pre-patch analysis is not reused.
# The copied tun driver only resolves tun.CreateTUN -- it still issues the
# OpenBSD ioctl -- which is harmless because tailcat runs netstack in
# userspace and never opens a tun(4); net/wireguard-go has the real NetBSD
# driver.  Bump WIREGUARD_GO when go.mod moves the pin.
WIREGUARD_GO=	github.com/tailscale/wireguard-go@v0.0.0-20260821191448-23d18d66172c

pre-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} list -e -deps ${GO_BUILD_PATTERN} >/dev/null
	${RUN} cd ${WRKDIR}/.gopath/pkg/mod/${WIREGUARD_GO} && ${CHMOD} -R +w . && \
		${SED} -i -e 's,^//go:build \(.*openbsd\)$$,//go:build \1 || netbsd,' \
			ipc/uapi_bsd.go ipc/uapi_unix.go && \
		${CP} tun/tun_openbsd.go tun/tun_netbsd.go
	${RUN} ${RM} -rf ${GO_CACHE_DIR} && ${MKDIR} ${GO_CACHE_DIR}
.endif

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
