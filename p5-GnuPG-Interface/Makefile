# $NetBSD: Makefile,v 1.2 2003/08/15 19:25:23 tvierling Exp $
#

DISTNAME=		GnuPG-Interface-0.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnupg-interface/}

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://gnupg-interface.sourceforge.net/
COMMENT=		Perl interface to GnuPG

DEPENDS+=		p5-Class-MethodMaker>=1.00:../../wip/p5-Class-MethodMaker
DEPENDS+=		gnupg>=1.1.0:../../security/gnupg

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GnuPG/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
