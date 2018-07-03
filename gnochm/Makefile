# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gnochm-0.9.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnochm/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnochm.sourceforge.net/
COMMENT=	CHM file viewer for Gnome2

DEPENDS+=	${PYPKGPREFIX}-chm>=0.8.4:../../wip/py-chm
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.99.12:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gnome2>=1.99.12:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-gnome2-extras>=1.99.12:../../x11/py-gnome2-extras

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

GCONF_SCHEMAS+=	gnochm.schemas

SUBST_CLASSES+=		schema
SUBST_STAGE.schema=	pre-configure
SUBST_MESSAGE.schema=	Fixing schema installation path.
SUBST_FILES.schema+=	data/Makefile.in
SUBST_SED.schema+=	-e "s,..sysconfdir./gconf/schemas,${PREFIX}/share/gconf/schemas/,"

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
