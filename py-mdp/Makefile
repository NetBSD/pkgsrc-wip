# $NetBSD: Makefile,v 1.3 2010/07/23 16:19:53 jihbed Exp $
#

DISTNAME=	MDP-2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/MDP/mdp/}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/mdp-toolkit/mdp-toolkit/2.6/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mdp-toolkit.sourceforge.net/index.html
COMMENT=	Modular toolkit for data processing
LICENSE=	gnu-lgpl-v2

#DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-pp>=1.6.0:../../wip/py-pp
DEPENDS+=	${PYPKGPREFIX}-symeig>=1.5:../../wip/py-symeig

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
