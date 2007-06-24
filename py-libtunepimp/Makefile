# $NetBSD: Makefile,v 1.3 2007/06/24 06:34:48 thomasklausner Exp $

DISTNAME=	libtunepimp-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio devel
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
                http://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://musicbrainz.org/products/tunepimp/index.html
COMMENT=	Python bindings for TunePimp library.

WRKSRC=		${WRKDIR}/${DISTNAME}/python

PYTHON_VERSIONS_ACCEPTED=	24 23
PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes

BUILD_DEPENDS+= ${PYPKGPREFIX}-ctypes-[0-9]*:../../devel/py-ctypes
BUILD_DEPENDS+= libtunepimp-[0-9]*:../../audio/libtunepimp

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
