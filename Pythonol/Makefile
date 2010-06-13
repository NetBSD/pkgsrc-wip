# $NetBSD: Makefile,v 1.15 2010/06/13 22:46:56 thomasklausner Exp $
#

DISTNAME=		Pythonol-2.0_i586
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_i586//}
WRKSRC=			${WRKDIR}/Pythonol-Install
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pythonol/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.phrozensmoke.com/projects/pythonol/
COMMENT=		Learn Spanish (with a little help of Python)

DEPENDS+=		${PYPKGPREFIX}-sqlite>=0.4.3:../../databases/py-sqlite

PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=		yes

TARGET_DIR=		${PREFIX}/${PYSITELIB}/Pythonol
SCRIPTNAME=		${PREFIX}/bin/pythonol
USE_TOOLS+=		printf pax

do-build:
	${RM} -r ${WRKSRC:Q}/sqlite
	${PYTHONBIN} ${WRKSRC:Q}/dictionary/makedb.py

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	cd ${WRKSRC} && pax -rw -pp * ${TARGET_DIR}
	${PRINTF} "#!/bin/sh\\nexec ${PYTHONBIN} ${TARGET_DIR}/pythonolui.py" > ${SCRIPTNAME}
	${CHMOD} ${BINMODE} ${SCRIPTNAME}
	${CHOWN} ${BINOWN}:${BINGRP} ${SCRIPTNAME}

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
