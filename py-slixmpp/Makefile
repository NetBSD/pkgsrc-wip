# $NetBSD$

DISTNAME=	slixmpp-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python # TODO: add primary category
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slixmpp/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://codeberg.org/poezio/slixmpp
COMMENT=	Async Python library for XMPP (aka Jabber)
LICENSE=	mit

.include "../../devel/py-maturin/tool.mk"

DEPENDS+=	${PYPKGPREFIX}-aiodns>=3.2.0:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.6.1:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.4.1:../../security/py-asn1-modules

# \todo Consider optional dependencies.

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
