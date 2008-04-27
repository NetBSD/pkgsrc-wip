# $NetBSD: Makefile,v 1.11 2008/04/27 09:21:35 thomasklausner Exp $
#

DISTNAME=	muine-0.5.2
PKGREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://muine.gooeylinux.org/
COMMENT=	Simple and intuitive music player for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		intltool

GCONF_SCHEMAS=		muine.schemas

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
