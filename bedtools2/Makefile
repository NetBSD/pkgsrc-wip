# $NetBSD$

DISTNAME=	bedtools-2.29.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=arq5x/}
GITHUB_PROJECT=	bedtools2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/arq5x/bedtools2
COMMENT=	Swiss army knife for genome arithmetic
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
REPLACE_SH=	scripts/vcfsortsh
REPLACE_PYTHON=	scripts/makeBashScripts.py

SUBST_CLASSES+=		make
SUBST_STAGE.make=	pre-configure
SUBST_SED.make=		-e 's|python|${PYTHONBIN}|g'
SUBST_FILES.make=	Makefile

# Avoid conflict with C++20 <version> by adding .txt suffix
post-extract:
	@${MV} ${WRKSRC}/src/utils/gzstream/version \
		${WRKSRC}/src/utils/gzstream/version.txt

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
