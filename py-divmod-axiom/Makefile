# $NetBSD: Makefile,v 1.8 2010/07/25 13:40:09 lexort Exp $

AXIOM_VERSION=	0.5.20
DISTNAME=	Axiom-${AXIOM_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-axiom-${AXIOM_VERSION}
PKGREVISION=	1
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=         pkgsrc-wip-users@sourceforge.net
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodAxiom
COMMENT=	An object database implemented on top of SQLite

DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.0:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../wip/py-twisted
DEPENDS+=	${PYPKGPREFIX}-divmod-epsilon>=0.5.6:../../wip/py-divmod-epsilon

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
