# $NetBSD: Makefile,v 1.3 2004/02/14 23:07:15 minskim Exp $
#

DISTNAME=	pyogg-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	audio
MASTER_SITES=	http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://vorbis.com/
COMMENT=	Python bindings for OGG library.

USE_BUILDLINK3=	yes
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../audio/libogg/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
