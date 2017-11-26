# $NetBSD: Makefile,v 1.6 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	irco-0.9.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/irco/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/GaretJax/irco
COMMENT=	International Research Collaboration Graphs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.18:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.9.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=0.9.4:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-ftfy>=3.0.4:../../textproc/py-ftfy
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=0.23:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-country>=0.19:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-structlog>=0.3.2:../../sysutils/py-structlog
BROKEN=		needs unpackaged wip/py-tablib-garetjax
#DEPENDS+=	${PYPKGPREFIX}-tablib-garetjax>=0.9.12:../../wip/py-tablib-garetjax
DEPENDS+=	${PYPKGPREFIX}-raven>=4.2.1:../../www/py-raven

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/irco-convert \
		${DESTDIR}${PREFIX}/bin/irco-convert${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/irco-explorer \
		${DESTDIR}${PREFIX}/bin/irco-explorer${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/irco-graph \
		${DESTDIR}${PREFIX}/bin/irco-graph${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/irco-import \
		${DESTDIR}${PREFIX}/bin/irco-import${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/irco-init \
		${DESTDIR}${PREFIX}/bin/irco-init${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/irco-scrape \
		${DESTDIR}${PREFIX}/bin/irco-scrape${PYVERSSUFFIX}
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/irco/explorer/static/fonts/*
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/irco/explorer/static/styles/*.css
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/irco/explorer/templates/*/*.html

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
