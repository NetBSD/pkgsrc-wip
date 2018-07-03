# $NetBSD$

EGG_NAME=	mlstats-0.4
DISTNAME=	MailingListStats-0.4.1
PKGNAME=	${PYPKGPREFIX}--${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=MetricsGrimoire/}
GITHUB_PROJECT=	MailingListStats

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MetricsGrimoire/MailingListStats
COMMENT=	Mailing List Stats is a tool to parse and analyze mail boxes
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.9:../../databases/py-sqlalchemy

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.4.1
USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/mlstats ${WRKSRC}/mlstats${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
