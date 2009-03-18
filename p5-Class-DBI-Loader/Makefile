# $NetBSD: Makefile,v 1.2 2009/03/18 12:05:33 cheusov Exp $
#

DISTNAME=	Class-DBI-Loader-0.22
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Loader/
COMMENT=	Dynamic definition of Class::DBI sub classes

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBI>=1.30:../../databases/p5-DBI
DEPENDS+=	p5-Class-DBI>=0.89:../../databases/p5-Class-DBI
DEPENDS+=	p5-Lingua-EN-Inflect>=1.88:../../textproc/p5-Lingua-EN-Inflect

PERL5_PACKLIST=	auto/Class/DBI/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
