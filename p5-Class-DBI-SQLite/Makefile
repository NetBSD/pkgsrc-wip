# $NetBSD: Makefile,v 1.2 2005/09/02 18:13:55 kuli0020 Exp $

DISTNAME=	Class-DBI-SQLite-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-SQLite/
COMMENT=	Extension to Class::DBI for sqlite

DEPENDS+=	p5-Class-DBI>=0.85:../../databases/p5-Class-DBI
DEPENDS+=	p5-Ima-DBI>=0.27:../../databases/p5-Ima-DBI
DEPENDS+=	p5-DBD-SQLite>=0.07:../../databases/p5-DBD-SQLite
DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Class/DBI/SQLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
