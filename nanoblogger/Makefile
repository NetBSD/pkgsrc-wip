# $NetBSD: Makefile,v 1.3 2007/09/07 12:24:21 dillo Exp $
#

DISTNAME=	nanoblogger-3.3
CATEGORIES=	www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://nanoblogger.sourceforge.net/
COMMENT=	Small weblog engine for the UNIX command line

DEPENDS+=       bash-[0-9]*:../../shells/bash
DEPENDS+=	tidy-[0-9]*:../../www/tidy

USE_LANGUAGES=	# none

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	cd ${WRKSRC}/ && ${RM} -f *.orig && ${PAX} -rw -pp [a-z]* ${PREFIX}/nanoblogger

.include "../../mk/bsd.pkg.mk"
