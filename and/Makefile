# $NetBSD: Makefile,v 1.3 2004/12/02 16:38:55 thomasklausner Exp $
#

DISTNAME=		and-1.2.0
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=and/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://and.sourceforge.net/
COMMENT=		auto nice daemon

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=	make
BUILD_TARGET=	default

USE_BUILDLINK3=		yes
MYARCH=${OPSYS}
.if ${MYARCH} == "NetBSD"
MYARCH=OpenBSD
.endif

SUBST_CLASSES=pref arch int val bsd init initd

SUBST_STAGE.pref= pre-patch
SUBST_FILES.pref= Makefile
SUBST_SED.pref= -e s!\/usr\/local!${PREFIX}!

SUBST_STAGE.arch=pre-patch
SUBST_FILES.arch=Makefile
SUBST_SED.arch= -e s!$$\(shell\ uname\)!${MYARCH}!

SUBST_STAGE.int=pre-patch
SUBST_FILES.int=and.c
SUBST_SED.int=-e s!MAXINT!INT_MAX!

SUBST_STAGE.val=pre-patch
SUBST_FILES.val=and.c
SUBST_SED.val=-e s!values!string!

SUBST_STAGE.bsd=pre-patch
SUBST_FILES.bsd=and-OpenBSD.c
SUBST_SED.bsd= -e s!kp_proc\.p_ppid!kp_proc\.p_pid!

SUBST_STAGE.init=pre-patch
SUBST_FILES.init=Makefile
SUBST_SED.init= -e s!INITSCRIPT=!\#!

SUBST_STAGE.initd=pre-patch
SUBST_FILES.initd=Makefile
SUBST_SED.initd= -e s!INSTALL_INITD=!\#!

.include "../../mk/bsd.pkg.mk"
