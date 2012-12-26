# $NetBSD: Makefile,v 1.1 2012/12/26 17:23:34 othyro Exp $
#

DISTNAME=	0.8
PKGNAME=	${PYPKGPREFIX}-logtools
CATEGORIES=	www
MASTER_SITES=	https://github.com/adamhadani/logtools/archive/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamhadani/logtools
COMMENT=	Log files analysis/filtering framework written in Python
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/logtools-${DISTNAME}
USE_LANGUAGES=	# none
USE_TOOLS+=	bash

REPLACE_BASH+=	scripts/*

REPLACE_INTERPRETER+=	env
REPLACE.env.old=	.*bin/env python
REPLACE.env.new=	${PYTHONBIN}
REPLACE_FILES.env=	logtools/__init__.py logtools/_config.py
REPLACE_FILES.env+=	logtools/_filter.py logtools/_filterbots.py
REPLACE_FILES.env+=	logtools/_geoip.py logtools/_join.py logtools/_merge.py
REPLACE_FILES.env+=	logtools/_parse.py logtools/_plot.py logtools/_qps.py
REPLACE_FILES.env+=	logtools/_sample.py logtools/_serve.py
REPLACE_FILES.env+=	logtools/_sumstat.py logtools/_urlparse.py
REPLACE_FILES.env+=	logtools/join_backends.py logtools/parsers.py
REPLACE_FILES.env+=	logtools/test/__init__.py logtools/test/test_logtools.py
REPLACE_FILES.env+=	logtools/utils.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
