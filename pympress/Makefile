# $NetBSD$

GITHUB_PROJECT=	pympress
GITHUB_TAG=	refs/tags/v1.6.1
DISTNAME=	pympress-1.6.1
PKGNAME=	${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cimbali/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cimbali/pympress/
COMMENT=	PDF presentation tool
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}
PYDISTUTILSPKG=	YES

DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.36.1:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.10.4:../../sysutils/py-watchdog

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
