# $NetBSD: Makefile,v 1.1.1.1 2004/08/25 20:09:57 lexort Exp $

DISTNAME=	IO-Multiplex-1.08
PKGNAME=	p5-IO-Multiplex-1.08
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://search.cpan.org/dist/IO-Multiplex/
COMMENT=	Front end to select loop for perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
