# $NetBSD: Makefile,v 1.1.1.1 2003/12/12 16:08:34 froz Exp $
#

DISTNAME=		pymad-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER= 		froz@icix.org
HOMEPAGE=		http://spacepants.org/src/pymad
COMMENT=		Mad bindings for Python; see libmad description

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../audio/libmad/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
