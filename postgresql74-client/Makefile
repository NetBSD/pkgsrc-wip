# $NetBSD: Makefile,v 1.3 2004/03/20 22:26:51 marc Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database client programs

DESCR_SRC=		${.CURDIR}/../../databases/postgresql-client/DESCR

.include "../../wip/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	${MKDIR} ${WRKSRC}/src/include/parser
	${CP} ${WRKSRC}/src/backend/parser/parse.h \
	    ${WRKSRC}/src/include/parser
	cd ${WRKSRC}/src/bin/psql &&					\
	${RM} -f pqsignal.h &&						\
	${LN} -sf ${BUILDLINK_DIR}/include/postgresql/server/libpq/pqsignal.h \
	    pqsignal.h

post-install:
	cd ${PREFIX}/man && 						\
		${PAX} -O -crzf ${WRKSRC}/doc/man.tar.gz

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../wip/postgresql74-lib/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
