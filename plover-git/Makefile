# $NetBSD$

PKGNAME=	plover-3.0.0
CATEGORIES=	inputmethod

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openstenoproject/plover/
COMMENT=	Open source stenotype engine
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	plover
GIT_REPO.plover=	https://github.com/openstenoproject/plover.git

WRKSRC=		${WRKDIR}/plover
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-hidapi-[0-9]*:../../wip/py-hidapi-git
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-Xlib>=0.15:../../x11/py-Xlib

#TODO: Should the following line be a DEPENDS line? yes
#.include "../../wip/py-wxWidgets/buildlink3.mk"

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
