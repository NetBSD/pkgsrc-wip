# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	sylvan-1.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=utwente-fmt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/utwente-fmt/sylvan/
COMMENT=	Multi-core Decision Diagram (BDD/LDD) implementation
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/sylvan-1.5.0
USE_LIBTOOL=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
