# $NetBSD: Makefile,v 1.4 2004/07/27 22:09:16 thomasklausner Exp $
#

DISTNAME=		PyKyra-0.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/PyK/k/}
CATEGORIES=		devel
MASTER_SITES=		http://www.alobbs.com/pykyra/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.alobbs.com/modules.php?op=modload&name=pykyra&file=index
COMMENT=		Game development framework for Python

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../wip/kyra/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
