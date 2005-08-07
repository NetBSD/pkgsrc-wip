# $NetBSD: Makefile,v 1.1.1.1 2005/08/07 19:40:10 jgoamakf Exp $
#

DISTNAME=	Class-DBI-AsForm-2.41
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cda
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-AsForm/
COMMENT=	Produce HTML form elements for database columns

DEPENDS+=	p5-DBI>=1.30:../../databases/p5-DBI
DEPENDS+=	p5-Class-DBI>=0.89:../../databases/p5-Class-DBI
DEPENDS+=	p5-Class-DBI-Plugin-Type>=1.88:../../wip/p5-Class-DBI-Plugin-Type
DEPENDS+=	p5-HTML-Tree>=1.88:../../www/p5-HTML-Tree

PERL5_PACKLIST=	auto/Class/DBI/AsForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
