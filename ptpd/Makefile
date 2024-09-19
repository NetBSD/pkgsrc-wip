# $NetBSD: Makefile,v 1.2 2013/06/18 12:24:27 fhajny Exp $
#

DISTNAME=	ptpd-2.2.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ptpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ptpd.sourceforge.net/
COMMENT=	Precision Time Protocol Daemon
LICENSE=	2-clause-bsd

CFLAGS.SunOS+=	-D_XPG4_2 -D__EXTENSIONS__
LIBS.SunOS+=	-lnsl -lresolv -lsocket

MAKE_ENV+=	LIBS=${LIBS:Q}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man8 sbin

PLIST_SUBST+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ptpd2 ${DESTDIR}${PREFIX}/sbin
	${INSTALL_LIB} ${WRKSRC}/libptpd2.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libptpd2.so.${PKGVERSION_NOREV} ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/ptpd2.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
