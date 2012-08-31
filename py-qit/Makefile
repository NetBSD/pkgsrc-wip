# $NetBSD: Makefile,v 1.1 2012/08/31 18:12:52 jihbed Exp $
#

DISTNAME=	qit-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/q/qit/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qit.sourceforge.net/
COMMENT=	Quantum Information Toolkit
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/qit-0.9.12

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
