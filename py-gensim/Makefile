# $NetBSD$

DISTNAME=	gensim-3.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/a0/b4/f4e45875a4cb1c4f6a76d6d07a2981753aab5f135dac2381f625e8807542/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://radimrehurek.com/gensim/
COMMENT=	Python framework for fast Vector Space Modelling
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.2:../../math/py-scipy


USE_LANGUAGES=	c c++

REPLACE_PYTHON+=	gensim/models/word2vec_inner.pyx

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
