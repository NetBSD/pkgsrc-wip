# $NetBSD$

DISTNAME=	LHAPDF-6.1.6
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/lhapdf/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://lhapdf.hepforge.org/
COMMENT=	Les Houches Accord PDF library and interface
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	lhapdf.pc.in

REPLACE_BASH+=	lhapdf-config.in

.include "options.mk"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
