# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	revelation-0.4.14
CATEGORIES=	security
MASTER_SITES=	https://bitbucket.org/erikg/revelation/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://revelation.olasagasti.info/
COMMENT=	Password manager for the GNOME desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-cracklib-[0-9]*:../../wip/py-cracklib

GNU_CONFIGURE=			yes
USE_LANGUAGES=			c
USE_TOOLS+=			gmake intltool pkg-config
CONFIGURE_ARGS+=		GCONFTOOL=${GCONFTOOL2}
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

GCONF_SCHEMAS=	revelation.schemas

REPLACE_PYTHON=		src/bundle/PBKDFv2.py
REPLACE_PYTHON+=	src/lib/PBKDF2.py
REPLACE_PYTHON+=	src/revelation.py

.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
