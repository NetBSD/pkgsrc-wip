# $NetBSD: Makefile,v 1.38 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	gdesklets-0.36
PKGNAME=	gDesklets-0.36
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://gdesklets.de/files/
EXTRACT_SUFX=	.tar.bz2
LICENSE=	gnu-gpl-v2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gdesklets.de/
COMMENT=	Advanced architecture for desktop applets


GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config intltool
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE=	gdesklets-core.pc.in
GCONF_SCHEMAS=		gdesklets-display-thumbnail.schemas

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

REPLACE_PYTHON=		gdesklets
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

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


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
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
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
