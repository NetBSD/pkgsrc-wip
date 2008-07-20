# $NetBSD: Makefile,v 1.3 2008/07/20 18:20:24 phonohawk Exp $
#

DISTNAME=	synfig-0.61.08
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	Vector-based 2D animation renderer

GNU_CONFIGURE=		yes
USE_TOOLS+=			pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	synfig.pc.in

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../wip/ETL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
