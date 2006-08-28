# $NetBSD: Makefile,v 1.2 2006/08/28 18:55:16 milosn Exp $

AXIOM_VERSION=	0.5.0
DISTNAME=	Axiom-${AXIOM_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-axiom-${AXIOM_VERSION}
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodAxiom
COMMENT=	An object database implemented on top of SQLite

DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.0:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-twisted-core>=2.4.0:../../wip/py-twisted-core
DEPENDS+=	${PYPKGPREFIX}-divmod-epsilon>=0.5.0:../../wip/py-divmod-epsilon

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=       24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
