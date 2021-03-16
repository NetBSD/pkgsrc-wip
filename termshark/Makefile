# $NetBSD: Makefile,v 1.9 2021/03/14 14:10:18 leot Exp $

DISTNAME=	termshark-2.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=gcla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gcla/termshark
COMMENT=	Terminal UI for tshark, inspired by Wireshark
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/termshark

INSTALLATION_DIRS+=	bin share/doc/termshark

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/termshark ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ.md ${DESTDIR}${PREFIX}/share/doc/termshark
	${INSTALL_DATA} ${WRKSRC}/docs/UserGuide.md ${DESTDIR}${PREFIX}/share/doc/termshark

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
