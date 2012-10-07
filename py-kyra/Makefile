# $NetBSD: Makefile,v 1.12 2012/10/07 12:25:13 asau Exp $
#

DISTNAME=		PyKyra-0.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/PyK/k/}
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.alobbs.com/pykyra/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.alobbs.com/modules.php?op=modload&name=pykyra&file=index
COMMENT=		Game development framework for Python

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../wip/kyra/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
