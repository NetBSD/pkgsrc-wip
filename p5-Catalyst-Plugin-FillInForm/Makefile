# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:29 asau Exp $

DISTNAME=	Catalyst-Plugin-FillInForm-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-FillInForm/
COMMENT=	Automatically fill in forms in Catalyst using HTML::FillInForms
PERL5_REQD+=	5.8

DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Action-RenderView-[0-9]*:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-HTML-FillInForm>=0:../../www/p5-HTML-FillInForm
DEPENDS+=	p5-NEXT>=0:../../devel/p5-NEXT
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Plugin/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
