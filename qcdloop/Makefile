# $NetBSD: Makefile,v 1.1 2012/09/03 23:03:22 jihbed Exp $
#

DISTNAME=	QCDLoop-1.9
PKGNAME=	qcdloop-1.9
CATEGORIES=	math
MASTER_SITES=	http://qcdloop.fnal.gov/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://qcdloop.fnal.gov/
COMMENT=	Repository of one-loop scalar Feynman integrals

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	fortran

MAKE_FILE=	makefile

INSTALLATION_DIRS=	lib share/doc/qcdloop

do-install:
	${INSTALL_LIB} ${WRKSRC}/ff/libff.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/ql/libqcdloop.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Doc/man.ps ${DESTDIR}${PREFIX}/share/doc/qcdloop

.include "../../mk/bsd.pkg.mk"
