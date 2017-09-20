# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=		Petal-2.24
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NI/NINE/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Petal/
COMMENT=		Perl Template Attribute Language
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-MKDoc-XML>=0.75:../../wip/p5-MKDoc-XML

EXTRACT_USING=		bsdtar
PERL5_PACKLIST=		auto/Petal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
