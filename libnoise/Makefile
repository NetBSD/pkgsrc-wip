# $NetBSD$

DISTNAME=	libnoisesrc-1.0.0
PKGNAME=	${DISTNAME:S,src,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnoise/}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/noise

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.cytopia.net/
COMMENT=	Coherent noise-generating library for C++
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
