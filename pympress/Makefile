# $NetBSD$

DISTNAME=	pympress-1.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cimbali/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cimbali/pympress/
COMMENT=	PDF presentation tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.36.1:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.10.4:../../sysutils/py-watchdog

WRKSRC=		${WRKDIR}/${DISTNAME}

# icon and desktop file
PYTHON_SELF_CONFLICT=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pympress pympress-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
