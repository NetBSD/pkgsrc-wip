# $NetBSD: Makefile,v 1.2 2008/10/20 10:10:18 tonnerre Exp $

DISTNAME=	Catalyst-Model-LDAP-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-LDAP/
COMMENT=	Net::LDAP model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-perl-ldap>=0.34:../../databases/p5-perl-ldap
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Model/LDAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
