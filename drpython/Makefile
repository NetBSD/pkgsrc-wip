# $NetBSD: Makefile,v 1.2 2004/04/25 18:42:07 blef Exp $
#

DISTNAME=		drpython-2.1.9
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=drpython/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://drpython.sourceforge.net/
COMMENT=		Source code editor, written in Python, for Python

USE_BUILDLINK3=		yes
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

.include "../../x11/py-wxWindows/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
