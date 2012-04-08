# $NetBSD: Makefile,v 1.4 2012/04/08 19:09:41 thomasklausner Exp $
#

DISTNAME=	bkchem-0.13.0
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://bkchem.zirael.org/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bkchem.zirael.org/
COMMENT=	Python based chemical structures editor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

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
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
