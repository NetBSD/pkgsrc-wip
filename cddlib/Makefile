# $NetBSD: Makefile,v 1.3 2015/01/31 20:03:00 jihbed Exp $

DISTNAME=	cddlib-094g
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.ethz.ch/users/fukudak/cdd/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://www.inf.ethz.ch/personal/fukudak/cdd_home/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	share/doc/cddlib

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cddlib
	${INSTALL_DATA} ${WRKSRC}/doc/cddlibman.pdf \
		${DESTDIR}${PREFIX}/share/doc/cddlib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
