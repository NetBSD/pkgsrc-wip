# $NetBSD$

DISTNAME=	${PKGNAME_NOREV}-stable-src
PKGNAME=	privoxy-4.2.0
CATEGORIES=	www
MASTER_SITES=	https://www.privoxy.org/sf-download-mirror/Sources/${PKGVERSION_NOREV}%20(stable)/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.privoxy.org/
COMMENT=	Web proxy with advanced filtering capabilities
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/privoxy-4.2.0-stable

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	privoxy
PRIVOXY_EGDIR=		${PREFIX}/share/examples/${PKGBASE}
PRIVOXY_DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
PRIVOXY_LOGDIR=		${VARBASE}/log/privoxy

USE_TOOLS+=		gmake mktemp autoconf autoheader perl

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	config man/privoxy.8 man/uagen.1
SUBST_VARS.paths=	PREFIX VARBASE PKG_SYSCONFDIR PRIVOXY_LOGDIR PRIVOXY_DOCDIR
SUBST_STAGE.paths=	pre-configure

REPLACE_PERL+=		tools/privoxy-log-parser.pl \
			tools/privoxy-regression-test.pl \
			tools/url-pattern-translator.pl \
			tools/uagen.pl

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PRIVOXY_EGDIR}
CONFIGURE_ARGS+=	--with-user=${PRIVOXY_USER:Q}
CONFIGURE_ARGS+=	--with-group=${PRIVOXY_GROUP:Q}

MAKE_FILE=		GNUmakefile

BUILD_DEFS+=			VARBASE
PRIVOXY_USER=			privoxy
PRIVOXY_GROUP=			privoxy
PRIVOXY_HOME=			${VARBASE}/lib/privoxy
PKG_USERS_VARS+=		PRIVOXY_USER
PKG_GROUPS_VARS+=		PRIVOXY_GROUP
PKG_GROUPS=			${PRIVOXY_GROUP}
PKG_USERS=			${PRIVOXY_USER}:${PRIVOXY_GROUP}
PKG_GECOS.${PRIVOXY_USER}=	Privoxy user
PKG_HOME.${PRIVOXY_USER}=	${PRIVOXY_HOME}

OWN_DIRS_PERMS+=	${PRIVOXY_HOME} ${PRIVOXY_USER} ${PRIVOXY_GROUP} 0770

FILES_SUBST+=		PRIVOXY_USER=${PRIVOXY_USER:Q}
.if ${INIT_SYSTEM} == "rc.d"
RCD_SCRIPTS+=		privoxy
.endif

USER_GROUP=		${PRIVOXY_USER} ${PRIVOXY_GROUP}
.for i in \
	config trust default.action user.action user.filter default.filter match-all.action
CONF_FILES_PERMS+=	${PRIVOXY_EGDIR}/${i} ${PKG_SYSCONFDIR}/${i} ${USER_GROUP} 0640
.endfor

OWN_DIRS_PERMS+=	${PRIVOXY_LOGDIR} ${USER_GROUP} 0755

pre-configure:
	cd ${WRKSRC} && autoheader && autoconf

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
