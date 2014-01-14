# $NetBSD: Makefile,v 1.1 2014/01/14 21:45:11 jihbed Exp $

DISTNAME=	NetFlowVizu-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/N/NetFlowVizu/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.smallbulb.net/netflowvizu
COMMENT=	Network flow visualizer
LICENSE=  	mit

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

WRKSRC=		${WRKDIR}/NetFlowVizu-0.6
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/net_flow_vizu_dia.py ${WRKSRC}/net_flow_vizu_dia.py${PYVERSSUFFIX}
.include "../../lang/python/egg.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
