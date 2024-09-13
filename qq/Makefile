# $NetBSD$

DISTNAME=	qq-0.2.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=JFryy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}-r

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JFryy/qq/
COMMENT=	jq-inspired interoperable config format transcoder
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}-r
USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
