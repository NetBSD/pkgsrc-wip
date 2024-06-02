# $NetBSD$

DISTNAME=	go-mobius-0.12.2
GITHUB_PROJECT=	mobius
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhalter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/jhalter/mobius
COMMENT=	Hotline server
LICENSE=	mit
USE_TOOLS+=	pax

GO_VERSION_REQD=	122
GO_SRCPATH=		github.com/jhalter/mobius
GO_DIST_BASE=		${GITHUB_PROJECT}-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/mobius/config

post-install:
	cd ${WRKSRC}/cmd/mobius-hotline-server/mobius/config && \
		${PAX} -r -w . ${DESTDIR}${PREFIX}/share/mobius/config

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
