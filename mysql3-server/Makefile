# $NetBSD: Makefile,v 1.3 2003/08/28 19:30:21 adrian_p Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
SVR4_PKGNAME=		mysqs
COMMENT=		MySQL, a free SQL database (server)

.include "../mysql3-client/Makefile.common"

CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--without-berkeley-db
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

PTHREAD_OPTS=		require

CONFIGURE_ARGS+=	--with-pthreads

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}::MySQL\\ database\\ administrator:${MYSQL_DATADIR}:${SH}
PKG_GROUPS=		${MYSQL_GROUP}
RCD_SCRIPTS=		mysqld
CONFIGURE_ARGS+=	--with-mysqld-user=${MYSQL_USER}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR} \
			MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR
MAKE_DIRS_PERMS+=	${MYSQL_DATADIR} ${MYSQL_USER} ${MYSQL_GROUP} 0700

post-configure:
	cd ${WRKSRC} && ${CP} -f config.h include/my_config.h

post-build:
	cd ${WRKSRC}/scripts && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}	\
		${MAKE_FLAGS} safe_mysqld mysql_install_db

pre-install:
	${SED}	-e "s|@MYSQL_DATADIR@|${MYSQL_DATADIR}|g"		\
		-e "s|@CAT@|${CAT}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/safe_mysqld ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mysql_install_db ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/support-files/mysql.server ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/mysqld.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/safe_mysqld.1 ${PREFIX}/man/man1
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/pthread.buildlink2.mk"
.include "../../wip/mysql3-client/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.if ${PTHREAD_TYPE} == "pth"
CFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CXXFLAGS+=	-DSIGNALS_DONT_BREAK_READ
CONFIGURE_ENV+=	ac_cv_func_pthread_setschedparam=no
CONFIGURE_ENV+=	ac_cv_func_pthread_attr_setschedparam=no
.endif

.include "../../mk/bsd.pkg.mk"
