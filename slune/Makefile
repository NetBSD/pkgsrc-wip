# $NetBSD: Makefile,v 1.1.1.1 2003/11/22 13:04:28 mpasternak Exp $
#

DISTNAME=		Slune-0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		games
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oomadness.tuxfamily.org/en/slune/index.html
COMMENT=		Action game, featuring cars, races and Tux the Penguin

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth

DEPENDS+=		${PYPKGPREFIX}-Py2Play>=0.1.5:../../wip/py-Py2Play
DEPENDS+=		${PYPKGPREFIX}-Soya>=0.5.1:../../wip/py-Soya
DEPENDS+=		${PYPKGPREFIX}-EditObj>=0.5.2:../../wip/py-EditObj
DEPENDS+=		${PYPKGPREFIX}-pyvorbis>=1.3:../../wip/py-vorbis

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
