# $NetBSD: Makefile,v 1.14 2010/06/13 22:47:16 thomasklausner Exp $
#

DISTNAME=		stardict-3.0.1
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stardict/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://stardict.sourceforge.net/
COMMENT=		Cross-Platform and international dictionary written in Gtk2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

LICENSE=		gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config msgfmt
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--disable-spell --disable-gucharmap --disable-festival
CONFIGURE_ARGS+=	--disable-espeak

#CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
#MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

#GCONF_SCHEMAS+=	stardict.schemas

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../devel/GConf/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
