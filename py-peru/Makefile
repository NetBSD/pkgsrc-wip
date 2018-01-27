# $NetBSD: Makefile,v 1.1 2015/06/20 17:54:15 jihbed Exp $

DISTNAME=	peru-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peru/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/buildinspace/peru
COMMENT=	Tool for fetching code
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml

USE_TOOLS+=	bash
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	34 35 36

REPLACE_BASH+=		peru/resources/plugins/rsync/rsync_plugin.sh

REPLACE_PYTHON+=	peru/resources/plugins/curl/curl_plugin.py\
			peru/resources/plugins/cp/cp_plugin.py\
			peru/resources/plugins/empty/empty_plugin.py \
			peru/resources/plugins/git/git_plugin.py \
			peru/resources/plugins/hg/hg_plugin.py   \
		    	peru/resources/plugins/noop_cache/noop_cache_plugin.py \
		    	peru/resources/plugins/print/print_plugin.py \
		    	peru/resources/plugins/svn/svn_plugin.py		

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
