# $NetBSD: Makefile,v 1.2 2007/01/13 21:25:15 absd Exp $

DISTNAME=	podlators-2.00
PKGREVISION=	1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/podlators/
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

DEPENDS+=	p5-Pod-Simple>=3.03:../../textproc/p5-Pod-Simple

PERL5_PACKLIST= auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
