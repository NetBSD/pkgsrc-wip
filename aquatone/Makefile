# $NetBSD$

DISTNAME=	aquatone-1.7.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=michenriksen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/michenriksen/aquatone/
COMMENT=	Tool for domain flyovers
LICENSE=	mit

#DEPENDS+=	chromium-[0-9]*:../../wip/chromium

GO_BUILD_PATTERN=	aquatone

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
