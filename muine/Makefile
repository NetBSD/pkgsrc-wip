# $NetBSD: Makefile,v 1.3 2004/08/17 18:31:14 tvierling Exp $
#

DISTNAME=	muine-0.5.2
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://muine.gooeylinux.org/
COMMENT=	Simple and intuitive music player for GNOME

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/muine/libmuine.la
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS=		muine.schemas

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../wip/gtk-sharp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
