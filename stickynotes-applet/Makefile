# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 09:11:07 xtraeme Exp $
#

DISTNAME=	stickynotes_applet-1.2.0
PKGNAME=	${DISTNAME:S/es_/es-/}
CATEGORIES=	misc gnome2
MASTER_SITES=	http://loban.caltech.edu/stickynotes/packages/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://loban.caltech.edu/stickynotes/
COMMENT=	Applet that adds sticky notes to your desktop

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	stickynotes.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
