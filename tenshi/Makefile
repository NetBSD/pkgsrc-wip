# $NetBSD: Makefile,v 1.6 2015/01/13 02:41:49 pbhenson Exp $
#

DISTNAME=	tenshi-0.15
CATEGORIES=	sysutils
MASTER_SITES=	http://dev.inversepath.com/download/tenshi/

MAINTAINER=	henson@acm.org
HOMEPAGE=	http://www.inversepath.com/tenshi.html
COMMENT=	Log monitoring program to watch and report on log files
LICENSE=	isc

USE_TOOLS+=		perl:run
REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	tenshi
EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${PREFIX}/${EGDIR}/tenshi.conf ${PKG_SYSCONFDIR}/tenshi/tenshi.conf
BUILD_DEFS+=		VARBASE

DEPENDS+=	p5-IO-BufferedSelect>=1.0:../../sysutils/p5-IO-BufferedSelect

SUBST_CLASSES+= 	tenshi
SUBST_STAGE.tenshi=	pre-build
SUBST_FILES.tenshi=	tenshi tenshi.conf tenshi.8
SUBST_SED.tenshi=	-e 's,/etc/tenshi/tenshi.conf,${PKG_SYSCONFDIR}/tenshi.conf,g'
SUBST_SED.tenshi+=	-e 's,/var/run/tenshi.pid,${VARBASE}/lib/tenshi/tenshi.pid,g'

PKG_GROUPS=		tenshi
PKG_USERS=		tenshi:tenshi
PKG_HOME.tenshi=	${VARBASE}/lib/tenshi
OWN_DIRS_PERMS+=	${VARBASE}/lib/tenshi tenshi tenshi 0700
OWN_DIRS+=		${PKG_SYSCONFDIR}/tenshi

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
