# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 10:47:24 mpasternak Exp $
#

DISTNAME=		mmpython-0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mmpython/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mmpython.sourceforge.net/
COMMENT=		Extract text information from mp3, ogg, avi, jpg and more

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
