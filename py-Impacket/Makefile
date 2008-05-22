# $NetBSD: Makefile,v 1.8 2008/05/22 15:38:46 tnn2 Exp $
#

DISTNAME=		Impacket-0.9.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oss.corest.com/projects/impacket.html
COMMENT=		Collection of Python classes for working with network protocols

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
