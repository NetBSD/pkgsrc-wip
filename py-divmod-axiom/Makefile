# $NetBSD: Makefile,v 1.18 2015/04/13 23:22:02 othyro Exp $

AXIOM_VERSION=	0.5.20
DISTNAME=	Axiom-${AXIOM_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-axiom-${AXIOM_VERSION}
PKGREVISION=	2
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/

MAINTAINER=	pkgsrc-wip-users@sourceforge.net
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodAxiom
COMMENT=	Object database implemented on top of SQLite

DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.0:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-divmod-epsilon>=0.5.6:../../wip/py-divmod-epsilon

PYDISTUTILSPKG=		yes
REPLACE_PYTHON+=	bin/axiomatic
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-sqlite2, py-twisted

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
