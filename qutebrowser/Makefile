# $NetBSD$

DISTNAME=	qutebrowser-1.4.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=qutebrowser/}
GITHUB_TAG=	v1.4.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qutebrowser.org/
COMMENT=	A keyboard-driven, vim-like browser based on PyQt5
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-PEG2-[0-9]*:../../wip/py-PEG2
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
#DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-cssutils-[0-9]*:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
#DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27 33

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"

.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
