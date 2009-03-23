# $NetBSD: Makefile,v 1.1.1.1 2009/03/23 23:07:33 jihbed Exp $
#

DISTNAME=	Aspyct-3-0_beta_3
PKGNAME=	${PYPKGPREFIX}-aspyct-3.0beta3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aspyct/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://aspyct.sourceforge.net/
COMMENT=	Python AOP (aspect oriented programming)

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
