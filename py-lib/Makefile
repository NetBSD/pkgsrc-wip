# $NetBSD: Makefile,v 1.10 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	py-1.0.2
PKGNAME=	${PYPKGPREFIX}-lib-1.0.2
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py/}
EXTRACT_SUFX=	.tar.gz#md5=d64444015bac78e0c73ac285f9423750

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylib.org/
COMMENT=	Agile development and test support library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-docutils
REPLACE_PYTHON+=		py/cmdline/pycleanup.py
REPLACE_PYTHON+=		py/cmdline/pycountloc.py
REPLACE_PYTHON+=		py/cmdline/pylookup.py
REPLACE_PYTHON+=		py/cmdline/pyrest.py
REPLACE_PYTHON+=		py/cmdline/pysvnwcrevert.py
REPLACE_PYTHON+=		py/cmdline/pytest.py
REPLACE_PYTHON+=		py/cmdline/pywhich.py
REPLACE_PYTHON+=		py/compat/testing/test_optparse.py
REPLACE_PYTHON+=		py/env.py
REPLACE_PYTHON+=		py/execnet/script/shell.py
REPLACE_PYTHON+=		py/execnet/script/socketserver.py
REPLACE_PYTHON+=		py/misc/cmdline/countloc.py
REPLACE_PYTHON+=		py/misc/findmissingdocstrings.py
REPLACE_PYTHON+=		py/bin/_findpy.py
REPLACE_PYTHON+=		py/bin/py.cleanup
REPLACE_PYTHON+=		py/bin/py.countloc
REPLACE_PYTHON+=		py/bin/py.lookup
REPLACE_PYTHON+=		py/bin/py.rest
REPLACE_PYTHON+=		py/bin/py.svnwcrevert
REPLACE_PYTHON+=		py/bin/py.test
REPLACE_PYTHON+=		py/bin/py.which

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
