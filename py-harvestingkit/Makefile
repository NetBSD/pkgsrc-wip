# $NetBSD$

DISTNAME=	HarvestingKit-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/36/59/74a881858b0c7e4c98b7f609c824cf2139cb630e90bed506e01e3e316fe3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/inspirehep/harvesting-kit
COMMENT=	Kit of tools to convert publisher XML(NLM/JATS)to MARCXML
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-argcomplete>=0.8.0:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-requests>=2.10.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.6.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.9:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-htmlparser>=0.0.2:../../wip/py-htmlparser
DEPENDS+=	${PYPKGPREFIX}-httpretty>=0.8.14:../../wip/py-httpretty
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3.2:../../www/py-beautifulsoup4

WRKSRC=		${WRKDIR}/HarvestingKit-0.6.6

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
