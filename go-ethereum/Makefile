# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-1.10.25
GITHUB_PROJECT=	go-ethereum
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ethereum/go-ethereum/
COMMENT=	Official Go implementation of the Ethereum protocol
LICENSE=	gnu-lgpl-v3

GO_BUILD_PATTERN=	./cmd/geth

do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} run build/ci.go install ${GO_BUILD_PATTERN}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/bin/geth \
		${DESTDIR}${PREFIX}/bin/geth

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
