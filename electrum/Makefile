# $NetBSD: Makefile,v 1.10 2015/04/13 23:22:01 othyro Exp $

VERSION=	3.3.8
DISTNAME=	Electrum-${VERSION}
PKGNAME=	electrum-${VERSION}
CATEGORIES=	finance
MASTER_SITES=	https://download.electrum.org/${VERSION}/

MAINTAINER=	js-pkgsrc@nil.im
HOMEPAGE=	https://electrum.org/
COMMENT=	Electrum is an easy to use Bitcoin client
LICENSE=	gnu-gpl-v3

NO_BUILD=			yes
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	36 37 38

# Ordered the same as in contrib/requirements.txt
DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-qrcode-[0-9]*:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-protobuf-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-jsonrpclib-pelix-[0-9]*:../../wip/py-jsonrpclib-pelix
# Seems to work without qdarkstyle? Commented out as it's currently not packaged
#DEPENDS+=	${PYPKGPREFIX}-qdarkstyle-[0-9]*:../../
DEPENDS+=	${PYPKGPREFIX}-aiorpcx<0.19:../../wip/py-aiorpcx
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.3.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks-[0-9]*:../../wip/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi

REPLACE_PYTHON+=	lib/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
