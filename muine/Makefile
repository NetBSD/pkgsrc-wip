# $NetBSD: Makefile,v 1.5 2005/04/11 21:14:08 tvierling Exp $
#

DISTNAME=	muine-0.5.2
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://muine.gooeylinux.org/
COMMENT=	Simple and intuitive music player for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
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
