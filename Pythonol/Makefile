# $NetBSD: Makefile,v 1.20 2014/05/09 07:38:42 thomasklausner Exp $

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


PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

TARGET_DIR=		${PREFIX}/${PYSITELIB}/Pythonol
SCRIPTNAME=		${PREFIX}/bin/pythonol
USE_TOOLS+=		printf pax

do-build:
	${RM} -r ${WRKSRC}/sqlite
	${PYTHONBIN} ${WRKSRC}/dictionary/makedb.py

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	cd ${WRKSRC} && pax -rw -pp * ${TARGET_DIR}
	${PRINTF} "#!/bin/sh\\nexec ${PYTHONBIN} ${TARGET_DIR}/pythonolui.py" > ${SCRIPTNAME}
	${CHMOD} ${BINMODE} ${SCRIPTNAME}
	${CHOWN} ${BINOWN}:${BINGRP} ${SCRIPTNAME}

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
