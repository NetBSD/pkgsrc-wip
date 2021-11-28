# $NetBSD$

DISTNAME=	gtg-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	editors

MASTER_SITES=	${MASTER_SITE_GITHUB:=getting-things-gnome/}
MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getting-things-gnome/gtg/
COMMENT=	Personal organizer for GNOME
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=		yes

REPLACE_PYTHON+=	GTG/gtg.in
REPLACE_PYTHON+=	GTG/core/networkmanager.py

DEPENDS+=	${PYPKGPREFIX}-liblarch-[0-9]*:../../wip/py-liblarch

.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
