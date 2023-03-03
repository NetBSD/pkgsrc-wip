# $NetBSD: Makefile,v 1.5 2022/09/17 11:03:56 leot Exp $

DISTNAME=	editorconfig-checker-2.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=editorconfig-checker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/editorconfig-checker/editorconfig-checker
COMMENT=	Verify that your files are in harmony with your .editorconfig
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/editorconfig-checker

.include "go-modules.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/editorconfig-checker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
