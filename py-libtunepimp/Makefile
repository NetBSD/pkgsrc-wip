# $NetBSD: Makefile,v 1.4 2008/05/22 15:38:47 tnn2 Exp $

DISTNAME=	libtunepimp-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio devel
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
                http://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://musicbrainz.org/products/tunepimp/index.html
COMMENT=	Python bindings for TunePimp library.

WRKSRC=		${WRKDIR}/${DISTNAME}/python

PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes

BUILD_DEPENDS+= ${PYPKGPREFIX}-ctypes-[0-9]*:../../devel/py-ctypes
BUILD_DEPENDS+= libtunepimp-[0-9]*:../../audio/libtunepimp

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
