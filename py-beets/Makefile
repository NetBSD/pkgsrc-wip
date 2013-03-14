# $NetBSD: Makefile,v 1.8 2013/03/14 13:46:10 thomasklausner Exp $
#

DISTNAME=	beets-1.0b15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://beets.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://code.google.com/p/beets/
HOMEPAGE=	http://beets.radbox.org/
COMMENT=	Music geek's media organizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-last-[0-9]*:../../audio/py-last
DEPENDS+=	${PYPKGPREFIX}-munkres-[0-9]*:../../math/py-munkres
DEPENDS+=	${PYPKGPREFIX}-musicbrainz-ngs-[0-9]*:../../audio/py-musicbrainz-ngs
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

USE_LANGUAGES=	# none
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/beet ${DESTDIR}${PREFIX}/bin/beet${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
