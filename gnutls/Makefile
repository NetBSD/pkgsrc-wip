# $NetBSD: Makefile,v 1.2 2003/05/14 03:00:16 lsed Exp $
#

DISTNAME=	gnutls-0.8.7
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Portable ANSI C library which implements the TLS 1.0 and SSL 3

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_PERL5=	run

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

REPLACE_PERL=	${WRKSRC}/doc/scripts/sort1.pl

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCDIR}
	cd ${WRKSRC}/doc/tex && ${INSTALL_DATA} *.ps *.tex *.eps ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${EGDIR}

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../wip/libopencdk/buildlink2.mk"
.include "../../wip/libtasn1/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
