# $NetBSD: Makefile,v 1.2 2007/09/07 12:22:35 thomasklausner Exp $
#

DISTNAME=	nanoblogger-3.3
CATEGORIES=	www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://nanoblogger.sourceforge.net/downloads/
COMMENT=	Small weblog engine for the UNIX command line

DEPENDS+=       bash-[0-9]*:../../shells/bash
DEPENDS+=	tidy-[0-9]*:../../www/tidy

USE_LANGUAGES=	# none

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	cd ${WRKSRC}/ && ${RM} -f *.orig && ${PAX} -rw -pp [a-z]* ${PREFIX}/nanoblogger

.include "../../mk/bsd.pkg.mk"
