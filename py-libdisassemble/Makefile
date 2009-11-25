# $NetBSD: Makefile,v 1.1.1.1 2009/11/25 10:37:30 jihbed Exp $
#

DISTNAME=	libdisassemble2.0
PKGNAME=	${PYPKGPREFIX}-libdisassemble-2.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.immunitysec.com/downloads/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.immunitysec.com/resources-freesoftware.shtml
COMMENT=	Python library that will disassemble X86
#LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/libdisassemble
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

REPLACE_PYTHON+=	disassemble.py

PY_PATCHPLIST=	yes

PLIST_SUBST+=	PYDISAM=${PYDISAM}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX} PYPKGPREFIX=${PYPKGPREFIX}

FILES_SUBST+=	PYSITELIB=${PREFIX}/${PYSITELIB}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

TARGET_NAME=	${PREFIX}/${PYSITELIB}/${PYDISAM}

INSTALLATION_DIRS+=	bin share/doc/py-libdisassemble

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disassemble.py \
		${DESTDIR}${PREFIX}/bin/disassemble${PYVERSSUFFIX}
	cd ${WRKSRC}  && pax -rw -pm opcode86.py opcode86.pyc ${DESTDIR}${TARGET_NAME}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/py-libdisassemble

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
