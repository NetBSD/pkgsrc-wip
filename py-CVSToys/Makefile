# $NetBSD: Makefile,v 1.1.1.1 2003/12/25 21:00:24 mpasternak Exp $
#

DISTNAME=		CVSToys-1.0.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
COMMENT=		Watch CVS tree changes on web, RSS, list or IRC

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Twisted-[0-9]*:../../wip/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
