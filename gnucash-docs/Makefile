# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:12 marttikuparinen Exp $

DISTNAME=	gnucash-docs-1.8.1
CATEGORIES=	finance
MASTER_SITES=	ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnucash.org/
COMMENT=	Help documentation and tutorial guide for gnucash

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	# defined

post-build:
	cd ${WRKSRC}/help/C && ${MAKE} convert-html ;
	cd ${WRKSRC}/help/de_DE && ${MAKE} convert-html ;
	cd ${WRKSRC}/guide/C && ${MAKE} convert-html

.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../databases/db3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
