# $NetBSD: Makefile,v 1.6 2011/12/15 15:45:14 jihbed Exp $
#

DISTNAME=	pylast-0.4.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	audio python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylast/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pylast/
COMMENT=	Python interface to Last.fm
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pylast-0.4.26
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
