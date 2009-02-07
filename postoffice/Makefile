# $NetBSD: Makefile,v 1.9 2009/02/07 16:20:15 pbraun9 Exp $
#

DISTNAME=		postoffice-1.4.9
CATEGORIES=		mail
MASTER_SITES=		http://www.pell.portland.or.us/~orc/Code/postoffice/

MAINTAINER=		pbraun@nethence.com
HOMEPAGE=		http://www.pell.portland.or.us/~orc/Code/postoffice/
COMMENT=		Simple SMTP mail server and client

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--use-mailwrappers \
			--with-queuedir=${VARBASE}/spool/mqueue
INSTALLATION_DIRS+=	${PREFIX}/share/examples/postoffice
RCD_SCRIPTS=		postoffice

PKG_GROUPS=		mail
PKG_GID.mail=		6
PKG_USERS=		mail:mail
PKG_UID.mail=		8

OWN_DIRS=		${PREFIX}/sbin \
			${VARBASE}/spool/mqueue
OWN_DIRS_PERMS=		${VARBASE}/spool/mqueue mail mail 0700

BUILD_DEFS=		VARBASE PKG_SYSCONFBASE
BUILD_DEFS+=		POSTOFFICE_AUTH
BUILD_DEFS+=		POSTOFFICE_GREYLIST
BUILD_DEFS+=		POSTOFFICE_MILTER
BUILD_DEFS+=		POSTOFFICE_TCPWRAPPERS
BUILD_DEFS+=		POSTOFFICE_VIRTUAL

.if defined(POSTOFFICE_TCPWRAPPERS) && !empty(POSTOFFICE_TCPWRAPPERS:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-tcpwrappers
.endif
.if defined(POSTOFFICE_GREYLIST) && !empty(POSTOFFICE_GREYLIST:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-greylist
.endif
.if defined(POSTOFFICE_AUTH) && !empty(POSTOFFICE_AUTH:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-auth
.endif
.if defined(POSTOFFICE_MILTER) && !empty(POSTOFFICE_MILTER:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-milter
.endif
.if defined(POSTOFFICE_VIRTUAL) && !empty(POSTOFFICE_VIRTUAL:M[Yy][Ee][Ss])
	CONFIGURE_ARGS+=	--with-vhost=${PKG_SYSCONFBASE}/virtual \
				--with-vspool=${VARBASE}/spool/virtual \
				--with-vuser=mail
	OWN_DIRS+=		${VARBASE}/spool/virtual \
				${PKG_SYSCONFDIR}/virtual
	OWN_DIRS_PERMS+=	${VARBASE}/spool/virtual mail mail 0700
	OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/virtual mail mail 0700

.endif

post-install:
	sed -e 's:@PREFIX@:${PREFIX}:' \
	${FILESDIR}/mailer.conf \
	> ${PREFIX}/share/examples/postoffice/mailer.conf

	${INSTALL_DATA} ${FILESDIR}/postoffice.cf \
	${PREFIX}/share/examples/postoffice/

	${INSTALL_SCRIPT} ${FILESDIR}/pop_passwd.pl \
	${PREFIX}/share/examples/postoffice/

.include "../../mk/bsd.pkg.mk"
