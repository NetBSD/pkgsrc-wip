# $NetBSD: Makefile,v 1.1.1.1 2004/01/11 22:00:14 poppnk Exp $
#

DISTNAME=		minimalist-2.4
CATEGORIES=		wip mail
MASTER_SITES=		http://www.mml.org.ua/LIST/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.mml.org.ua/LIST/
COMMENT=		Minimalistic Mailing Lists Manager

USE_BUILDLINK2=		yes
USE_PERL5=		yes
REPLACE_PERL=		${WRKSRC}/minimalist.pl
REPLACE_PERL+=		${WRKSRC}/contrib/minimalist_request.pl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl \
			${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/minimalist_request.pl \
			${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
