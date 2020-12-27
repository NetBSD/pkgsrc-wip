# $NetBSD$

DISTNAME=	crossbar-20.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crossbar/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://crossbar.io/
COMMENT=	Crossbar.io multi-protocol application router for microservices
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-lmdb>=0.94:../../databases/py-lmdb
DEPENDS+=	${PYPKGPREFIX}-automat>=0.8.0:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-bitstring>=3.1.7:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.14.4:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-constantly>=15.1.0:../../devel/py-constantly
DEPENDS+=	${PYPKGPREFIX}-incremental>=17.5.0:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-treq>=0.14.3:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-txaio>=1.0.3:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=5.1.2:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-[0-9]*:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.19.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-hpack>=4.0.0:../../net/py-hpack
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.8.0:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=1.15.0:../../net/py-txtorcon
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-scour>=0.38.2:../../wip/py-scour
DEPENDS+=	${PYPKGPREFIX}-passlib>=0.14.3:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.10.4:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-priority>=1.0.3:../../wip/py-priority
DEPENDS+=	${PYPKGPREFIX}-service_identity>=:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-setproctitle>=1.2:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-testresources>=2.0.1:../../devel/py-testresources
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.7:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-mistune>=0.8.4:../../textproc/py-mistune
#DEPENDS+=	${PYPKGPREFIX}-flatbuffers>=1.12:../../wip/py-flatbuffers
DEPENDS+=	${PYPKGPREFIX}-ubjson>=0.16.1:../../wip/py-ubjson
DEPENDS+=	${PYPKGPREFIX}-trie3>=0.2:../../wip/py-trie3
DEPENDS+=	${PYPKGPREFIX}-hamcrest>=2.0.2:../../wip/py-hamcrest
#DEPENDS+=	${PYPKGPREFIX}-u-msgpack>=2.7.1:../../wip/py-u-msgpack
DEPENDS+=	${PYPKGPREFIX}-snappy>=0.5.3:../../wip/py-snappy
DEPENDS+=	${PYPKGPREFIX}-zlmdb>=20.8.1:../../wip/py-zlmdb
DEPENDS+=	${PYPKGPREFIX}-autobahn>=20.1.2:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hyperlink-[0-9]*:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.23:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=1.0.1:../../www/py-werkzeug

.include "../../math/py-numpy/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
