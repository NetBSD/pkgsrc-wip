# $NetBSD: Makefile,v 1.8 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=	common-1.2.18r4122
PKGNAME=	common-mml-1.2.18
CATEGORIES=	mbone audio multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/
COMMENT=	Common multimedia library required by mbone tools

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include/common-mml lib share/doc/common-mml

INCDIR=		${PREFIX}/include/common-mml
DOCDIR=		${PREFIX}/share/doc/common-mml

do-install:
	${LIBTOOL} --mode=install \
		${INSTALL_LIB} ${WRKSRC}/src/*.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
