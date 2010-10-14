# $NetBSD: Makefile,v 1.1.1.1 2010/10/14 18:58:23 cheusov Exp $
#

DISTNAME=	anki-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://anki.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://ichi2.net/anki/
COMMENT=	Flashcard learning program
LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-simplejson>=1.7.3:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.4.3:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=1.3:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

REPLACE_PYTHON=		anki

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

do-build:
	set -e; cd ${WRKSRC}/libanki; \
	${PYTHONBIN} setup.py build; cd ..; \
	${PYTHONBIN} setup.py build

do-install:
	set -e; cd ${WRKSRC}/libanki; \
	${PYTHONBIN} setup.py install --skip-build --root ${DESTDIR} --prefix ${PREFIX}; \
	cd ..; \
	${PYTHONBIN} setup.py install --skip-build --root ${DESTDIR} --prefix ${PREFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
