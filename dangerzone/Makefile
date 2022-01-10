# $NetBSD$

DISTNAME=	dangerzone-0.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=firstlookmedia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dangerzone.rocks/
COMMENT=	Convert PDFs to safe PDFs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
#DEPENDS+=	${PYPKGPREFIX}-PySide2-[0-9]*:../../x11/py-PySide2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
