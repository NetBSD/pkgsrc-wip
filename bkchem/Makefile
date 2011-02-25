# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:47 thomasklausner Exp $
#

DISTNAME=	bkchem-0.13.0
CATEGORIES=	biology python
MASTER_SITES=	http://bkchem.zirael.org/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bkchem.zirael.org/
COMMENT=	Python based chemical structures editor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24 23
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

PY_EXEC=${PREFIX}/bin/python${PYVERSSUFFIX}
PY_APPAPATH=${PREFIX}/${PYSITELIB}/bkchem/bkchem.py

post-extract:
	    ${CP} ${FILESDIR}/bkchem.desktop ${WRKSRC}
	    ${ECHO} '#!/bin/sh' > ${WRKSRC}/bkchem${PYVERSSUFFIX}
	    ${ECHO} 'echo "Starting Bkchem" ' >> ${WRKSRC}/bkchem${PYVERSSUFFIX}
	    ${ECHO} exec ${PY_EXEC} -OO  ${PY_APPAPATH} >> ${WRKSRC}/bkchem${PYVERSSUFFIX}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-Pmw/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
