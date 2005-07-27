# $NetBSD: Makefile,v 1.6 2005/07/27 16:27:05 thomasklausner Exp $
#

DISTNAME=		CVSToys-1.0.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
COMMENT=		Watch CVS tree changes on web, RSS, list or IRC

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
