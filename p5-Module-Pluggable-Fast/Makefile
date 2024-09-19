# $NetBSD: Makefile,v 1.8 2014/10/09 13:45:24 thomasklausner Exp $

DISTNAME=	Module-Pluggable-Fast-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Module-Pluggable-Fast
COMMENT=	Fast plugins with instantiation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=	auto/Module/Pluggable/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
