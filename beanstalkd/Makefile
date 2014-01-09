# $NetBSD: Makefile,v 1.2 2014/01/09 19:30:42 othyro Exp $
#

DISTNAME=	v1.9
PKGNAME=	beanstalkd${DISTNAME:S/v/-/1}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/kr/beanstalkd/archive/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kr.github.io/beanstalkd/
COMMENT=	Simple, fast work queue
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

B_MANDIR=		${PKGMANDIR}/man1
B_DOCDIR=		share/doc/${PKGBASE}
RCD_SCRIPTS+=		beanstalkd
INSTALLATION_DIRS+=	${B_MANDIR} ${B_DOCDIR} share/examples/rc.d

PKG_GROUPS_VARS+=	BEANSTALKD_GROUP
PKG_USERS_VARS=		BEANSTALKD_USER
BUILD_DEFS+=		BEANSTALKD_USER BEANSTALKD_GROUP BEANSTALKD_HOME VARBASE
BEANSTALKD_USER?=	beanstalkd
FILES_SUBST+=		BEANSTALK_USER=${BEANSTALKD_USER}
BEANSTALKD_GROUP?=	beanstalkd
BEANSTALKD_HOME?=	${VARBASE}/chroot/beanstalkd
PKG_HOME.beanstalkd?=	${BEANSTALKD_HOME}
PLIST_SUBST+=		BEANSTALK_HOME=${BEANSTALKD_HOME}
PKG_GROUPS=		${BEANSTALKD_GROUP}
PKG_GECOS.beanstalkd=	beanstalk daemon
PKG_USERS=		${BEANSTALKD_USER}:${BEANSTALKD_GROUP}
OWN_DIRS_PERMS+=	${PKG_HOME.beanstalkd} ${PKG_USERS:S/:/ /1} 0700

post-patch:
	${CP} ${WRKSRC}/freebsd.c ${WRKSRC}/netbsd.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/beanstalkd.1 \
		${DESTDIR}${PREFIX}/${B_MANDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/protocol.txt \
		${DESTDIR}${PREFIX}/${B_DOCDIR}

.include "../../mk/bsd.pkg.mk"
