# $NetBSD: Makefile,v 1.1.1.1 2005/02/04 00:42:50 rxg Exp $
#

DISTNAME=		stardict-2.4.4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stardict/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://stardict.sourceforge.net/
COMMENT=		Cross-Platform and international dictionary written in Gtk2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	stardict.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
