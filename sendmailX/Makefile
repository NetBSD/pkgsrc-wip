# $NetBSD: Makefile,v 1.25 2012/10/07 16:22:55 asau Exp $

DISTNAME=	smX-${VERSION}
PKGNAME=	sendmailX-${VERSION}
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sendmail.org/sm-X/
COMMENT=	Modular Mail Transfer Agent


CONFLICTS+=	postfix-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
VERSION=	0.0.0.0
USE_TOOLS+=	sed

# Note: This will work on Linux, NetBSD, OpenBSD, SunOS, OSF1 and UnixWare but
# it will not work on Darwin and Interix.  Basically pkgsrc does not have
# the functionality ATM to add a user to a group and that's what we need
# this for.
#
USERMOD?=	/usr/sbin/usermod

EGDIR=		${PREFIX}/share/examples/smX
DOCDIR=		${PREFIX}/share/doc/smX
FILES_SUBST+=	PREFIX=${PREFIX} SMXCNF=${SMXCNF:Q} USERMOD=${USERMOD:Q}
FILES_SUBST+=	VARBASE=${VARBASE} SED=${SED:Q} UNAME=${UNAME:Q}
MESSAGE_SUBST+=	SMXCNF=${SMXCNF}

PKG_SYSCONFSUBDIR=	smx
SMXCNFDIR=		${PKG_SYSCONFDIR}
SMXCNF=			${SMXCNFDIR}/smx.conf

PKG_GROUPS=	smxs smxq smxc smxm smx
PKG_USERS=	smxs:smxs::Sendmail\ X\ SMTP\ Server
PKG_USERS+=	smxq:smxq::Sendmail\ X\ Queue\ Manager
PKG_USERS+=	smxc:smxc::Sendmail\ X\ SMTP\ Client
PKG_USERS+=	smxm:smxm::Sendmail\ X\ Address\ Resolver
PKG_USERS+=	smx:smx::Sendmail\ X\ Misc

# Note: Do not use Berkeley DB 4.3.27/28 in 64 bit mode on Solaris 5.8/9 as
# it crashes at least in those configurations. This bug is fixed in the
# version that is distributed with sendmail X.
#
# This is unconfirmed on pkgsrc so we roll with the pkgsrc version of db4.
#
CONFIGURE_ARGS+=	--disable-included-bdb

.include "options.mk"

RCD_SCRIPTS=		sendmailx
CONF_FILES_PERMS=	${EGDIR}/smx.conf ${SMXCNF} smx smx 0644
CONF_FILES_PERMS+=	${EGDIR}/aliases ${SMXCNFDIR}/aliases smxm smxm 0644
CONF_FILES_PERMS+=	${EGDIR}/Makefile ${SMXCNFDIR}/Makefile smxm smxm 0644
CONF_FILES_PERMS+=	${EGDIR}/mt ${SMXCNFDIR}/mt smxm smxm 0644

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-extract:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/smx.conf \
		> ${WRKDIR}/smx.conf
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/Makefile \
		> ${WRKDIR}/Makefile

post-build:
	@cd ${WRKSRC}/misc && ${MAKE} runas
	@cd ${WRKSRC}/libmta && ${MAKE} t-hostname
	@cd ${WRKSRC}/checks && ${MAKE} t-getgroup
	@cd ${WRKSRC}/libconf && ${MAKE} tree

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${WRKDIR}/smx.conf ${EGDIR}/smx.conf
	${INSTALL_DATA} ${WRKDIR}/Makefile ${EGDIR}/Makefile
	${INSTALL_DATA} ${FILESDIR}/aliases ${EGDIR}/aliases
	${INSTALL_DATA} ${FILESDIR}/mt ${EGDIR}/mt
	${INSTALL_DATA} ${WRKSRC}/doc/README.txt ${DOCDIR}/README.txt
	${INSTALL_DATA} ${WRKSRC}/doc/README.html ${DOCDIR}/README.html
	${INSTALL_PROGRAM} ${WRKSRC}/checks/t-getgroup ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
