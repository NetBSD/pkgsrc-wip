# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 18:31:48 mpasternak Exp $
#

DISTNAME=		PyBabelPhish-2.0_All_Platforms
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_All_Platforms//}
WRKSRC=			${WRKDIR}/PyBabelPhish-Install
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pythonol/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pythonol.sourceforge.net/
COMMENT=		Gtk-based frontend for several translation services on web

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
NO_BUILD=		# defined

PYFILES=	URLRead.py pybabelfish.py pyfilter.py pytheme.py \
		pythonol_festival.py symbolbar.py
	
TARGET_DIR=	${PREFIX}/${PYSITELIB}/BabelPhish
SCRIPTNAME=	${PREFIX}/bin/pybabelfish

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/pixmaps
	
	for a in ${PYFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${TARGET_DIR}/$$a; \
	done
	for a in ${WRKSRC}/pixmaps/*; do \
		${INSTALL_DATA} $$a ${TARGET_DIR}/pixmaps/`${BASENAME} $$a`; \
	done
	printf "#!/bin/sh\nexec ${PYTHONBIN} ${PREFIX}/${PYSITELIB}/BabelPhish/pybabelfish.py" > ${SCRIPTNAME}
	${CHMOD} ${BINMODE} ${SCRIPTNAME}
	${CHOWN} ${BINOWN}:${BINGRP} ${SCRIPTNAME}

.include "../../lang/python/extension.mk"
.include "../..//x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
