# $NetBSD: Makefile,v 1.3 2014/02/11 20:47:33 jihbed Exp $
#

DISTNAME=	nightfall-1.70
CATEGORIES=	math
MASTER_SITES=	http://www.la-samhna.de/nightfall/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.hs.uni-hamburg.de/DE/Ins/Per/Wichmann/Nightfall.html
COMMENT=	Application for a producing a best-fit model for a binary star
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnuplot>=4.6.0:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bison perl msgfmt intltool

CONFIGURE_ARGS+=	--with-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
