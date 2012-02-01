# $NetBSD: Makefile,v 1.5 2012/02/01 00:04:53 noud4 Exp $

DISTNAME=	libtunepimp-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
                http://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://musicbrainz.org/products/tunepimp/index.html
COMMENT=	Python bindings for TunePimp library.

WRKSRC=		${WRKDIR}/${DISTNAME}/python

PY_PATCHPLIST=	yes
PYDISTUTILSPKG= yes

BUILD_DEPENDS+= libtunepimp-[0-9]*:../../audio/libtunepimp

.include "../../lang/python/extension.mk"
.if ${PYVERSSUFFIX} == "2.4"
BUILD_DEPENDS+= ${PYPKGPREFIX}-ctypes-[0-9]*:../../devel/py-ctypes
.endif
.include "../../mk/bsd.pkg.mk"
