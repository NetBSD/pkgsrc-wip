# $NetBSD: Makefile,v 1.2 2003/08/22 11:20:28 tvierling Exp $
#

DISTNAME=		pgpenvelope-2.10.2
PKGREVISION=		1
CATEGORIES=		security mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pgpenvelope/}

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://pgpenvelope.sourceforge.net/
COMMENT=		GnuPG and Pine/Procmail integration tool

DEPENDS+=		p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=		p5-Class-MethodMaker>=0.96:../../wip/p5-Class-MethodMaker
DEPENDS+=		p5-GnuPG-Interface>=0.34nb1:../../wip/p5-GnuPG-Interface
DEPENDS+=		p5-String-Approx>=3.13:../../wip/p5-String-Approx
DEPENDS+=		p5-Term-ReadKey>=2.14:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Term-ReadLine>=1.01:../../devel/p5-Term-ReadLine

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/pgpenvelope/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
