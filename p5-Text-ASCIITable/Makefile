# $NetBSD: Makefile,v 1.3 2011/10/15 15:49:12 jgoamakf Exp $

DISTNAME=		Text-ASCIITable-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tat
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-ASCIITable/
COMMENT=		Create a nice formatted table using ASCII characters
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/ASCIITable/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
