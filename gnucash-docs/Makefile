# $NetBSD: Makefile,v 1.4 2004/04/27 01:21:19 thomasklausner Exp $

DISTNAME=	gnucash-docs-1.8.1
CATEGORIES=	finance
MASTER_SITES=	ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnucash.org/
COMMENT=	Help documentation and tutorial guide for gnucash

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_PERL5=	# defined

post-build:
	cd ${WRKSRC}/help/C && ${MAKE} convert-html ;
	cd ${WRKSRC}/help/de_DE && ${MAKE} convert-html ;
	cd ${WRKSRC}/guide/C && ${MAKE} convert-html

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bdb.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
