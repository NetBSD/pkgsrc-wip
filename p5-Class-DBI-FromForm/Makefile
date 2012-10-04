# $NetBSD: Makefile,v 1.2 2012/10/04 09:13:32 asau Exp $
#

DISTNAME=	Class-DBI-FromForm-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdl
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-FromForm/
COMMENT=	Update Class::DBI data using Data::FormValidator

DEPENDS+=	p5-Class-DBI>=0.89:../../databases/p5-Class-DBI
DEPENDS+=	p5-Data-FormValidator>=3.63:../../textproc/p5-Data-FormValidator

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Class/DBI/FromForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
