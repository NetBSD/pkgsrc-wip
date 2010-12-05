# $NetBSD: Makefile,v 1.1.1.1 2010/12/05 17:24:18 zatmania Exp $
#

DISTNAME=	redis-2.0.4
CATEGORIES=	databases
MASTER_SITES=	http://redis.googlecode.com/files/

MAINTAINER=	zatmania@gotofreedom.org
HOMEPAGE=	http://code.google.com/p/redis/
COMMENT=	Redis is an advanced key-value store
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pax
USE_LANGUAGES=	c99

PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS+=		redis
RCD_SCRIPT_SRC.redis=	${FILESDIR}/redis.sh

DOCDIR=			share/doc/redis
DOCFILES+=		00-RELEASENOTES BETATESTING.txt BUGS COPYING \
			Changelog README

BUILD_DEFS+=		VARBASE

REDIS_DATADIR=		${VARBASE}/db/redis
OWN_DIRS+=		${REDIS_DATADIR}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR} ${EGDIR}/utils ${EGDIR}/tests
CONF_FILES=		${EGDIR}/redis.conf.example ${PKG_SYSCONFDIR}/redis.conf

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-patch
SUBST_MESSAGE.fix-paths=Fixing dbdir path.
SUBST_FILES.fix-paths=	redis.conf
SUBST_SED.fix-paths=	-e 's,@@DBDIR@@,${REDIS_DATADIR},g'

do-install:
	 ${INSTALL_PROGRAM} ${WRKSRC}/redis-server ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_PROGRAM} ${WRKSRC}/redis-cli ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_PROGRAM} ${WRKSRC}/redis-benchmark ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_PROGRAM} ${WRKSRC}/redis-check-aof ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_PROGRAM} ${WRKSRC}/redis-check-dump ${DESTDIR}${PREFIX}/bin/
	 ${INSTALL_DATA} ${WRKSRC}/redis.conf ${DESTDIR}${EGDIR}/redis.conf.example
.for file in ${DOCFILES}
	 ${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${DOCDIR}/${file}
.endfor
	 ${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DESTDIR}${PREFIX}/${DOCDIR}
	 ${INSTALL_DATA_DIR} ${DESTDIR}${REDIS_DATADIR}
	 cd ${WRKSRC}/utils && pax -rwpp . ${DESTDIR}${EGDIR}/utils/
	 cd ${WRKSRC}/tests && pax -rwpp . ${DESTDIR}${EGDIR}/tests/

.include "../../mk/bsd.pkg.mk"
