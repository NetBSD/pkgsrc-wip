# $NetBSD: Makefile,v 1.4 2013/03/07 14:21:52 jym-netbsd Exp $
#

PKGNAME=	stud-0.3
CATEGORIES=	security

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/bumptech/stud
COMMENT=	Scalable TLS Unwrapping Daemon
LICENSE=	2-clause-bsd

DISTNAME=	bumptech-stud-0.3-51-g0b88039
MASTER_SITES=	http://rohara.fedorapeople.org/stud/

USE_TOOLS+=		gmake

BUILD_DEFS+=		STUD_USER STUD_GROUP VARBASE

STUD_USER?=		stud
STUD_GROUP?=		stud
STUD_HOME=		${VARBASE}/chroot/stud
# default file containing X509 PEM certificates and private keys
STUD_CERTS=		${PKG_SYSCONFDIR}/certs.pem

PKG_GROUPS?=		${STUD_GROUP}
PKG_USERS?=		${STUD_USER}:${STUD_GROUP}
PKG_GECOS.${STUD_USER}=	stud daemon user
PKG_HOME.${STUD_USER}=	${STUD_HOME}

WRKSRC=			${WRKDIR}/bumptech-stud-0b88039
EGDIR=			${PREFIX}/share/examples/stud
INSTALLATION_DIRS+=	bin ${EGDIR}

PKG_SYSCONFSUBDIR=	stud
PKG_SYSCONFDIR_PERMS=	${ROOT_USER} ${STUD_GROUP} 750

CONF_FILES+=		${EGDIR}/stud.conf ${PKG_SYSCONFDIR}/stud.conf
OWN_DIRS+=		${STUD_HOME}

SUBST_CLASSES+=		studconf
SUBST_STAGE.studconf=	pre-configure
SUBST_MESSAGE.studconf=	Apply default values to configuration file.
SUBST_FILES.studconf=	stud.conf
SUBST_VARS.studconf+=	STUD_USER STUD_GROUP STUD_HOME STUD_CERTS

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fix prefix path in Makefile.
SUBST_FILES.prefix=	Makefile
SUBST_VARS.prefix=	PREFIX

RCD_SCRIPTS=		stud

post-extract:
	${CP} ${FILESDIR}/stud.conf ${WRKSRC}/stud.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/stud.conf ${DESTDIR}${EGDIR}/stud.conf

.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
