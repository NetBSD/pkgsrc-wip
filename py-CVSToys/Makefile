# $NetBSD: Makefile,v 1.3 2004/08/02 20:10:32 minskim Exp $
#

DISTNAME=		CVSToys-1.0.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
COMMENT=		Watch CVS tree changes on web, RSS, list or IRC

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
