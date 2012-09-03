# $NetBSD: Makefile,v 1.1 2012/09/03 23:13:26 jihbed Exp $
#

DISTNAME=	nightfall-1.70
CATEGORIES=	math
MASTER_SITES=	http://www.la-samhna.de/nightfall/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.hs.uni-hamburg.de/DE/Ins/Per/Wichmann/Nightfall.html
COMMENT=	Application for a producing a best-fit model for a binary star
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnuplot>=4.6.0:../../graphics/gnuplot

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	bison perl msgfmt intltool

CONFIGURE_ARGS+=	--with-included-gettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
