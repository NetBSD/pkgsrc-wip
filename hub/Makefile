# $NetBSD$

DISTNAME=	hub-2.2.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hub.github.com/
COMMENT=	hub helps you win at git
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/github/hub

DEPENDS+=		git-base>=1.7.3:../../devel/git-base

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/hub

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/hub ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/hub.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
