# $NetBSD$

DISTNAME=	autokey-0.90.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/autokey/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/autokey/
COMMENT=	Desktop automation utility
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.90.4

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
