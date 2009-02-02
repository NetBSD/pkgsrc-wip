# $NetBSD: Makefile,v 1.2 2009/02/02 03:22:13 thomasklausner Exp $

PKGNAME=		${DISTNAME:S/-/-embedded-/}
COMMENT=		MySQL 5, a free SQL database (embedded)

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/mysql5-client/Makefile.common"

MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--with-embedded-server
CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-raid
CONFIGURE_ARGS+=	--without-berkeley-db
CONFIGURE_ARGS+=	--without-mysqlfs

PTHREAD_OPTS+=		require
CONFIGURE_ARGS+=	--with-pthreads

BUILD_DIRS=		strings regex mysys dbug myisam myisammrg heap innobase vio libmysqld
CFLAGS+=		-fPIC -DPIC -I../libmysql
CXXFLAGS+=		-fPIC -DPIC -I../libmysql

INSTALLATION_DIRS=	bin lib/mysql

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
CXXFLAGS+=		-D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__
.endif

.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"

# We only need readline to placate the configure script.  None of the
# binaries are actually linked against -lreadline, so make this only
# a build-time dependency.
#
BUILDLINK_DEPMETHOD.readline=	build
.include "../../devel/readline/buildlink3.mk"

post-configure:
	cd ${WRKSRC}/include && cp -f config.h my_config.h
	cd ${WRKSRC}/sql && mv client_settings.h away

post-build:
	cd ${WRKSRC} && \
	${MKDIR} libmysqld/work && \
	cd libmysqld/work && \
	ar -x ../libmysqld.a && \
	${CC} -shared -Wl,-soname,libmysqld.so.0 -o libmysqld.so.0.0.1 *.o \
		-lwrap -lz -lpthread -lcrypt -lssl -lcrypto -lrt -lstdc++ -lm -lc

do-install:
	cd ${WRKSRC}/libmysqld && \
	${INSTALL_LIB} libmysqld.a ${DESTDIR}${PREFIX}/lib/mysql
	cd ${WRKSRC}/libmysqld/work && \
	${INSTALL_LIB} libmysqld.so.0.0.1 ${DESTDIR}${PREFIX}/lib/mysql
	cd ${DESTDIR}${PREFIX}/lib/mysql && ${RM} -f libmysqld.so && \
		ln -s libmysqld.so.0.0.1 libmysqld.so
	cd ${DESTDIR}${PREFIX}/lib/mysql && ${RM} -f libmysqld.so.0 && \
		ln -s libmysqld.so.0.0.1 libmysqld.so.0
	cd ${WRKSRC}/libmysqld/examples && \
	${INSTALL_PROGRAM} mysql_client_test_embedded mysqltest_embedded \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
