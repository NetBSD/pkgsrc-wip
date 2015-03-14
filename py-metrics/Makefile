# $NetBSD: Makefile,v 1.4 2015/03/14 17:49:21 jihbed Exp $
#

DISTNAME=	pymetrics-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pymetrics/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/pymetrics/
COMMENT=	Metrics for python files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/pymetrics ${WRKSRC}/pymetrics${PYVERSSUFFIX}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
