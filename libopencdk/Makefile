# $NetBSD: Makefile,v 1.2 2003/05/14 01:57:45 lsed Exp $
#

DISTNAME=	opencdk-0.4.5
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/opencdk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Library that handles and understands OpenPGP packets

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_PERL5=	build

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
REPLACE_PERL=		doc/gdoc

DOCDIR=		${PREFIX}/share/doc/libopencdk
EGDIR=		${PREFIX}/share/examples/libopencdk
HTMLDIR=	${PREFIX}/share/doc/html/libopencdk

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${EGDIR}

.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
