# $NetBSD: Makefile,v 1.1.1.1 2011/03/23 09:53:08 jihbed Exp $
#

DISTNAME=	multichain_mcmc-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/m/multichain_mcmc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi.python.org/pypi/multichain_mcmc
COMMENT=	Multichain MCMC framework and algorithmse
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/multichain_mcmc-0.3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
