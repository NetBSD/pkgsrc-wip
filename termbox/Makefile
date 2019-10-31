# $NetBSD$

DISTNAME=	termbox-1.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nsf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/nsf/termbox/
COMMENT=	Library for writing text-based user interfaces
LICENSE=	mit

PYTHON_FOR_BUILD_ONLY=	yes

TOOL_DEPENDS+=	waf>=1.8.4:../../devel/waf

.include "../../devel/waf/waf.mk"
.include "../../mk/bsd.pkg.mk"
