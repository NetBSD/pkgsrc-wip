# $NetBSD$

DISTNAME=	textual_image-0.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lnqs/textual-image
COMMENT=	Render images in the terminal with Textual and rich
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-rich>=13.4.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-textual>=0.68.0:../../comms/py-textual

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
