# $NetBSD: Makefile,v 1.6 2004/04/18 15:06:31 marc Exp $

PKGNAME=		postgresql-client-${BASE_VERS}
SVR4_PKGNAME=		pstgc
COMMENT=		PostgreSQL database client programs

.include "../../wip/postgresql74/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-readline
MAKE_ENV+=		INSTALLED_LIBPQ=1

BUILD_DIRS=		${WRKSRC}/src/bin

pre-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/backend && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
		../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	
post-install:
	${EGREP} -v "^#" ${FILESDIR}/man.exclude > ${WRKDIR}/man_tar_exclude
	${TAR} -zxm -C ${PREFIX}/man -X ${WRKDIR}/man_tar_exclude	\
		-f ${WRKSRC}/doc/man.tar.gz

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" && ${LOWER_OPSYS_VERSUFFIX} == "4"
USE_GNU_READLINE=yes
.endif

.include "../../wip/postgresql74-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
