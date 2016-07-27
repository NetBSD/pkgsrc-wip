# $NetBSD: Makefile,v 1.8 2012/10/06 17:13:26 asau Exp $
#

DISTNAME=	PyOpenAL-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/pyopenal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/oomadness/en/pyopenal/index.html
COMMENT=	Python bindings for audio/openal
#LICENSE=	LICENSE

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes


.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
