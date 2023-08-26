# $NetBSD: Makefile,v 1.57 2023/01/29 21:16:48 ryoon Exp $

VERSION=	20230823
DISTNAME=	chirp-${VERSION}
CATEGORIES=	ham
MASTER_SITES=	https://trac.chirp.danplanet.com/chirp_next/next-${VERSION}/
# Chirp does not have what would normally called releasees.  They have
# "daily builds" which are like releases except that:
#   they are called chirp-daily instead of chirp
#   they have YYYYMMDD version numbers
#   they don't have the usual release testing
#   the python3 version is chirp-next (which is also daily)
# Upstream says
#    they will not go back to regular version numbers
#    the preferred name is chirp, not chirp-daily
# via
#   https://chirp.danplanet.com/issues/8067
#   https://chirp.danplanet.com/news/15

MAINTAINER+=	gdt@NetBSD.org
#MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://chirp.danplanet.com/
COMMENT=	Tool for programming Amateur Radio HTs
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-wxPython>=4:../../x11/py-wxPython

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.4.0:../../devel/py-importlib-resources
.endif
# py-yattag

.include "../../mk/bsd.prefs.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
