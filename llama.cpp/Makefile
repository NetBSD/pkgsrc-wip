# $NetBSD$

DISTNAME=	llama.cpp-b3091
PKGNAME=	${DISTNAME:S/-b/-0.0.2./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggerganov/}
GITHUB_TAG=	b3091

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

#WRKSRC=		${WRKDIR}/llama.cpp-b3091
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in
REPLACE_PYTHON+=	*.py */*.py */*/*.py

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
