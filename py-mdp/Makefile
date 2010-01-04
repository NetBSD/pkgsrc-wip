# $NetBSD: Makefile,v 1.2 2010/01/04 23:56:59 jihbed Exp $
#

DISTNAME=	MDP-2.5
PKGNAME=	${PYPKGPREFIX}-mdp-2.5
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/mdp-toolkit/mdp-toolkit/2.5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mdp-toolkit.sourceforge.net/index.html
COMMENT=	Modular toolkit for data processing
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pp>=1.5.7:../../wip/py-pp

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
