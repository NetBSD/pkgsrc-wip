# $NetBSD$

DISTNAME=	aioxmpp-0.11.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     net devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aioxmpp/}

MAINTAINER=     kamelderouiche@yahoo.com
HOMEPAGE=       https://github.com/horazont/aioxmpp
COMMENT=        Pure-python XMPP library for asyncio
LICENSE=        gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-multidict>=4.7.6:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-babel>=2.8.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-dnspython>=2.0.0:../../wip/py-dns
DEPENDS+=       ${PYPKGPREFIX}-asn1>=0.4.8:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=19.1.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=2.1:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-sortedcollections>=1.2.1:../../wip/py-sortedcollections
DEPENDS+=	${PYPKGPREFIX}-aioopenssl>=0.5.1:../../wip/py-aioopenssl
DEPENDS+=	${PYPKGPREFIX}-aiosasl>=0.4.1:../../wip/py-aiosasl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
