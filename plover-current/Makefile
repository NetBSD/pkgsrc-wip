# $NetBSD$

PKGNAME=	plover-3.0.0
CATEGORIES=	inputmethod

GIT_REPOSITORIES=	plover
GIT_REPO.plover=	https://github.com/openstenoproject/plover.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openstenoproject/plover/
COMMENT=	Open source stenotype engine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/plover
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../wip/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-hidapi-[0-9]*:../../wip/py-hidapi
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
# XXX at least 0.15 required.
DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../wip/py-Xlib

#TODO: Should the following line be a DEPENDS line?
#.include "../../wip/py-wxWidgets/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
