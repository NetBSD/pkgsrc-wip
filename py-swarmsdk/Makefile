# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:41:36 jihbed Exp $
#

DISTNAME=	pyswarmsdk-0.7.1-sdist-20070501
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//S/-sdist-20070501//}
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyswarm/pyswarmSDK-unstable/0.7.1/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyswarm.sourceforge.net/
COMMENT=	Model-driven development of Python applications
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-PgSQL>=2.4:../../databases/py-PgSQL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE= 22 21 20 15

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
