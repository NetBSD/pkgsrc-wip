# $NetBSD: Makefile,v 1.5 2005/07/27 16:25:24 thomasklausner Exp $
#

DISTNAME=		drpython-2.1.9
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=drpython/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://drpython.sourceforge.net/
COMMENT=		Source code editor, written in Python, for Python

NO_CONFIGURE=
NO_BUILD=

DRPYTHON_DIR=		share/drpython
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PYTHON_PATCH_SCRIPTS=	drpython.py

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DRPYTHON_DIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe [a-z]* ${PREFIX}/${DRPYTHON_DIR}
	cd ${PREFIX} && ${FIND} ${DRPYTHON_DIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${DRPYTHON_DIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}
	${LN} -s ${PREFIX}/${DRPYTHON_DIR}/drpython.py ${PREFIX}/bin

.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
