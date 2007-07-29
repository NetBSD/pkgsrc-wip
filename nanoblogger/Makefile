# $NetBSD: Makefile,v 1.1 2007/07/29 00:20:34 cherrymathew Exp $
#

DISTNAME=	nanoblogger-3.3
CATEGORIES=	wip www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://nanoblogger.sourceforge.net/downloads/
COMMENT=	Small weblog engine for the UNIX command line

DEPENDS+=       bash-[0-9]*:../../shells/bash

USE_LANGUAGES=	# none

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	cd ${WRKSRC}/ && ${RM} *.orig && ${PAX} -rw -pp [a-z]* ${PREFIX}/nanoblogger

.include "../../mk/bsd.pkg.mk"
