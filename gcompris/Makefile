# $NetBSD: Makefile,v 1.4 2004/08/17 18:26:27 tvierling Exp $

DISTNAME=	gcompris-3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ofset.sourceforge.net/gcompris/
COMMENT=	Educational games for children

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/gcompris/libadvanced_colors.la
LIBTOOL_LA_FILES+=	lib/gcompris/libalgebra.la
LIBTOOL_LA_FILES+=	lib/gcompris/libalgebra_guesscount.la
LIBTOOL_LA_FILES+=	lib/gcompris/libcanal_lock.la
LIBTOOL_LA_FILES+=	lib/gcompris/libchess.la
LIBTOOL_LA_FILES+=	lib/gcompris/libclick_on_letter.la
LIBTOOL_LA_FILES+=	lib/gcompris/libclickgame.la
LIBTOOL_LA_FILES+=	lib/gcompris/libclockgame.la
LIBTOOL_LA_FILES+=	lib/gcompris/libcolors.la
LIBTOOL_LA_FILES+=	lib/gcompris/libdraw.la
LIBTOOL_LA_FILES+=	lib/gcompris/libenumerate.la
LIBTOOL_LA_FILES+=	lib/gcompris/liberase.la
LIBTOOL_LA_FILES+=	lib/gcompris/libgletters.la
LIBTOOL_LA_FILES+=	lib/gcompris/libhanoi.la
LIBTOOL_LA_FILES+=	lib/gcompris/libimageid.la
LIBTOOL_LA_FILES+=	lib/gcompris/libleftright.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmachpuzzle.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmaze.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmemory.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmenu.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmissingletter.la
LIBTOOL_LA_FILES+=	lib/gcompris/libmoney.la
LIBTOOL_LA_FILES+=	lib/gcompris/libparatrooper.la
LIBTOOL_LA_FILES+=	lib/gcompris/libplanegame.la
LIBTOOL_LA_FILES+=	lib/gcompris/librailroad.la
LIBTOOL_LA_FILES+=	lib/gcompris/libread_colors.la
LIBTOOL_LA_FILES+=	lib/gcompris/libreading.la
LIBTOOL_LA_FILES+=	lib/gcompris/libreversecount.la
LIBTOOL_LA_FILES+=	lib/gcompris/libshapegame.la
LIBTOOL_LA_FILES+=	lib/gcompris/libsmallnumbers.la
LIBTOOL_LA_FILES+=	lib/gcompris/libsubmarine.la
LIBTOOL_LA_FILES+=	lib/gcompris/libsuperbrain.la
LIBTOOL_LA_FILES+=	lib/gcompris/libtarget.la
LIBTOOL_LA_FILES+=	lib/gcompris/libtraffic.la
LIBTOOL_LA_FILES+=	lib/gcompris/libwordsgame.la
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_TOOLS+=		tar

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
