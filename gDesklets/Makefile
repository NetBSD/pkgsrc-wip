# $NetBSD: Makefile,v 1.32 2010/12/24 12:55:11 noud4 Exp $
#

DISTNAME=	gdesklets-0.36
PKGNAME=	gDesklets-0.36
CATEGORIES=	x11 gnome
MASTER_SITES=	http://gdesklets.de/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gdesklets.de/
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

SUBST_CLASSES+=		python2
SUBST_MESSAGE.python2=	Fixing Python command name.
SUBST_STAGE.python2=	post-patch
SUBST_FILES.python2=	configure
SUBST_SED.python2=	-e 's|python -c|${PYTHONBIN} -c|g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gdesklets/Displays

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
