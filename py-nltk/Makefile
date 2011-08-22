# $NetBSD: Makefile,v 1.1.1.1 2011/08/22 12:37:34 thomasklausner Exp $
#

DISTNAME=	nltk-2.0.1rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://nltk.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nltk.org/
COMMENT=	Natural Language Toolkit (NLTK)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes
REPLACE_PYTHON=			nltk/corpus/reader/knbc.py
REPLACE_PYTHON+=		nltk/stem/rslp.py
PYTHON_VERSIONS_INCOMPATIBLE=	24 31

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
