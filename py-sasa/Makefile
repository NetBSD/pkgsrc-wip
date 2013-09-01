# $NetBSD: Makefile,v 1.1 2013/09/01 18:20:57 jihbed Exp $

DISTNAME=	sasa-0.1.3
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	https://pypi.python.org/packages/source/s/sasa/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://code.google.com/p/sasa-tool/
COMMENT=	SAIL/AIL Sentiment Analyzer
LICENSE=	apache-2.0

DEPENDS+=     ${PYPKGPREFIX}-nltk>=3.0a2:../../wip/py-nltk

FETCH_USING=	curl

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
