# $NetBSD: Makefile,v 1.1.1.1 2003/05/13 02:29:35 xtraeme Exp $
#

DISTNAME=	opencdk-0.4.5
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/opencdk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gnutls/
COMMENT=	Library that handles and understands OpenPGP packets

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

HTMLDIR=	${PREFIX}/share/doc/html/libopencdk
DOCDIR=		${PREFIX}/share/doc/libopencdk
EXAMPLESDIR=	${PREFIX}/share/examples/libopencdk

TESTFILES=      *.gpg *.c

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS ${DOCDIR}
	( cd ${WRKSRC}/tests	&&      \
       	for file in ${TESTFILES};	do	\
		${INSTALL_DATA} $$file  ${EXAMPLESDIR}; \
	done )

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
