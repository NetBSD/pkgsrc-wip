# $NetBSD$

DISTNAME=	sylajone-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sylajone/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://sylajone.sourceforge.net/
COMMENT=	Sylajone: Arabic syntax Analyzer library
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-arabic>=0.6.2:../../wip/py-arabic
DEPENDS+=	${PYPKGPREFIX}-pickledb>=0.9.0:../../wip/py-pickledb
DEPENDS+=	${PYPKGPREFIX}-libqutrub>=1.2.4.1:../../wip/py-libqutrub
DEPENDS+=	${PYPKGPREFIX}-naftawayh>=0.4:../../wip/py-naftawayh
DEPENDS+=	${PYPKGPREFIX}-qalsadi>=0.3.5:../../wip/py-qalsadi


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
