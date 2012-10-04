# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:32 asau Exp $
#

DISTNAME=	Class-DBI-Plugin-RetrieveAll-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdr
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Plugin-RetrieveAll/
COMMENT=	More complex retrieve_all() for Class::DBI

DEPENDS+=	p5-Class-DBI>=0.95:../../databases/p5-Class-DBI

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Class/DBI/Plugin/RetrieveAll/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
