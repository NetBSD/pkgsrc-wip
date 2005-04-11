# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:37 tvierling Exp $
#

DISTNAME=	Data-Properties-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dpr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Data-Properties
COMMENT=	Perl version of Java's java.util.Properties

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=          # empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Properties/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
