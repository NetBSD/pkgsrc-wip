# $NetBSD: Makefile,v 1.1.1.1 2008/02/21 21:14:19 pmatias Exp $
#

DISTNAME=	agg-2.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.antigrain.com/

MAINTAINER=	matias@dotbsd.org
HOMEPAGE=	http://www.antigrain.com/
COMMENT=	High Quality Rendering Engine for C++

USE_TOOLS+=	gmake msgfmt pkg-config aclocal autoheader \
            automake autoconf
USE_LANGUAGES=	c c++
USE_LIBTOOL=            yes
GNU_CONFIGURE=          yes

PKGCONFIG_OVERRIDE+=	libagg.pc.in

pre-configure:
	cd ${WRKSRC}; chmod +x autogen.sh; ./autogen.sh

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
