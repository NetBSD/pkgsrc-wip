# $NetBSD: Makefile,v 1.1.1.1 2003/10/13 14:10:25 adrian_p Exp $

DISTNAME=	Unreal3.2-beta18
PKGNAME=	unrealircd-3.2beta18
WRKSRC=		${WRKDIR}/Unreal3.2
CATEGORIES=	chat
MASTER_SITES=	http://www.unrealircd.com/downloads/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

PTHREAD_OPTS=	require

CONFIGURE_ARGS+=	--enable-hub
CONFIGURE_ARGS+=	--enable-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--enable-ipv6
CONFIGURE_ARGS+=	--with-dpath=${IRCD_HOME}
CONFIGURE_ARGS+=	--with-spath=${PREFIX}/sbin/ircd
CONFIGURE_ARGS+=	--with-hostname=localhost
CONFIGURE_ARGS+=	--with-permissions=0600
CONFIGURE_ARGS+=	--with-listen=5
CONFIGURE_ARGS+=	--with-nick-history=2000
CONFIGURE_ARGS+=	--with-sendq=3000000
CONFIGURE_ARGS+=	--with-bufferpool=18
CONFIGURE_ARGS+=	--with-fd-setsize=512
CONFIGURE_ARGS+=	--enable-dynamic-linking

IRCD_DOCS=	${PREFIX}/share/doc/unrealircd
IRCD_SHARE=	${PREFIX}/share/unrealircd
IRCD_EG=	${PREFIX}/share/examples/unrealircd

IRCD_USER?=	uircd
IRCD_GROUP?=	uircd
IRCD_UID?=	5000
IRCD_GID?=	5000
IRCD_HOME?=	/var/unrealircd

RESTRICTED=		"Hardset GID and UID"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

BUILD_DEFS+=	IRCD_UID IRCD_GID

DOC_FILES=	doc/Authors doc/coding-guidelines doc/tao.of.irc \
		doc/unreal32docs.html LICENSE Donation

CONF_FILES=	${IRCD_EG}/example.conf \
		${IRCD_SHARE}/unrealircd.conf

CONF_FILES_MODE=	0600

PKG_USERS=	${IRCD_USER}:${IRCD_GROUP}:${IRCD_UID}:UnrealIRCD\\ user:${IRCD_HOME}:${NOLOGIN}
PKG_GROUPS=	${IRCD_GROUP}:${IRCD_GID}
RCD_SCRIPTS=	unrealircd

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

CFLAGS+=	-DIRC_UID=${IRCD_UID}
CFLAGS+=	-DIRC_GID=${IRCD_GID}

MESSAGE_SUBST+=	IRCD_HOME=${IRCD_HOME}
MESSAGE_SUBST+=	IRCD_DOCS=${IRCD_DOCS}
FILES_SUBST+=	IRCD_HOME=${IRCD_HOME}
FILES_SUBST+=	IRCD_SHARE=${IRCD_SHARE}
FILES_SUBST+=	IRCD_USER=${IRCD_USER}
FILES_SUBST+=	IRCD_GROUP=${IRCD_GROUP}
FILES_SUBST+=	PAX=${PAX}

OWN_DIRS_PERMS+=	${IRCD_HOME} ${IRCD_USER} ${IRCD_GROUP} 755

pre-install:
	${SED} -e 's#@IRCD_HOME@#${IRCD_HOME}#g' \
		< ${WRKSRC}/doc/example.conf > ${WRKSRC}/example.conf

do-install:
	${INSTALL_DATA_DIR} ${IRCD_SHARE}
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/networks
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/aliases
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/modules
	${INSTALL_DATA_DIR} ${IRCD_DOCS}
	${INSTALL_DATA_DIR} ${IRCD_EG}

	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/networks/*.network ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/networks/networks.ndx ${IRCD_SHARE}/networks
	${INSTALL_SCRIPT} ${WRKSRC}/networks/makenet ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${IRCD_SHARE}/aliases
	${INSTALL_DATA} ${WRKSRC}/badwords*.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${IRCD_SHARE}
	${INSTALL_SCRIPT} ${WRKSRC}/src/modules/*.so ${IRCD_SHARE}/modules

	for FILE in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE ${IRCD_DOCS}; \
	done

	${INSTALL_DATA} ${WRKSRC}/example.conf ${IRCD_EG}
	${INSTALL_DATA} ${WRKSRC}/doc/example.settings ${IRCD_EG}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
