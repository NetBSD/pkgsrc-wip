# $NetBSD: Makefile,v 1.4 2004/05/11 07:55:48 cubidou Exp $

DISTNAME=	DateTime-Event-Cron-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Event-Cron/
COMMENT=	DateTime extension to handle crontab entries

DEPENDS+=	p5-DateTime-Set-[0-9]*:../../wip/p5-DateTime-Set
DEPENDS+=	p5-Set-Crontab-[0-9]*:../../wip/p5-Set-Crontab

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/Event/Cron/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
