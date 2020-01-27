# $NetBSD: Makefile,v 1.3 2013/12/03 17:02:35 jihbed Exp $

DISTNAME=	QCDLoop-1.95
PKGNAME=	qcdloop-1.95
CATEGORIES=	math
MASTER_SITES=	http://qcdloop.fnal.gov/
MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://qcdloop.fnal.gov/
COMMENT=	Repository of one-loop scalar Feynman integrals
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_FILE=	makefile

USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	lib share/doc/qcdloop

do-install:
	${INSTALL_LIB} ${WRKSRC}/ff/libff.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/ql/libqcdloop.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Doc/man.ps ${DESTDIR}${PREFIX}/share/doc/qcdloop

.include "../../mk/bsd.pkg.mk"
