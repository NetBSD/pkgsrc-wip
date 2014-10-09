# $NetBSD: Makefile,v 1.6 2014/10/09 13:45:24 thomasklausner Exp $
#

DISTNAME=	Data-Properties-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Data-Properties/
COMMENT=	Perl version of Java's java.util.Properties

PKG_DESTDIR_SUPPORT=	none
PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Properties/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
