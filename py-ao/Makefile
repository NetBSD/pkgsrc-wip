# $NetBSD: Makefile,v 1.2 2004/02/15 21:40:17 minskim Exp $
#

DISTNAME=		pyao-0.81
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://vorbis.com/
COMMENT=		Libao bindings for Python; see libao description

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} config_unix.py --prefix ${PREFIX}

.include "../../audio/libao/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
