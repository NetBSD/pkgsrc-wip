# $NetBSD$

GITHUB_PROJECT=	MailingListStats
EGG_NAME=	mlstats-0.4
DISTNAME=	0.4.1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT:tl}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=MetricsGrimoire/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MetricsGrimoire/MailingListStats
COMMENT=	Mailing List Stats is a tool to parse and analyze mail boxes
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.9:../../databases/py-sqlalchemy

WRKSRC=		${WRKDIR}/MailingListStats-0.4.1

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/mlstats ${WRKSRC}/mlstats${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
