# $NetBSD: Makefile,v 1.8 2006/08/19 20:19:59 kristerw Exp $
#

DISTNAME=	muine-0.5.2
PKGREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://muine.gooeylinux.org/
COMMENT=	Simple and intuitive music player for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		intltool

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
.include "../../x11/gtk2-sharp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
