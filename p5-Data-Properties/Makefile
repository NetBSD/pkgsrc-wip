# $NetBSD: Makefile,v 1.1.1.1 2004/05/10 14:39:19 jgoamakf Exp $
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

USE_BUILDLINK3=         YES
USE_LANGUAGES=          # empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Properties/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
