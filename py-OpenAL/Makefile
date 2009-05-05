# $NetBSD: Makefile,v 1.7 2009/05/05 23:06:01 jihbed Exp $
#

DISTNAME=	PyOpenAL-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/pyopenal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/oomadness/en/pyopenal/index.html
COMMENT=	Python bindings for audio/openal
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes


.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
