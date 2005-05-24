# $NetBSD: Makefile,v 1.13 2005/05/24 10:29:52 rillig Exp $

DISTNAME=	gDesklets-0.26
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.pycage.de/download/gdesklets/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gdesklets.gnomedesktop.org/
COMMENT=	Advanced architecture for desktop applets

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
USE_X11=	YES

PKGCONFIG_OVERRIDE=	gdesklets-core.pc.in
GCONF2_SCHEMAS=		gdesklets-display-thumbnail.schemas

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	23 22 21
PYTHON_PATCH_SCRIPTS=		gdesklets

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	"Fixing Python command name."
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	locale/Makefile.in
SUBST_SED.python=	-e 's|python |${PYTHONBIN} |g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gdesklets/Displays

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

# libXau.so is required to build dynamically-linked Python modules.
.include "../../wip/libXau/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
