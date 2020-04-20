# $NetBSD$

DISTNAME=	slack-term-0.5.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=erroneousboat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erroneousboat/slack-term
COMMENT=	Slack client for your terminal
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/erroneousboat/slack-term

INSTALLATION_DIRS+=	bin share/doc/slack-term

CHECK_RELRO_SKIP+=	bin/slack-term

post-patch:
	${CP} ${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg/xdg_linux.go \
	    ${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg/xdg_netbsd.go 

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/slack-term ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/slack-term

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
