# $NetBSD: Makefile,v 1.6 2004/01/25 02:22:49 grantbeattie Exp $
#

DISTNAME=	gnome-pkgview-1.0.0
PKGNAME=	${DISTNAME:S/gnome/gnome2/}
CATEGORIES=	sysutils gnome2
MASTER_SITES=	http://www.greatnorthern.demon.co.uk/packages/gnome-pkgview/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.greatnorthern.demon.co.uk/gnome-pkgview.html
COMMENT=	Displays the version of GNOME components installed

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

CONFIGURE_ARGS=		--with-gconf-schema-file-dir=${GCONF_SCHEMA_FILE_DIR}

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	gnome-pkgview.schemas
GCONF2_SCHEMAS+=	gnome-pkgview.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
