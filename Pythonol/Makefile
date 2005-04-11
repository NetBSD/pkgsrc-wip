# $NetBSD: Makefile,v 1.5 2005/04/11 21:09:37 tvierling Exp $
#

DISTNAME=		Pythonol-2.0_i586
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_i586//}
WRKSRC=			${WRKDIR}/Pythonol-Install
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pythonol/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pythonol.sourceforge.net/
COMMENT=		Learn Spanish (with a little help of Python)

DEPENDS=		${PYPKGPREFIX}-sqlite>=0.4.3:../../databases/py-sqlite

PY_PATCHPLIST=		yes

TARGET_DIR=		${PREFIX}/${PYSITELIB}/Pythonol
SCRIPTNAME=		${PREFIX}/bin/pythonol

do-build:
	${RM} -r ${WRKSRC}/sqlite
	${PYTHONBIN} ${WRKSRC}/dictionary/makedb.py

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${TARGET_DIR}
	printf "#!/bin/sh\nexec ${PYTHONBIN} ${TARGET_DIR}/pythonolui.py" > ${SCRIPTNAME}
	${CHMOD} ${BINMODE} ${SCRIPTNAME}
	${CHOWN} ${BINOWN}:${BINGRP} ${SCRIPTNAME}

.include "../../lang/python/extension.mk"
.include "../..//x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
