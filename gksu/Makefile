# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		gksu-1.3.6
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/gksu/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/gksu/
COMMENT=		Authorization dialog library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

USE_X11=YES

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF_SCHEMAS+=	gksu.schemas

.include "../../mk/x11.buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libgksu/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../wip/libgksuui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
