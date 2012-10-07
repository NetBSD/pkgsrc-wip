# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	QCDLoop-1.9
PKGNAME=	qcdloop-1.9
CATEGORIES=	math
MASTER_SITES=	http://qcdloop.fnal.gov/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qcdloop.fnal.gov/
COMMENT=	Repository of one-loop scalar Feynman integrals

USE_LANGUAGES=	fortran

MAKE_FILE=	makefile

INSTALLATION_DIRS=	lib share/doc/qcdloop

do-install:
	${INSTALL_LIB} ${WRKSRC}/ff/libff.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/ql/libqcdloop.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Doc/man.ps ${DESTDIR}${PREFIX}/share/doc/qcdloop

.include "../../mk/bsd.pkg.mk"
