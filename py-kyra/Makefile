# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 06:32:15 mpasternak Exp $
#

DISTNAME=		PyKyra-0.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/PyK/k/}
CATEGORIES=		devel
MASTER_SITES=		http://www.alobbs.com/pykyra/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.alobbs.com/modules.php?op=modload&name=pykyra&file=index
COMMENT=		Game development framework for Python

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../wip/kyra/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
