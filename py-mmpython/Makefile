# $NetBSD: Makefile,v 1.2 2004/05/10 01:48:50 blef Exp $
#

DISTNAME=		mmpython-0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mmpython/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mmpython.sourceforge.net/
COMMENT=		Extract text information from mp3, ogg, avi, jpg and more

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
