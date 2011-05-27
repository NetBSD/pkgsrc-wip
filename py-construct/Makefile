# $NetBSD: Makefile,v 1.2 2011/05/27 03:26:10 schnoebe Exp $
#

DISTNAME=	construct-2.04
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/c/construct/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://pypi.python.org/pypi/construct
COMMENT=	a powerful declarative parser for binary data
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
USE_LANGUAGES+=	c 
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
# MAKE_ENV+=	ATLAS=None

# REPLACE_PYTHON+=	numpy/core/scons_support.py

# SUBST_CLASSES+=	numpy
# SUBST_STAGE.numpy=	post-patch
# SUBST_FILES.numpy=	numpy/f2py/setup.py numpy/f2py/setupscons.py
# SUBST_SED.numpy=	-e 's:/usr/bin/env %s:${PYTHONBIN}:'
# SUBST_SED.numpy+=	-e 's:%(os.path.basename(sys.executable))::'

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

# needs devel/py-nose
#do-test:
#	${PYTHONBIN} -c "import numpy; numpy.test()"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
