# $NetBSD: Makefile,v 1.5 2012/10/04 09:13:29 asau Exp $

DISTNAME=	Catalyst-Plugin-FormValidator-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-FormValidator/
COMMENT=	FormValidator for Catalyst

PERL5_REQD+=	5.6.3

DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Data-FormValidator>=0:../../textproc/p5-Data-FormValidator


PERL5_PACKLIST= auto/Catalyst/Plugin/FormValidator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
