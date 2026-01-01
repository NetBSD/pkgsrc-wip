# $NetBSD$

DISTNAME=	clipper_ver6.4.2
# clipper is too generic package name, go for polyclipping
PKGNAME=	${DISTNAME:S/_ver/-/:S/clipper/polyclipping/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyclipping/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/polyclipping/files/
COMMENT=	Polygon and line clipping and offsetting library
LICENSE=	boost-license

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

WRKSRC=		${WRKDIR}/cpp

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
