# $NetBSD$

GITHUB_PROJECT=	plover
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-4.0.0.dev0
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstenoproject/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openstenoproject/plover/
COMMENT=	Open source stenotype engine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-hidapi-[0-9]*:../../wip/py-hidapi-git
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-Xlib>=0.16:../../x11/py-Xlib
DEPENDS+=	${PYPKGPREFIX}-wxWidgets-[0-9]*:../../x11/py-wxWidgets

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
