# $NetBSD: Makefile,v 1.8 2009/07/29 08:43:49 jihbed Exp $
#

DISTNAME=	CVSToys-1.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://twistedmatrix.com/users/acapnotic/wares/code/CVSToys/
COMMENT=	Watch CVS tree changes on web, RSS, list or IRC
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
