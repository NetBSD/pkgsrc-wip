# $NetBSD$

DISTNAME=	git-cola-4.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=git-cola/}
GITHUB_PROJECT=	git-cola
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/git-cola/git-cola/
COMMENT=	Highly caffeinated Git GUI
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-qt5-webengine-[0-9]*:../../x11/py-qt5-webengine
DEPENDS+=	${PYPKGPREFIX}-qtpy-[0-9]*:../../wip/py-qtpy

USE_LANGUAGES=		# none
USE_TOOLS+=		tclsh

SUBST_CLASSES+=		tclsh
SUBST_FILES.tclsh+=	cola/bin/ssh-askpass
SUBST_SED.tclsh+=	-e "s,.*env tclsh,${TCLSH},"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.
SUBST_STAGE.tclsh=	pre-build

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
