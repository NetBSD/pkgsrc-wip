# $NetBSD$

DISTNAME=	clipper_ver6.4
# clipper is too generic package name, go for polyclipping
PKGNAME=	${DISTNAME:S/_ver/-/:S/clipper/polyclipping/}
CATEGORIES=	graphics
MASTER_SITES=	https://sourceforge.net/projects/polyclipping/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/polyclipping/files/
COMMENT=	Polygon and line clipping and offsetting library
LICENSE=	boost-license

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/cpp

.include "../../mk/bsd.pkg.mk"
