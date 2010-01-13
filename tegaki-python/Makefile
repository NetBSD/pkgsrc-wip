# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:17:42 obache Exp $
#

DISTNAME=	tegaki-python-0.3
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Base Python library for the Tegaki project
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-zinnia>=0.05:../../wip/py-zinnia

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	tegaki/engine.py
SUBST_SED.prefix=	-e 's|/usr/local/share|${PREFIX}/share|g'

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
