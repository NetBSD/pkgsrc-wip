# $NetBSD: Makefile,v 1.1.1.1 2004/01/19 21:33:46 minskim Exp $

DISTNAME=	gDesklets-0.25.1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.pycage.de/download/gdesklets/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://gdesklets.gnomedesktop.org/
COMMENT=	Advanced architecture for desktop applets

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	gdesklets-core.pc.in
GCONF2_SCHEMAS=		gdesklets-display-thumbnail.schemas

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

PYTHON_PATCH_SCRIPTS=	gdesklets

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	"Fixing Python command name."
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	locale/Makefile.in
SUBST_SED.python=	-e 's|python |${PYTHONBIN} |g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gdesklets/Displays

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgtop2/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/py-gnome2/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
