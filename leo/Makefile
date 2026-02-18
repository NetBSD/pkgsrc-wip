# $NetBSD$

DISTNAME=	leo-editor-6.8.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/editor-//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=leo-editor/}
GITHUB_PROJECT=	leo-editor
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	https://leo-editor.github.io/leo-editor/
COMMENT=	Programmer's editor and a flexible browser

WRKSRC=		${WRKDIR}/${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.3.9:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
