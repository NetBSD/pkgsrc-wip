# $NetBSD: Makefile,v 1.2 2004/05/02 22:10:25 blef Exp $
#

DISTNAME=		Fnorb-1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fnorb/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://fnorb.sourceforge.net/
COMMENT=		CORBA 2.0 ORB for Python

USE_BUILDLINK3=		yes

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
