# $NetBSD: Makefile,v 1.10 2014/06/22 19:54:49 thomasklausner Exp $

DISTNAME=	qutrub-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://qutrub.arabeyes.org/index
COMMENT=	Qutrub is an Arabic verb conjugator
LICENSE=	gnu-gpl-v2

DEPENDS+=	${APACHE_PKG_PREFIX}-${PYPKGPREFIX}-python>=3.3.1:../../www/ap2-python

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

QUTRUB_FILES=	ar_ctype.py arabic_const.py classverb.py mosaref_main.py  conjugate.py conjugatedisplay.py  index.py verb_const.py

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-sqlite2
PY_EXEC=	${PREFIX}/bin/python${PYVERSSUFFIX}
QUTRUBDIR=	${PREFIX}/${PYSITELIB}/py-qutrub

INSTALLATION_DIRS=	bin ${QUTRUBDIR}

do-build:
	    printf "#! ${SH}\\nexec  ${PY_EXEC} -OO ${QUTRUBDIR}/conjugate.py  \"\$$@\"\\n" >> ${WRKSRC}/qutrub.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qutrub.sh ${DESTDIR}${PREFIX}/bin/qutrub
	for a in ${QUTRUB_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${QUTRUBDIR}/$$a; \
	done
	cd ${WRKSRC}/data && pax -rw -pp . ${DESTDIR}${QUTRUBDIR}/data
	cd ${WRKSRC}/styles && pax -rw -pp . ${DESTDIR}${QUTRUBDIR}/styles
	cd ${WRKSRC}/images && pax -rw -pp . ${DESTDIR}${QUTRUBDIR}/images
	cd ${WRKSRC}/templates && pax -rw -pp . ${DESTDIR}${QUTRUBDIR}/templates

.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
