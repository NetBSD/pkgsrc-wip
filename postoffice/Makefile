# $NetBSD: Makefile,v 1.6 2006/10/03 12:58:51 elge Exp $
#

DISTNAME=		postoffice-1.3.4
CATEGORIES=		mail
MASTER_SITES=		http://www.tsfr.org/~orc/Code/postoffice/

MAINTAINER=		pbraun@nethence.com
HOMEPAGE=		http://www.tsfr.org/~orc/Code/postoffice/
COMMENT=		Simple greylist, auth, milter, virtual hosts mbox capable SMTP server

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--use-mailwrappers
INSTALLATION_DIRS+=	${PREFIX}/share/examples/postoffice
CONF_FILES=		${PREFIX}/share/examples/postoffice/postoffice.cf ${PKG_SYSCONFDIR}/postoffice.cf
PKG_CONFIG=		no
RCD_SCRIPTS+=		postoffice

BUILD_DEFS+=		POSTOFFICE_AUTH
BUILD_DEFS+=		POSTOFFICE_GREYLIST
BUILD_DEFS+=		POSTOFFICE_MILTER
BUILD_DEFS+=		POSTOFFICE_TCPWRAPPERS
BUILD_DEFS+=		POSTOFFICE_VIRTUAL

.if defined(POSTOFFICE_TCPWRAPPERS) && !empty(POSTOFFICE_TCPWRAPPERS:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-tcpwrappers
.  endif
.if defined(POSTOFFICE_GREYLIST) && !empty(POSTOFFICE_GREYLIST:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-greylist
.  endif
.if defined(POSTOFFICE_AUTH) && !empty(POSTOFFICE_AUTH:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-auth
.  endif
.if defined(POSTOFFICE_MILTER) && !empty(POSTOFFICE_MILTER:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-milter
.  endif
.if defined(POSTOFFICE_VIRTUAL) && !empty(POSTOFFICE_VIRTUAL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-vhost=${SYSCONFBASE}/virtual \
			--with-vspool=${VARBASE}/spool/virtual \
			--with-vuser=mail
.  endif

post-install:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	${FILESDIR}/mailer.conf \
	> ${PREFIX}/share/examples/postoffice/mailer.conf
	${INSTALL_DATA} ${FILESDIR}/postoffice.cf ${PREFIX}/share/examples/postoffice/
	${INSTALL_SCRIPT} ${FILESDIR}/pop_passwd.pl ${PREFIX}/share/examples/postoffice/

.include "../../mk/bsd.pkg.mk"
