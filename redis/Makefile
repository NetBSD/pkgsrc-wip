# $NetBSD: Makefile,v 1.3 2011/03/08 10:52:25 zatmania Exp $
#

DISTNAME=	redis-2.2.2
CATEGORIES=	databases
MASTER_SITES=	http://redis.googlecode.com/files/

MAINTAINER=	zatmania@gotofreedom.org
HOMEPAGE=	http://code.google.com/p/redis/
COMMENT=	Persistent key-value database with built-in net interface
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pax
USE_LANGUAGES=	c99

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS+=		redis
RCD_SCRIPT_SRC.redis=	${FILESDIR}/redis.sh

DOCDIR=			share/doc/redis
DOCFILES+=		00-RELEASENOTES BUGS COPYING \
			Changelog README
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests
CONF_FILES=		${EGDIR}/redis.conf.example ${PKG_SYSCONFDIR}/redis.conf

BUILD_DEFS+=		VARBASE REDIS_USER REDIS_GROUP REDIS_DATADIR
BUILD_DEFS+=		REDIS_LOGDIR REDIS_PIDDIR

REDIS_USER?=		redis
REDIS_GROUP?=		redis
REDIS_DATADIR?=		${VARBASE}/db/redis
REDIS_LOGDIR?=		${VARBASE}/log/redis
REDIS_PIDDIR?=		${VARBASE}/run

OWN_DIRS+=		${REDIS_DATADIR} ${REDIS_LOGDIR}
OWN_DIRS_PERMS+=	${REDIS_DATADIR} ${REDIS_USER} ${REDIS_GROUP} 0770
OWN_DIRS_PERMS+=	${REDIS_LOGDIR} ${REDIS_USER} ${REDIS_GROUP} 0770

PKG_GROUPS+=		${REDIS_GROUP}
PKG_USERS+=		${REDIS_USER}:${REDIS_GROUP}
PKG_GECOS.${REDIS_USER}= Redis daemon user
PKG_HOME.${REDIS_USER}=	${REDIS_DBDIR}

FILES_SUBST+=		REDIS_USER=${REDIS_USER}

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-patch
SUBST_MESSAGE.fix-paths= Fixing paths.
SUBST_FILES.fix-paths=	redis.conf
SUBST_SED.fix-paths=	-e 's,@@DBDIR@@,${REDIS_DATADIR},g'
SUBST_SED.fix-paths+=	-e 's,@@LOGDIR@@,${REDIS_LOGDIR},g'
SUBST_SED.fix-paths+=	-e 's,@@PIDDIR@@,${REDIS_PIDDIR},g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/redis.conf ${DESTDIR}${EGDIR}/redis.conf.example
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${DOCDIR}/${file}
.endfor
	cd ${WRKSRC}/doc && pax -rwpp . ${DESTDIR}${PREFIX}/${DOCDIR}
	cd ${WRKSRC}/utils && pax -rwpp . ${DESTDIR}${EGDIR}/utils/
	cd ${WRKSRC}/tests && pax -rwpp . ${DESTDIR}${EGDIR}/tests/

.include "../../mk/bsd.pkg.mk"
