# $NetBSD: Makefile,v 1.1.1.1 2005/06/09 12:34:51 obache Exp $
#

DISTNAME=	${PKGNAME:C|-.*||}
PKGNAME=	topless-1.36
CATEGORIES=	sysutils
MASTER_SITES=	http://people.freebsd.org/~daichi/src/
EXTRACT_SUFX=	#defined

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.ongs.net/~daichi/#topless
COMMENT=	Display and update information of target command like 'top'

NO_CONFIGURE=	YES
NO_BUILD=	YES

do-extract:
do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTFILES} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
