# $NetBSD: Makefile,v 1.5 2011/03/21 16:43:49 phonohawk Exp $
#

DISTNAME=	synfig-0.62.02
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	Vector-based 2D animation renderer
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=			pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	synfig.pc.in

.include "options.mk"

.include "../../devel/ETL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
