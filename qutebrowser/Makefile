# $NetBSD: Makefile,v 1.32 2024/11/14 22:22:10 wiz Exp $

DISTNAME=	qutebrowser-3.6.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=qutebrowser/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qutebrowser.org/
COMMENT=	Keyboard-driven, vim-like browser based on PyQt6
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6
DEPENDS+=	${PYPKGPREFIX}-qt6-webengine-[0-9]*:../../wip/py-qt6-webengine
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
