# $NetBSD: Makefile,v 1.7 2013/04/06 02:26:04 jgoamakf Exp $

DISTNAME=	Module-Pluggable-Fast-0.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mpf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable-Fast/
COMMENT=	Fast plugins with instantiation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=	auto/Module/Pluggable/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
