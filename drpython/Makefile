# $NetBSD: Makefile,v 1.12 2010/07/23 16:01:31 jihbed Exp $
#

DISTNAME=    DrPython_3.11.2
PKGNAME=    drpython-3.11.2
PKGREVISION=    2
CATEGORIES=    editors
MASTER_SITES=    ${MASTER_SITE_SOURCEFORGE:=drpython/}
EXTRACT_SUFX=    .zip

MAINTAINER=   pkgsrc-users@NetBSD.org
HOMEPAGE=    http://drpython.sourceforge.net/
COMMENT=    Source code editor, written in Python, for Python
LICENSE=    gnu-gpl-v3

PKG_DESTDIR_SUPPORT=    user-destdir

WRKSRC=        ${WRKDIR}/DrPython
USE_LANGUAGES=    # none

PYDISTUTILSPKG=    yes

PY_EXEC=${PREFIX}/bin/python${PYVERSSUFFIX}
PY_APPAPATH=${PREFIX}/${PYSITELIB}/drpython/drpython.py

post-extract:
	     ${CP} ${FILESDIR}/drpython.desktop ${WRKSRC}
	    @${ECHO} '#!/bin/sh' > ${WRKSRC}/drpython${PYVERSSUFFIX}
	    @${ECHO} 'echo "Starting DrPython" ' >> ${WRKSRC}/drpython
	    @${ECHO} exec ${PY_EXEC} -OO  ${PY_APPAPATH} >> ${WRKSRC}/drpython

.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
