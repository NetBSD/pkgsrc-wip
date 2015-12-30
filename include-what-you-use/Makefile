# $NetBSD$

DISTNAME=	include-what-you-use-0.5.src
PKGNAME=	${DISTNAME:.src=}
CATEGORIES=	devel
MASTER_SITES=	http://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://include-what-you-use.org/downloads/
COMMENT=	Analyze \#includes in C and C++ source files
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/libLLVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
