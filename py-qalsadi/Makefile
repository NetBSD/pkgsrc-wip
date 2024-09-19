# $NetBSD$

DISTNAME=	qalsadi-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qalsadi/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/qalsadi
COMMENT=	Qalsadi Arabic Morpholoc=gical Analyzer for Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-alyahmor>=0.1:../../wip/py-alyahmor
DEPENDS+=	${PYPKGPREFIX}-arabic-stopwords>=0.3:../../wip/py-arabic-stopwords
DEPENDS+=	${PYPKGPREFIX}-arramooz-sqlite>=0.1:../../wip/py-arramooz-sqlite
DEPENDS+=	${PYPKGPREFIX}-naftawayh>=0.1:../../wip/py-naftawayh
DEPENDS+=	${PYPKGPREFIX}-libqutrub>=1.0:../../wip/py-libqutrub
DEPENDS+=	${PYPKGPREFIX}-arabic>=0.6.10:../../wip/py-arabic
DEPENDS+=	${PYPKGPREFIX}-pickleDB>=0.9.2:../../wip/py-pickleDB
DEPENDS+=	${PYPKGPREFIX}-tashaphyne>=0.3.4.1:../../wip/py-tashaphyne

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
