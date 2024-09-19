# $NetBSD$

DISTNAME=	nyan-0.1.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=SFTtech/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
COMMENT=	Modding API with a typesafe hierarchical key-value database
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	flex-[0-9]*:../../devel/flex

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
