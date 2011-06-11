# $NetBSD: Makefile,v 1.1.1.1 2011/06/11 12:56:32 jathis Exp $
#

V=	2010-05-05
S=	BZR2356-stable
DISTNAME=	kicad-sources-${V}-${S}
PKGNAME= kicad-${V:S/-//g}
CATEGORIES=	cad
MASTER_SITES=	ftp://iut-tice.ujf-grenoble.fr/cao/
EXTRACT_SUFX=	.zip

MAINTAINER=	jonathan.gabris@gmail.com
HOMEPAGE=	ftp://iut-tice.ujf-grenoble.fr/cao/
COMMENT=	Schematic and PCB CAD software
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/kicad-sources-${V}-${S:S/-stable//}
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CMAKE=	yes

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
