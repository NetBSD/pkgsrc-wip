# $NetBSD: Makefile,v 1.2 2004/03/04 23:11:19 minskim Exp $
#

DISTNAME=		Regexp-Common-2.113
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Provide commonly requested regular expressions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
