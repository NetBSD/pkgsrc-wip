# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:28 asau Exp $

DISTNAME=	qit-0.9.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qit.sourceforge.net/
COMMENT=	Quantum Information Toolkit
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

WRKSRC=		${WRKDIR}/qit-0.9.12

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
