# $NetBSD: Makefile,v 1.2 2004/05/02 21:16:24 blef Exp $
#

DISTNAME=		PyStem-1.0.4
PKGNAME=		${PYPKGPREFIX}-stem-1.0.4
CATEGORIES=		devel
MASTER_SITES=		http://www.alobbs.com//pystem/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.alobbs.com//pystem/
COMMENT=		Binding of the Porter stemming algorithm to Python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		# defined
# How the heck do I get Python include directory?!
CFLAGS+=		-I. -I${PREFIX}/include/python${PYVERSSUFFIX}

PY_STEM_FILES=		stem py-c-stem stopwords stoplist

do-build:
	for a in ${PY_STEM_FILES}; do \
		( cd ${WRKSRC} && ${CC} ${CFLAGS} -c $$a.c ); \
	done
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o _pyStem.so *.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/_pyStem.so ${PREFIX}/${PYSITELIB}/_pyStem.so
	${INSTALL_DATA} ${WRKSRC}/Stem.py ${PREFIX}/${PYSITELIB}/Stem.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
