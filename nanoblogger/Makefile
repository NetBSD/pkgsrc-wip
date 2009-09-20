# $NetBSD: Makefile,v 1.7 2009/09/20 13:42:14 tonnerre Exp $
#

DISTNAME=	nanoblogger-3.4.1
CATEGORIES=	www
MASTER_SITES=	http://nanoblogger.sourceforge.net/downloads/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://nanoblogger.sourceforge.net/
COMMENT=	Small weblog engine for the UNIX command line

DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	tidy-[0-9]*:../../www/tidy

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		nb
SUBST_SED.fix-paths+=		-e 's,\/bin\/bash,${PREFIX}/bin/bash,'
SUBST_SED.fix-paths+=            -e 's,NB_BASE_DIR=`dirname $$0`,NB_BASE_DIR=${PREFIX}/share/nanoblogger,'

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nb ${PREFIX}/bin
	cd ${WRKSRC}/ && pax -rw -pp [a-z]* ${PREFIX}/share/nanoblogger

#.include "../../mk/subst.mk"
.include "../../mk/bsd.pkg.mk"
