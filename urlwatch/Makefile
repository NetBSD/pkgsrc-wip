# $NetBSD: Makefile,v 1.1 2015/08/18 18:36:32 yhardy Exp $

DISTNAME=	urlwatch-1.18
CATEGORIES=	net
MASTER_SITES=	http://thp.io/2008/urlwatch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thp.io/2008/urlwatch/
COMMENT=	Watch web pages and arbitrary URLs for changes
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	YES
# needs futures
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	cd ${WRKSRC} && ${MV} share/man man

post-patch:
	cd ${WRKSRC} && ${TOOLS_PLATFORM.env} PYVERSSUFFIX=${PYVERSSUFFIX} ${SH} convert-to-python3.sh

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
