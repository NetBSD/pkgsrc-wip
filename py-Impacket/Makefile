# $NetBSD: Makefile,v 1.10 2012/10/06 17:13:25 asau Exp $
#

DISTNAME=		Impacket-0.9.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oss.corest.com/projects/impacket.html
COMMENT=		Collection of Python classes for working with network protocols

PKG_DESTDIR_SUPPORT=	none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
