# $NetBSD: Makefile,v 1.6 2004/03/29 18:47:24 tvierling Exp $
#

DISTNAME=		GnuPG-Interface-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnupg-interface/}

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://gnupg-interface.sourceforge.net/
COMMENT=		Perl interface to GnuPG

DEPENDS+=		p5-Class-MethodMaker>=1.00:../../devel/p5-Class-MethodMaker
DEPENDS+=		gnupg>=1.2.3:../../security/gnupg

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GnuPG/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
