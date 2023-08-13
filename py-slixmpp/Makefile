# $NetBSD$

DISTNAME=	slixmpp-1.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slixmpp/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://lab.louiz.org/poezio/slixmpp
COMMENT=	Async Python library for XMPP (aka Jabber)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-aiodns>=1.0:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-asn1>0:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>0:../../security/py-asn1-modules

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
