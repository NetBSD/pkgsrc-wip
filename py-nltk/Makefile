# $NetBSD: Makefile,v 1.5 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	nltk-3.0a2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://nltk.org/nltk3-alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nltk.org/
COMMENT=	Natural Language Toolkit (NLTK)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

REPLACE_PYTHON=			nltk/corpus/reader/knbc.py
REPLACE_PYTHON+=		nltk/stem/rslp.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
