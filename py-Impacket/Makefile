# $NetBSD: Makefile,v 1.3 2004/05/02 22:12:28 blef Exp $
#

DISTNAME=		Impacket-0.9.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oss.corest.com/projects/impacket.html
COMMENT=		Collection of Python classes for working with network protocols

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22 23pth 22pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
