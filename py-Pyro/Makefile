# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 22:38:26 mpasternak Exp $
#

DISTNAME=		Pyro-3.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyro/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
