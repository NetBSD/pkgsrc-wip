# $NetBSD: Makefile,v 1.6 2005/07/27 16:27:26 thomasklausner Exp $
#

DISTNAME=		Impacket-0.9.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oss.corest.com/projects/impacket.html
COMMENT=		Collection of Python classes for working with network protocols

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
