# $NetBSD: Makefile,v 1.12 2012/06/13 06:17:15 othyro Exp $
#

DISTNAME=		and-1.2.0
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=and/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://and.sourceforge.net/
COMMENT=		Auto nice daemon
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake
USE_LANGUAGES=		c
BUILD_TARGET=		default
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

MYARCH=			${OPSYS}
.if ${MYARCH} == "NetBSD"
MYARCH=			OpenBSD
.endif

SUBST_CLASSES+=		pref
SUBST_STAGE.pref=	pre-configure
SUBST_FILES.pref=	Makefile
SUBST_SED.pref=		-e s,/usr/local,${PREFIX},

SUBST_CLASSES+=		arch
SUBST_STAGE.arch=	pre-configure
SUBST_FILES.arch=	Makefile
SUBST_SED.arch=		-e s,ARCH=.*,ARCH=${MYARCH},g

SUBST_CLASSES+=		int
SUBST_STAGE.int=	pre-configure
SUBST_FILES.int=	and.c
SUBST_SED.int=		-e s,MAXINT,INT_MAX,g

SUBST_CLASSES+=		val
SUBST_STAGE.val=	pre-configure
SUBST_FILES.val=	and.c
SUBST_SED.val=		-e s,values,string,

SUBST_CLASSES+=		bsd
SUBST_STAGE.bsd=	pre-configure
SUBST_FILES.bsd=	and-OpenBSD.c
SUBST_SED.bsd=		-e s,kp_proc.p_ppid,kp_proc.p_pid,

SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-configure
SUBST_FILES.init=	Makefile
SUBST_SED.init=		-e s,INITSCRIPT=,\#,

SUBST_CLASSES+=		initd
SUBST_STAGE.initd=	pre-configure
SUBST_FILES.initd=	Makefile
SUBST_SED.initd=	-e s,INSTALL_INITD=,\#,

.include "../../mk/bsd.pkg.mk"
