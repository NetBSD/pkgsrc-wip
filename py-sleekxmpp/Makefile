# $NetBSD$

DISTNAME=	sleekxmpp-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sleekxmpp/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/fritzy/SleekXMPP
COMMENT=	SleekXMPP is an elegant Python library for XMPP
LICENSE=	mit


do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testall.py

.include "../../lang/python/egg.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
