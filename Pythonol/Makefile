# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 19:10:00 mpasternak Exp $
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

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
NO_BUILD=		# defined

TARGET_DIR=		${PREFIX}/${PYSITELIB}/Pythonol
SCRIPTNAME=		${PREFIX}/bin/pythonol

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${TARGET_DIR}
	printf "#!/bin/sh\nexec ${PYTHONBIN} ${PREFIX}/${PYSITELIB}/pythonolui.py" > ${SCRIPTNAME}
	${CHMOD} ${BINMODE} ${SCRIPTNAME}
	${CHOWN} ${BINOWN}:${BINGRP} ${SCRIPTNAME}

.include "../../lang/python/extension.mk"
.include "../..//x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
