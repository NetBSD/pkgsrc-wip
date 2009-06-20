# $NetBSD: Makefile,v 1.6 2009/06/20 12:54:14 jihbed Exp $
#

DISTNAME=		Fnorb-1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fnorb/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fnorb.sourceforge.net/
COMMENT=		CORBA 2.0 ORB for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
