# $NetBSD: Makefile,v 1.1.1.1 2003/05/13 02:33:09 xtraeme Exp $
#

DISTNAME=	gnutls-0.8.7
CATEGORIES=	devel security
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gnutls/
COMMENT=	Portable ANSI C library which implements the TLS 1.0 and SSL 3

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	run

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

REPLACE_PERL=	${WRKSRC}/doc/scripts/sort1.pl

PSDOCS=		*.ps *.tex *.eps
EXAMPLES= 	*.c

pre-install:

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnutls
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnutls
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${PREFIX}/share/doc/gnutls
	( cd ${WRKSRC}/doc/tex	&&	\
	for f in ${PSDOCS};	do	\
		${INSTALL_DATA} $$f ${PREFIX}/share/doc/gnutls/; \
	done )
	( cd ${WRKSRC}/doc/examples	&&	\
	for f in ${EXAMPLES}; do	\
		${INSTALL_DATA}	$$f ${PREFIX}/share/examples/gnutls/; \
	done )

.include "../../wip/libopencdk/buildlink2.mk"
.include "../../wip/libtasn1/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
