# $NetBSD$

DISTNAME=	${PKGVERSION}
PKGNAME=	redict-7.3.0
CATEGORIES=	databases
MASTER_SITES=	https://codeberg.org/redict/redict/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redict.io/
COMMENT=	Persistent key-value database with built-in net interface
LICENSE=	gnu-lgpl-v3
WRKSRC=		${WRKDIR}/redict

TEST_DEPENDS+=	tcl>=8.5:../../lang/tcl

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake pkg-config

# Don't let LTO kick in as it is not supported on all platforms.
MAKE_ENV+=	OPTIMIZATION=${DBG:U-O2:Q}
# Use standard malloc by default
MAKE_ENV+=	USE_JEMALLOC=no

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

RCD_SCRIPTS+=		redict
RCD_SCRIPT_SRC.redict=	${FILESDIR}/redict.sh

DOCDIR=			share/doc/redict
DOCFILES+=		README.md SECURITY.md TLS.md
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests

BUILD_DEFS+=		VARBASE REDICT_USER REDICT_GROUP REDICT_DATADIR
BUILD_DEFS+=		REDICT_LOGDIR REDICT_PIDDIR PKG_SYSCONFDIR

REDICT_USER?=		redict
REDICT_GROUP?=		redict
REDICT_DATADIR?=	${VARBASE}/db/redict
REDICT_LOGDIR?=		${VARBASE}/log/redict
REDICT_PIDDIR?=		${VARBASE}/run

OWN_DIRS_PERMS+=	${REDICT_DATADIR} ${REDICT_USER} ${REDICT_GROUP} 0770
OWN_DIRS_PERMS+=	${REDICT_LOGDIR} ${REDICT_USER} ${REDICT_GROUP} 0770

CONF_FILES_PERMS+=	${PREFIX}/share/redict/redict.conf ${PKG_SYSCONFDIR}/redict.conf \
			${REAL_ROOT_USER} ${REDICT_GROUP} 0640

PKG_GROUPS+=			${REDICT_GROUP}
PKG_USERS+=			${REDICT_USER}:${REDICT_GROUP}
PKG_GECOS.${REDICT_USER}=	redict daemon user
PKG_HOME.${REDICT_USER}=	${REDICT_DBDIR}

FILES_SUBST+=		REDICT_USER=${REDICT_USER}
FILES_SUBST+=		REDICT_GROUP=${REDICT_GROUP}
FILES_SUBST+=		REDICT_DATADIR=${REDICT_DATADIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=		redict.conf
SUBST_VARS.fix-paths=		REDICT_DATADIR REDICT_LOGDIR REDICT_PIDDIR

CHECK_PORTABILITY_SKIP+=	deps/jemalloc/configure

post-extract:
	${CHMOD} -R g-w ${WRKSRC}

post-install:
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${DOCDIR}/${file}
.endfor

do-test:
	cd ${WRKSRC} && ${SH} runtest

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
