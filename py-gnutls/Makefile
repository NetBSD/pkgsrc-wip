# $NetBSD: Makefile,v 1.1.1.1 2004/01/09 17:44:52 minskim Exp $
#

DISTNAME=		python-gnutls-0.2
PKGNAME=		${DISTNAME:S/python/${PYPKGPREFIX}/}
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		security
MASTER_SITES=		http://home.o2w.net/~ivo/python-gnutls/dist/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://home.o2w.net/~ivo/wiki/moin.cgi/PythonGnutls
COMMENT=		Python bindings for GNUTLS

USE_BUILDLINK2=		yes
PYDISTUTILSPKG=		yes
NO_CONFIGURE=		yes

PYTHON_VERSIONS_ACCEPTED= 22 22pth 23 23pth

.include "../../lang/python/extension.mk"
.include "../../security/gnutls/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
