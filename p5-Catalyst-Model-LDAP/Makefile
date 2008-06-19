# $NetBSD: Makefile,v 1.1 2008/06/19 21:35:07 tonnerre Exp $

DISTNAME=	Catalyst-Model-LDAP-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-LDAP/
COMMENT=	Net::LDAP model class for Catalyst

DEPENDS+=	p5-Catalyst>=5.00:../../wip/p5-Catalyst
DEPENDS+=	p5-perl-ldap>=0.34:../../databases/p5-perl-ldap
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-C3>=0:../../wip/p5-Class-C3

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/Catalyst/Model/LDAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
