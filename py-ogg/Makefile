# $NetBSD: Makefile,v 1.2 2003/11/23 13:55:44 mpasternak Exp $
#

DISTNAME=		pyogg-1.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for OGG library.

USE_BUILDLINK2=		yes
PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../audio/libogg/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
