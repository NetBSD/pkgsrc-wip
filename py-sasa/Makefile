# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	sasa-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sasa/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://code.google.com/p/sasa-tool/
COMMENT=	SAIL/AIL Sentiment Analyzer
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-nltk>=3.0a2:../../wip/py-nltk


USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
