# $NetBSD$

DISTNAME=	mido-1.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mido/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://mido.readthedocs.io/
COMMENT=	Library for working with MIDI messages and ports.
LICENSE=	mit

WRKSRC=		${WRKDIR}/mido-1.2.9
USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && for b in mido-connect mido-play mido-ports mido-serve; do \
	  ${MV} $$b $$b-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
