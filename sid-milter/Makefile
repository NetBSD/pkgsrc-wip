# $NetBSD: Makefile,v 1.2 2005/02/22 09:36:06 adrian_p Exp $

DISTNAME=	sid-milter-0.2.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sid-milter/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.sendmail.net/sid-milter/
COMMENT=	Open source implementation of the Sender ID specification

DEPENDS+=	sendmail>=8.13.0:../../mail/sendmail

BUILDLINK_DEPENDS.libmilter+=	libmilter>=8.13.0

USE_BUILDLINK3=		YES

USE_BUILTIN.libmilter=	NO
LICENSE=		no-profit
USE_GNU_TOOLS+=		m4
MAKE_ENV+=		M4="${M4}"
PTHREAD_OPTS+=		require
USE_PKGINSTALL=		YES
RCD_SCRIPTS=		sidmilter

SIDDOC=		${PREFIX}/share/doc/sid-milter

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-build
SUBST_FILES.libs=	sid-filter/Makefile.m4
SUBST_SED.libs=		-e "s|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g"
SUBST_MESSAGE.libs=	"Fixing paths."

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-extract:
	@${CP} ${FILESDIR}/sid-filter.m4 ${WRKSRC}/sid-filter/Makefile.m4

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build \
		INCLUDEDIR=${PREFIX}/include \
		LIBDIR=${PREFIX}/lib \
		MANROOT=${PREFIX}/man/man \
		UBINDIR=${PREFIX}/bin \
		install

	${INSTALL_DATA_DIR} ${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/README ${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/README-SenderID ${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${SIDDOC}

.include "../../mk/bsd.pkg.mk"
