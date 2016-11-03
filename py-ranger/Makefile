# $NetBSD$

DISTNAME=	ranger-1.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://ranger.nongnu.org/

MAINTAINER=	nahra@unseen.is
HOMEPAGE=	http://ranger.nongnu.org/
COMMENT=	VIM-inspired filemanager for the console
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

BUILD_TARGET=	compile

CHECK_PORTABILITY_SKIP+=	examples/rifle_sxiv.sh

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-install
SUBST_MESSAGE.install=	correcting installation path
SUBST_FILES.install=	${WRKSRC}/setup.py
SUBST_SED.install=	-e 's,share/man,man,g'

REPLACE_PYTHON+=	.py	*/*.py	*/*/*.py	*/*/*.py

USE_LANGUAGES=	# none

.include	"../../lang/python/distutils.mk"
.include	"../../lang/python/application.mk"

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
