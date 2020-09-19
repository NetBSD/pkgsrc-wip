# $NetBSD$

DISTNAME=	wireguard-go-0.0.20200320
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-go/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://www.wireguard.com/
COMMENT=	Implementation of WireGuard in Go
LICENSE=	mit

#DEPENDS+=	wireguard-tools>=1.0.20200827:../../net/wireguard-tools

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/wireguard \
		${DESTDIR}${PREFIX}/bin/wireguard-go

GO_BUILD_PATTERN=	.

post-patch:
	cd ${WRKSRC}/tun && ${LN} -sf tun_openbsd.go tun_netbsd.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
