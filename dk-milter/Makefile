# $NetBSD: Makefile,v 1.3 2005/05/24 10:44:35 rillig Exp $

DISTNAME=	dk-milter-0.2.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://sendmail.net/dk-milter/
COMMENT=	Open source implementation of DomainKeys for sendmail

DEPENDS+=	sendmail>=8.13.0:../../mail/sendmail

BUILDLINK_DEPENDS.libmilter+=	libmilter>=8.13.0


USE_BUILTIN.libmilter=	NO
LICENSE=		no-profit
BUILD_DEFS+=		USE_INET6
USE_TOOLS+=		gm4
MAKE_ENV+=		M4="${M4}"
LDFLAGS+=		-lpthread
PTHREAD_OPTS+=		require

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-build
SUBST_FILES.libs=	dk-filter/Makefile.m4 libdk/Makefile.m4
SUBST_SED.libs=		-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g" \
			-e "s|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g" \
			-e "s|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g"
SUBST_MESSAGE.libs=	"Fixing paths."

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
SUBST_SED.libs+=	-e "s|@DNL@||g"
.else
SUBST_SED.libs+=	-e "s|@DNL@|dnl |g"
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-extract:
	@${CP} ${FILESDIR}/dk-filter.m4 ${WRKSRC}/dk-filter/Makefile.m4
	@${CP} ${FILESDIR}/libdk.m4 ${WRKSRC}/libdk/Makefile.m4

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dk-milter
	${INSTALL_LIB} ${WRKSRC}/${DKWORK}/libar/libar.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/${DKWORK}/libar/ar.0 ${PREFIX}/man/cat3/
	${INSTALL_PROGRAM} ${WRKSRC}/${DKWORK}/dk-filter/dk-filter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${DKWORK}/dk-filter/dk-filter.0 \
		${PREFIX}/man/cat8/
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dk-milter

.include "../../mk/bsd.pkg.mk"

# Has to be below include for bsd.pkg.mk, else substition fails
DKWORK!=		${ECHO}	obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -`
