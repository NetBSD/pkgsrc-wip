# $NetBSD: Makefile,v 1.13 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=		postoffice-1.4.9
CATEGORIES=		mail
MASTER_SITES=		http://www.pell.portland.or.us/~orc/Code/postoffice/

MAINTAINER=		pbraun@nethence.com
HOMEPAGE=		http://www.pell.portland.or.us/~orc/Code/postoffice/
COMMENT=		Simple SMTP mail server and client
LICENSE=		original-bsd

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--confdir=${PKG_SYSCONFDIR} \
			--use-mailwrappers \
			--with-queuedir=${VARBASE}/spool/mqueue \
			--with-auth \
			--with-milter \
			--with-tcpwrappers \
			--with-vhost=${PKG_SYSCONFDIR}/virtual \
			--with-vspool=${VARBASE}/spool/virtual \
			--with-vuser=mail

BUILD_DEFS=		VARBASE PKG_SYSCONFDIR
BUILD_DEFS+=		POSTOFFICE_GREYLIST

.if defined(POSTOFFICE_GREYLIST) && !empty(POSTOFFICE_GREYLIST:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-greylist
.endif

PKG_GROUPS=		mail
PKG_GID.mail=		6
PKG_USERS=		mail:mail
PKG_UID.mail=		8

RCD_SCRIPTS=		postoffice

INSTALLATION_DIRS=	${DESTDIR}${PREFIX}/share/examples/postoffice
EGDIR=			${DESTDIR}${PREFIX}/share/examples/postoffice
CONF_FILES=		${EGDIR}/postoffice.cf ${PKG_SYSCONFDIR}/postoffice.cf

OWN_DIRS=		${DESTDIR}${PREFIX}/sbin
OWN_DIRS+=		${DESTDIR}${PKG_SYSCONFDIR}/virtual
OWN_DIRS+=		${VARBASE}/spool/mqueue
OWN_DIRS+=		${VARBASE}/spool/virtual

OWN_DIRS_PERMS=		${DESTDIR}${PKG_SYSCONFDIR}/virtual mail mail 0700
OWN_DIRS_PERMS+=	${VARBASE}/spool/mqueue mail mail 0700
OWN_DIRS_PERMS+=	${VARBASE}/spool/virtual mail mail 0700

post-install:
	sed -e 's:@PREFIX@:${PREFIX}:' \
	${FILESDIR}/mailer.conf \
	> ${DESTDIR}${PREFIX}/share/examples/postoffice/mailer.conf

	${INSTALL_DATA} ${FILESDIR}/postoffice.cf \
	${DESTDIR}${PREFIX}/share/examples/postoffice/

	${INSTALL_SCRIPT} ${FILESDIR}/pop_passwd.pl \
	${DESTDIR}${PREFIX}/share/examples/postoffice/

.include "../../mk/bsd.pkg.mk"
