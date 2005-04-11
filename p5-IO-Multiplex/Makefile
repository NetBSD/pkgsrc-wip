# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:39 tvierling Exp $

DISTNAME=	IO-Multiplex-1.08
PKGNAME=	p5-IO-Multiplex-1.08
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://search.cpan.org/dist/IO-Multiplex/
COMMENT=	Front end to select loop for perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews


PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Multiplex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
