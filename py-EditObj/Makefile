# $NetBSD: Makefile,v 1.3 2004/05/09 23:40:26 blef Exp $
#

DISTNAME=		EditObj-0.5.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oomadness.tuxfamily.org/en/editobj/
COMMENT=		useful tool for writing (text or non-text) editors of all kinds in Python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
