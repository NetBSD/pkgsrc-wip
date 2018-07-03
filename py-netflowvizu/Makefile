# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	NetFlowVizu-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=N/NetFlowVizu/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.smallbulb.net/netflowvizu
COMMENT=	Network flow visualizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-xml

post-extract:
	${MV} ${WRKSRC}/net_flow_vizu_dia.py ${WRKSRC}/net_flow_vizu_dia.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
