# $NetBSD: Makefile,v 1.13 2013/01/01 00:57:33 othyro Exp $
#

DISTNAME=	PyKyra-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyK/k/1}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.alobbs.com/pykyra-stuff/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alobbs.com/pykyra/
COMMENT=	Game development framework for Python
LICENSE=	gnu-gpl-v2


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../wip/kyra2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
