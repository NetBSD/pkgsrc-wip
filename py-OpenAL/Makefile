# $NetBSD: Makefile,v 1.4 2005/07/27 16:27:27 thomasklausner Exp $
#

DISTNAME=		PyOpenAL-0.1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		audio
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oomadness.tuxfamily.org/en/pyopenal/index.html
COMMENT=		Python bindings for audio/openal; see openal package for details

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../audio/openal/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
