# $NetBSD: Makefile,v 1.5 2014/07/19 14:26:33 thomasklausner Exp $

DISTNAME=	Catalyst-Model-LDAP-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-LDAP/
COMMENT=	Net::LDAP model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-perl-ldap>=0.34:../../databases/p5-perl-ldap
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=	p5-Data-Page-[0-9]*:../../devel/p5-Data-Page
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=	auto/Catalyst/Model/LDAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
