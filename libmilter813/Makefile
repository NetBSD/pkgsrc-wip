# $NetBSD: Makefile,v 1.1.1.1 2004/06/27 09:45:59 adrian_p Exp $

.include "../../wip/sendmail813/Makefile.common"

PKGNAME=	libmilter-${DIST_VERS}
COMMENT=	Mail filter support library for sendmail

post-patch: make-sendmail-siteconfig
	${ECHO} >>${DESCR_SRC}

do-build:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib install)

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`uname -srm | ${TR} \  .`
