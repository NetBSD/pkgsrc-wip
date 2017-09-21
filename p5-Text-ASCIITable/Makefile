# $NetBSD: Makefile,v 1.5 2013/04/18 10:49:54 jgoamakf Exp $

DISTNAME=		Text-ASCIITable-0.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-ASCIITable/
COMMENT=		Create a nice formatted table using ASCII characters
LICENSE=		${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/ASCIITable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
