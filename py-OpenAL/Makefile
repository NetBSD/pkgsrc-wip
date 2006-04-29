# $NetBSD: Makefile,v 1.5 2006/04/29 17:43:16 shattered Exp $
#

DISTNAME=		PyOpenAL-0.1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=		audio
MASTER_SITES=		http://download.gna.org/pyopenal/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://home.gna.org/oomadness/en/pyopenal/index.html
COMMENT=		Python bindings for audio/openal; see openal package for details

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../audio/openal/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
