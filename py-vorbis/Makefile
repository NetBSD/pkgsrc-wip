# $NetBSD: Makefile,v 1.3 2003/11/22 14:18:45 mpasternak Exp $
#

DISTNAME=		pyvorbis-1.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://vorbis.com/
COMMENT=		Vorbis bindings for Python; see vorbis for details

USE_BUILDLINK2=         yes
PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../lang/python/extension.mk"
.include "../../wip/py-ogg/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
