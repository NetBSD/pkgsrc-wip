# $NetBSD: Makefile,v 1.8 2005/02/22 08:29:04 adrian_p Exp $

DISTNAME=	Unreal3.2.2b
PKGNAME=	unrealircd-3.2.2b
CATEGORIES=	chat
MASTER_SITES=	http://unreal.atlanti-ka.org/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.unrealircd.com/
COMMENT=	Advanced IRC server with IPv6 and SSL support

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
WRKSRC=		${WRKDIR}/Unreal3.2

#.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=	tre_version="0.7.0"
CONFIGURE_ENV+=	TRELIBS="-L${PREFIX}/lib -ltre"

CONFIGURE_ARGS+=	--with-dpath=${IRCD_HOME}
CONFIGURE_ARGS+=	--with-spath=${PREFIX}/sbin/ircd
CONFIGURE_ARGS+=	--with-permissions=0600
CONFIGURE_ARGS+=	--enable-dynamic-linking
#
CONFIGURE_ARGS+=	--with-hostname=${IRCD_HOST}
CONFIGURE_ARGS+=	--enable-prefixaq
CONFIGURE_ARGS+=	--with-listen=${IRCD_LISTEN}
CONFIGURE_ARGS+=	--with-sendq=${IRCD_SENDQ}
CONFIGURE_ARGS+=	--with-bufferpool=${IRCD_BUFFER}
CONFIGURE_ARGS+=	--with-fd-setsize=${IRCD_FDSIZE}
CONFIGURE_ARGS+=	--with-nick-history=${IRCD_NICKHIST}
CONFIGURE_ARGS+=	--disable-inet6

.include "options.mk"

IRCD_DOCS=	${PREFIX}/share/doc/unrealircd
IRCD_SHARE=	${PREFIX}/share/unrealircd
IRCD_EG=	${PREFIX}/share/examples/unrealircd

BUILD_DEFS+=	IRCD_SENDQ IRCD_LISTEN IRCD_BUFFER IRCD_USER IRCD_HOST
BUILD_DEFS+=	IRCD_HOME IRCD_NICKHIST IRCD_FDSIZE IRCD_GROUP 

PTHREAD_OPTS=	require

# The defaults for most of these here are from the standard Conf
# script supplied with the UnrealIRCd package.
#
IRCD_SENDQ?=	3000000
IRCD_LISTEN?=	5
IRCD_BUFFER?=	18
IRCD_NICKHIST?=	2000
IRCD_FDSIZE?=	512
IRCD_USER?=	uircd
IRCD_GROUP?=	uircd
IRCD_HOST?=	localhost
IRCD_HOME?=	${VARBASE}/unrealircd

DOC_FILES=	doc/Authors doc/coding-guidelines doc/tao.of.irc LICENSE

CONF_FILES_PERMS=	${IRCD_EG}/example.conf ${IRCD_HOME}/unrealircd.conf \
			${IRCD_USER} ${IRCD_GROUP} 0600

PKG_USERS=	${IRCD_USER}:${IRCD_GROUP}::UnrealIRCD\\ user:${IRCD_HOME}:${NOLOGIN}
PKG_GROUPS=	${IRCD_GROUP}
RCD_SCRIPTS=	unrealircd

MESSAGE_SUBST+=	IRCD_HOME=${IRCD_HOME}
FILES_SUBST+=	IRCD_HOME=${IRCD_HOME}
FILES_SUBST+=	IRCD_USER=${IRCD_USER}
FILES_SUBST+=	IRCD_GROUP=${IRCD_GROUP}

SUBST_CLASSES=		homedir
SUBST_STAGE.homedir=	post-patch
SUBST_FILES.homedir=	doc/example.conf
SUBST_SED.homedir=	-e "s|src/modules|${IRCD_SHARE}/modules|g" \
			-e "s|include \"|include \"${IRCD_SHARE}/|g"
SUBST_MESSAGE.homedir=	"Fixing home directory of IRC server."

OWN_DIRS_PERMS=		${IRCD_HOME} ${IRCD_USER} ${IRCD_GROUP} 0700

# Do an explicit disable of inet6 as --disable-inet6 does not do the job
.if empty(PKG_OPTIONS:Minet6)         
CONFIGURE_ENV+=		ac_cv_ip6=no  
.endif

# Bad hack as I think there's a bug floating round the place
# with INSTALL_UNSTRIPPED=yes being ignored in cetain cases.
.if ${OPSYS} == "Darwin"
_STRIPFLAG_CC=          
_STRIPFLAG_INSTALL=     
.endif

do-install:
	${INSTALL_DATA_DIR} ${IRCD_SHARE}
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/networks
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/aliases
	${INSTALL_DATA_DIR} ${IRCD_SHARE}/modules
	${INSTALL_DATA_DIR} ${IRCD_DOCS}
	${INSTALL_DATA_DIR} ${IRCD_EG}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/unrealircd

	${INSTALL_PROGRAM} ${WRKSRC}/src/ircd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/networks/*.network ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/networks/networks.ndx ${IRCD_SHARE}/networks
	${INSTALL_SCRIPT} ${WRKSRC}/networks/makenet ${IRCD_SHARE}/networks
	${INSTALL_DATA} ${WRKSRC}/aliases/*.conf ${IRCD_SHARE}/aliases
	${INSTALL_DATA} ${WRKSRC}/badwords*.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/help.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/spamfilter.conf ${IRCD_SHARE}
	${INSTALL_DATA} ${WRKSRC}/src/modules/*.so ${IRCD_SHARE}/modules

	for f in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${IRCD_DOCS}; \
	done

	${INSTALL_DATA} ${WRKSRC}/doc/unreal32docs.html \
		${PREFIX}/share/doc/html/unrealircd

	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${IRCD_EG}
	${INSTALL_DATA} ${WRKSRC}/doc/example.settings ${IRCD_EG}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/tre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
