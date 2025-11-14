# $NetBSD: Makefile,v 1.20 2025/10/16 17:59:58 bsiegert Exp $

DISTNAME=	amneziawg-go-0.2.15
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=amnezia-vpn/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/amnezia-vpn/amneziawg-go/
COMMENT=	DPI-resistant Wireguard fork
LICENSE=	mit

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/amneziawg-go \
		${DESTDIR}${PREFIX}/bin/

GO_BUILD_PATTERN=	.

pre-patch:
	cd ${WRKSRC}/tun && ${LN} tun_openbsd.go tun_netbsd.go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
