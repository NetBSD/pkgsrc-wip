# $NetBSD: Makefile,v 1.7 2015/01/10 20:18:36 thomasklausner Exp $

DISTNAME=	logfmon
CATEGORIES=	sysutils


MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://logfmon.sourceforge.net/
COMMENT=	Log file monitor

GIT_REPOSITORIES=	logfmon
GIT_REPO.logfmon=	git@github.com:nicm/logfmon.git

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

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
