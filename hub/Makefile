# $NetBSD$

DISTNAME=	hub-2.2.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hub.github.com/
COMMENT=	hub helps you win at git
LICENSE=	mit

WRKSRC=		${WRKDIR}/src/github.com/github/hub

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go
DEPENDS+=		git-base>=1.7.3:../../devel/git-base

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/hub

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	    go build -ldflags "-X github.com/github/hub/version.Version=${PKGVERSION_NOREV}" -o bin/hub

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/hub ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/hub.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
