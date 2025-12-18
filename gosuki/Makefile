# $NetBSD$

DISTNAME=	gosuki-1.3.0.20251218
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=blob42/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	92c2d4b4f45205240a771ee1b3610682ee97b9ba

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/blob42/gosuki/
COMMENT=	Lightweight, open-source, privacy-first bookmark manager
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
