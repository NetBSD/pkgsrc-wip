# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:50 thomasklausner Exp $

DISTNAME=	pyswarmsdk-0.7.1-sdist-20070501
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//S/-sdist-20070501//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyswarm/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyswarm.sourceforge.net/
COMMENT=	Model-driven development of Python applications
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-PgSQL>=2.4:../../databases/py-PgSQL

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-mxDateTime

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/pyswarm/pyswarm-copy.py ${WRKSRC}/pyswarm/pyswarm-copy${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-edit.py ${WRKSRC}//pyswarm/pyswarm-edit${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-generate.py ${WRKSRC}//pyswarm/pyswarm-generate${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-new.py ${WRKSRC}/pyswarm/pyswarm-new${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-sdk-edit.py ${WRKSRC}/pyswarm/pyswarm-sdk-edit${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-view.py ${WRKSRC}/pyswarm/pyswarm-view${PYVERSSUFFIX}
	${MV} ${WRKSRC}/pyswarm/pyswarm-sdk-view.py ${WRKSRC}/pyswarm/pyswarm-sdk-view${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
