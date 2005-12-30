# $NetBSD: Makefile,v 1.1.1.1 2005/12/30 16:35:58 kuli0020 Exp $

DISTNAME=	podlators-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/podlators/
COMMENT=	Modules to convert and parse POD (Plain Old Documentation)

DEPENDS+=	p5-Pod-Simple>=3.03:../../textproc/p5-Pod-Simple
DEPENDS+=	{perl>=5.0.5,p5-File-Spec>=0.8}:../../devel/p5-File-Spec

PERL5_PACKLIST= auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
