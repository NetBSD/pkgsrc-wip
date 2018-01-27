# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:38 asau Exp $
#

DISTNAME=		gnubg
CATEGORIES=		games

MAINTAINER=		pho@cielonegro.org
COMMENT=		GNU Backgammon is for playing and analysing backgammon positions
HOMEPAGE=		http://gnubg.org/
LICENSE=		gnu-gpl-v3

CVS_REPOSITORIES=	gnubg
CVS_ROOT.gnubg=		${CVS_ROOT_GNU}/gnubg
CVS_MODULE.gnubg=	gnubg

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake autoconf bison flex gmake pkg-config

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../wip/mk/cvs-package.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
