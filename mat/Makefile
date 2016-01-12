# $NetBSD$

DISTNAME=	mat-0.6.1
CATEGORIES=	graphics
MASTER_SITES=	https://mat.boum.org/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mat.boum.org/
COMMENT=	Metadata Anonymisation Toolkit
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	intltool

BUILD_DEPENDS+=	${PYPKGPREFIX}-distutils-extra-[0-9]*:../../wip/py-distutils-extra

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-pdfrw-[0-9]*:../../wip/py-pdfrw

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-patch
SUBST_MESSAGE.setup=	Fixing hardcoded paths in setup.py
SUBST_FILES.setup=	setup.py
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},g'

PYTHON_VERSIONS_INCOMPATIBLE=	35	# py-pdfrw

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
