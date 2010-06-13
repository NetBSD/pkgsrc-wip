# $NetBSD: Makefile,v 1.30 2010/06/13 22:47:04 thomasklausner Exp $

DISTNAME=	gDesklets-0.26
PKGREVISION=	5
CATEGORIES=	x11 gnome
MASTER_SITES=	http://www.pycage.de/download/gdesklets/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gdesklets.org/
COMMENT=	Advanced architecture for desktop applets

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config intltool
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	gdesklets-core.pc.in
GCONF_SCHEMAS=		gdesklets-display-thumbnail.schemas

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=		gdesklets

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing Python command name.
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	locale/Makefile.in
SUBST_SED.python=	-e 's|python |${PYTHONBIN} |g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gdesklets/Displays

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
