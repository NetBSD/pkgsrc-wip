# $NetBSD: Makefile,v 1.1.1.1 2003/11/22 12:48:37 mpasternak Exp $
#

DISTNAME=		pyvorbis-1.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://vorbis.com/
COMMENT=		Vorbis bindings for Python; see vorbis for details

USE_BUILDLINK2=         yes
PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

DEPENDS+=		${PYPKGPREFIX}-pyogg>=1.3:../../wip/py-ogg

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../audio/libogg/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
