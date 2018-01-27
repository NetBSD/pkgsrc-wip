# $NetBSD: Makefile,v 1.8 2014/01/25 10:45:28 thomasklausner Exp $

DISTNAME=	plucker_parser-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_parser//}
CATEGORIES=	converters www
MASTER_SITES=	http://www.unmetered.org.uk/plkr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.plkr.org/
COMMENT=	Set of tools converting web pages to Plucker format

CONFLICTS=	py*-plucker-[0-9]*


WRKSRC=		${WRKDIR}/${DISTNAME:S/_parser//}
NO_BUILD=	yes

EGDIR=		${PREFIX}/share/doc/py-plucker
CONF_FILES=	${EGDIR}/pluckerrc.sample ${PKG_SYSCONFDIR}/pluckerrc

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	plucker-build.1	\
			PyPlucker/__init__.py PyPlucker/helper/gettext.py
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

REPLACE_PYTHON=	PyPlucker/Spider.py PyPlucker/PluckerDocs.py	\
			PyPlucker/Decode.py
PLIST_SUBST+=	PYSITELIB=${PYSITELIB:Q}

.include "../../lang/python/application.mk"

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/PyPlucker
	${INSTALL_DATA} ${WRKSRC}/PyPlucker/*.py			\
		${PREFIX}/${PYSITELIB}/PyPlucker
.for f in Spider.py PluckerDocs.py Decode.py
	${INSTALL_SCRIPT} ${WRKSRC}/PyPlucker/${f}			\
		${PREFIX}/${PYSITELIB}/PyPlucker
.endfor
	${LN} -sf ${PREFIX}/${PYSITELIB}/PyPlucker/Spider.py		\
		${PREFIX}/bin/plucker-build
	${LN} -sf ${PREFIX}/${PYSITELIB}/PyPlucker/PluckerDocs.py	\
		${PREFIX}/bin/plucker-decode
	${LN} -sf ${PREFIX}/${PYSITELIB}/PyPlucker/Decode.py		\
		${PREFIX}/bin/plucker-dump
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/PyPlucker/helper
	${INSTALL_DATA} ${WRKSRC}/PyPlucker/helper/*.py			\
		${PREFIX}/${PYSITELIB}/PyPlucker/helper
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/${PYSITELIB}/PyPlucker
	${PYTHONBIN} -O ${PYCOMPILEALL} ${PREFIX}/${PYSITELIB}/PyPlucker
	${INSTALL_MAN} ${WRKSRC}/*.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in exclusionlist.txt home.html pluckerrc.sample
	${INSTALL_DATA} ${WRKSRC}/${f} ${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
