# $NetBSD: Makefile,v 1.2 2003/11/22 15:14:11 mpasternak Exp $
#

DISTNAME=		Slune-0.5
PKGNAME=		${PYPKGPREFIX}-Slune-0.5
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
DEPENDS+=		${PYPKGPREFIX}-vorbis>=1.3:../../wip/py-vorbis

PYSETUPINSTALLARGS=	--install-lib ${PYSITELIB} --install-scripts ${PREFIX}/bin --install-data ${PREFIX}/share/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
