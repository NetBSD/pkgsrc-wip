# $NetBSD: Makefile,v 1.2 2004/04/14 21:39:59 poppnk Exp $
#

DISTNAME=		minimalist-2.4
CATEGORIES=		wip mail
MASTER_SITES=	http://www.mml.org.ua/LIST/
EXTRACT_SUFX=	.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.mml.org.ua/LIST/
COMMENT=		Minimalistic Mailing Lists Manager

USE_BUILDLINK3= YES
USE_PERL5=		YES
REPLACE_PERL=	${WRKSRC}/minimalist.pl
REPLACE_PERL+=	${WRKSRC}/contrib/minimalist_request.pl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl \
			${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/minimalist_request.pl \
			${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
