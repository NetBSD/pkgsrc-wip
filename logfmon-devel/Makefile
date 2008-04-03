# $NetBSD: Makefile,v 1.3 2008/04/03 21:23:48 smoppy Exp $
#

PKGNAME=	logfmon-1.0.1
DISTNAME=	logfmon
CATEGORIES=	sysutils
MASTER_SITES=	#

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://logfmon.sourceforge.net/
COMMENT=	Log file monitor

CVS_PROJECT=		logfmon
CVS_REPOSITORIES=	${CVS_PROJECT}
CVS_ROOT.logfmon=	${CVS_ROOT_SOURCEFORGE}

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		yacc

# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile..
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile+=	-e 's/$${PREFIX}/$${DESTDIR}$${PREFIX}/'
SUBST_SED.makefile+=	-e 's/-g bin -o root/-o ${BINOWN} -g ${BINGRP}/'
SUBST_SED.makefile+=	-e "s,/man/,/${PKGMANDIR}/,"
SUBST_SED.makefile+=	-e 's/DEBUG=//'	# No debug
SUBST_SED.makefile+=	-e 's/ -I-//'	# Obsolete with GCC 4

# Configuration path
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-build
SUBST_MESSAGE.conf=	Fixing configuration path..
SUBST_FILES.conf=	logfmon.h logfmon.conf.5 logfmon.8
SUBST_SED.conf=		-e "s,/etc,${PKG_SYSCONFDIR},"

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
