# $NetBSD: Makefile,v 1.6 2012/10/03 09:10:42 asau Exp $
#

DISTNAME=	logfmon
CATEGORIES=	sysutils

MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://logfmon.sourceforge.net/
COMMENT=	Log file monitor

CVS_PROJECT=		logfmon
CVS_REPOSITORIES=	${CVS_PROJECT}
CVS_ROOT.logfmon=	${CVS_ROOT_SOURCEFORGE}

USE_TOOLS+=		yacc

# Makefile things
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing the Makefile..
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/DEBUG=//'	# No debug
SUBST_SED.makefile=	-e 's/ -I-//'	# Obsolete with GCC 4

# Configuration path
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-build
SUBST_MESSAGE.conf=	Fixing configuration path..
SUBST_FILES.conf=	logfmon.h logfmon.conf.5 logfmon.8
SUBST_SED.conf=		-e "s,/etc,${PKG_SYSCONFDIR},"

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	INSTALLBIN=${INSTALL_PROGRAM:Q}
INSTALL_MAKE_FLAGS+=	INSTALLMAN=${INSTALL_MAN:Q}

.include "../../mk/bsd.pkg.mk"
.include "../../wip/mk/cvs-package.mk"
