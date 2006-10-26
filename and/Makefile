# $NetBSD: Makefile,v 1.8 2006/10/26 11:33:42 poppnk Exp $
#

DISTNAME=		and-1.2.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=and/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://and.sourceforge.net/
COMMENT=		Auto nice daemon

USE_TOOLS+=		gmake
BUILD_TARGET=		default

MYARCH=			${OPSYS}
.if ${MYARCH} == "NetBSD"
MYARCH=			OpenBSD
.endif

SUBST_CLASSES+=		pref
SUBST_STAGE.pref=	pre-patch
SUBST_FILES.pref=	Makefile
SUBST_SED.pref=		-e s,/usr/local,${PREFIX},

SUBST_CLASSES+=		arch
SUBST_STAGE.arch=	pre-patch
SUBST_FILES.arch=	Makefile
SUBST_SED.arch=		-e s,ARCH=,ARCH=${MYARCH}\ \#,g

SUBST_CLASSES+=		int
SUBST_STAGE.int=	pre-patch
SUBST_FILES.int=	and.c
SUBST_SED.int=		-e s,MAXINT,INT_MAX,g

SUBST_CLASSES+=		val
SUBST_STAGE.val=	pre-patch
SUBST_FILES.val=	and.c
SUBST_SED.val=		-e s,values,string,

SUBST_CLASSES+=		bsd
SUBST_STAGE.bsd=	pre-patch
SUBST_FILES.bsd=	and-OpenBSD.c
SUBST_SED.bsd=		-e s,kp_proc.p_ppid,kp_proc.p_pid,

SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-patch
SUBST_FILES.init=	Makefile
SUBST_SED.init=		-e s,INITSCRIPT=,\#,

SUBST_CLASSES+=		initd
SUBST_STAGE.initd=	pre-patch
SUBST_FILES.initd=	Makefile
SUBST_SED.initd=	-e s,INSTALL_INITD=,\#,

.include "../../mk/bsd.pkg.mk"
