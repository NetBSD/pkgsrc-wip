# $NetBSD: Makefile,v 1.1.1.1 2004/09/01 10:35:53 adrian_p Exp $

DISTNAME=	sid-milter-0.2.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sid-milter/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.sendmail.net/sid-milter/
COMMENT=	Open source implementation of the Sender ID specification

DEPENDS+=	sendmail>=8.13.0:../../mail/sendmail

LICENSE=	no-profit
USE_BUILDLINK3=	YES
PTHREAD_OPTS+=	require
USE_PKGINSTALL=	YES
RCD_SCRIPTS=	sidmilter

SIDDOC=		${PREFIX}/share/doc/sid-milter
BUILDLINK_DEPENDS.libmilter?=	libmilter>=8.13.0

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

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
