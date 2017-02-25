# $NetBSD$

DISTNAME=	dvisvgm-2.1.3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgieseki/}
GITHUB_RELEASE=	2.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgieseki/dvisvgm/
COMMENT=	Fast DVI to SVG converter
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CPPFLAGS+=	-I${BUILDLINK_PREFIX.kpathsea}/lib

DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
